#ifdef X_DD_SPHERICAL_H_X

#ifndef X_DD_SPHERICAL_CPP_X
#define X_DD_SPHERICAL_CPP_X

namespace X {

    namespace DDSPHERICAL {
        template <typename T, xsize N1, xsize N2>
            ddSphericalDescriptor<T,N1,N2>::ddSphericalDescriptor(T r) {
                if(N1 % 4 != 0) { X::XError::err("Points on phi direction must be 4 mutiple."); }
                this->r = r;

                setup();
            }

        template <typename T, xsize N1, xsize N2>
            void ddSphericalDescriptor<T,N1,N2>::setup() {

                T dtheta = M_PI / (N2-1);
                T dphi   = 2*M_PI / N1;

                for(xsize i=0; i < N1; ++i) {
                    phi(i) = i * dphi;
                }

                for(xsize j=0; j < N2; ++j) {
                    theta(j) = j * dtheta;
                }

                for(xsize j=0; j < N2; ++j) {
                    dx(j) = r * sin(theta(j)) * dphi;
                }

                dy = r * dtheta;
            }

        // ddSphericalTool
        template <typename T, xsize N1, xsize N2>
            void ddSphericalTool<T,N1,N2>::gradient_xy(ddSphericalDescriptor<T,N1,N2>& desc, DataIndex2<T,N1,N2>& in, DataIndex2<T,N1,N2>& out_x, DataIndex2<T,N1,N2>& out_y) {
                
                // x direction
                for(xsize i=1;i<N1-1;++i) {
                    for(xsize j=1;j<N2-1;++j) {
                        out_x(i,j) = (in(i+1,j) - in(i-1,j)) / (2 * desc.dx(j));
                    }
                }

                for(xsize j=1;j<N2-1;++j) {
                    out_x(0,j) = (in(1,j) - in(N1-1,j)) / (2 * desc.dx(j));
                    out_x(N1-1,j) = (in(0,j) - in(N1-2,j)) / (2 * desc.dx(j));
                }

                // y direction
                for(xsize i=1;i<N1;++i) {
                    for(xsize j=1;j<N2-1;++j) {
                        out_y(i,j) = - (in(i,j+1) - in(i,j-1)) / (2 * desc.dy); // negative because y direction is oppisite to theta direction
                    }
                }

                // north pole point, treat phi=0 toward equator as +x axis, phi=90 toward equator as +y axis
                T dfdx_n = (in(0,1) - in(N1/2,1)) / (2 * desc.dy);
                T dfdy_n = (in(N1/4,1) - in(N1*3/4,1)) / (2 * desc.dy);
                T df_n = sqrt(pow(dfdx_n,2) + pow(dfdy_n,2));

                // south pole point, treat phi=0 toward equator as +x axis, phi=90 toward equator as +y axis,
                // which is mirror image from odinary xy coordinate
                T dfdx_s = (in(0,N2-2) - in(N1/2,N2-2)) / (2 * desc.dy);
                T dfdy_s = (in(N1/4,N2-2) - in(N1*3/4,N2-2)) / (2 * desc.dy);
                T df_s = sqrt(pow(dfdx_s,2) + pow(dfdy_s,2));
               
                cout << "dfdx_n = " << dfdx_n << ", "; 
                cout << "dfdy_n = " << dfdy_n << ", "; 
                cout << "df_n = " << df_n << endl; 

                T cos_n = dfdx_n / df_n;
                T sin_n = dfdy_n / df_n;
                T cos_s = dfdx_s / df_s;
                T sin_s = dfdx_s / df_s;
                // assign to each point
                for(xsize i = 0 ; i < N1 ; ++i) {
                    T sin_phi = sin(desc.phi(i));
                    T cos_phi = cos(desc.phi(i));
                    
                    out_x(i,0) =   cos_phi * sin_n - sin_phi * cos_n;
                    out_y(i,0) = - cos_phi * cos_n - sin_phi * sin_n;

                    out_x(i,N2-1) = cos_phi * sin_s - sin_phi * cos_s;
                    out_y(i,N2-1) = cos_phi * cos_s + sin_phi * sin_s;
                }
 
            
            }
        template <typename T, xsize N1, xsize N2>
            void ddSphericalTool<T,N1,N2>::laplacian(ddSphericalDescriptor<T,N1,N2>& desc, DataIndex2<T,N1,N2>& in, DataIndex2<T,N1,N2>& out) {
            }

    };
}


#endif
#endif
