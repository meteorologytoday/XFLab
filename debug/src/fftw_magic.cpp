
#ifdef X_FFTW_MAGIC_H
#ifndef X_FFTW_MAGIC_CPP
#define X_FFTW_MAGIC_CPP


#define _USE_MATH_DEFINES
#include <cmath>

#define M_PII (2*M_PI)
#define ccmul(z,x,y) (z)[0] = (x)[0] * (y)[0] - (x)[1] * (y)[1]; (z)[1] = (x)[0] * (y)[1] + (x)[1] * (y)[0];
#define rcmul(z,r,c) (z)[0] = r * (c)[0]; (z)[1] = r * (c)[1];

#include <iostream>
using namespace std;
namespace X {
    namespace FFTW {

        void* fftw_malloc_wave_table2(x_size D0, x_size D1) {
            return  FFTW(malloc)(sizeof(FFTW_COMPLEX) * D0 * ((x_size) (D1/2)+1));
        }


        // for even , kreal = -Nx/2 + (k - Nx/2) = -Nx + k 
        // for odd  , kreal = -(Nx-1)/2 + k - ((Nx-1)/2 + 1) = -Nx + k
        inline FFTW_REAL mapWavenumber(x_size dim, x_size i) {
            //            cout << "i : " << i << ", (x_size)(dim/2) = " << (x_size)(dim/2) << "  " ;
            //            cout << ((i <= (x_size)(dim/2)) ? static_cast<FFTW_REAL>(i) : static_cast<FFTW_REAL>(i) - dim) << endl;
            return (i <= (x_size)(dim/2)) ? static_cast<FFTW_REAL>(i) : static_cast<FFTW_REAL>(i) - dim ;
        }

        template <typename T>
            void diff2(x_size dir, int order,FFTW_COMPLEX *in, FFTW_COMPLEX *out, x_size D0, x_size D1, T L0, T L1) {
                FFTW_REAL factor = 0;
                x_size offset = 0;
                int oddity = order%4;
                FFTW_REAL k,l;
                FFTW_COMPLEX complex_indicator = {1,0};
                D1 = (x_size)(D1/2+1);
                switch(oddity) {
                    case 0:
                        complex_indicator[0] = 1;
                        complex_indicator[1] = 0;
                        break;
                    case 1:
                        complex_indicator[0] = 0;
                        complex_indicator[1] = 1;
                        break;
                    case 2:
                        complex_indicator[0] = -1;
                        complex_indicator[1] = 0;
                        break;
                    case 3:
                        complex_indicator[0] = 0;
                        complex_indicator[1] = -1;
                        break;
                }
                if(dir == 0) { // dimension 0

                    for(x_size i = 0; i < D0 ; ++i) {
                        factor = pow(((M_PII * mapWavenumber(D0,i)) / L0) , static_cast<FFTW_REAL>(order));
                        for(x_size j = 0; j < D1; ++j) {

                            offset = OFFSET2(D0,D1,i,j);
                            ccmul(out[offset], in[offset], complex_indicator);
                            rcmul(out[offset], factor, out[offset]);
                        }
                    }


                } else if(dir == 1) { // dimension 1
                    for(x_size i = 0; i < D0 ; ++i) {
                        for(x_size j = 0; j < D1; ++j) {
                            factor = pow(((M_PII * mapWavenumber(D1,j)) / L1) , static_cast<FFTW_REAL>(order));
                            offset = OFFSET2(D0,D1,i,j);
                            ccmul(out[offset], in[offset], complex_indicator);
                            rcmul(out[offset], factor, out[offset]);
                        }
                    }


                } else {
                    // error
                    throw 1;
                }

            }

        template <typename T>
            void ipoisson(FFTW_COMPLEX *in, FFTW_COMPLEX *out, x_size D0, x_size D1, T L0, T L1) {
                FFTW_REAL factor = 0;
                FFTW_REAL wavenumber_k = 0, wavenumber_l = 0;
                
                x_size offset = 0;
                FFTW_REAL k,l;
                D1 = (x_size)(D1/2+1);

                for(x_size i = 0; i < D0 ; ++i) {
                    for(x_size j = 0; j < D1; ++j) {
                        factor = 0;
                        offset = OFFSET2(D0,D1,i,j);
                        wavenumber_k = mapWavenumber(D0,i);
                        wavenumber_l = mapWavenumber(D1,j);
                        
                        if(wavenumber_k == 0 && wavenumber_l == 0) {
                            out[offset][0] = 0;
                            out[offset][1] = 0;
                            continue;
                        
                        } else {
                            factor =  - (pow(M_PII * wavenumber_k / L0, 2) + pow(M_PII * wavenumber_l / L1, 2));
                        }

                        rcmul(out[offset], 1 / factor, in[offset]);
                    }
                }


            }

        template <typename T>
            void laplacian(FFTW_COMPLEX *in, FFTW_COMPLEX *out, x_size D0, x_size D1, T L0, T L1) {
                FFTW_REAL factor = 0;
                FFTW_REAL wavenumber_k = 0, wavenumber_l = 0;
                
                x_size offset = 0;
                FFTW_REAL k,l;
                D1 = (x_size)(D1/2+1);

                for(x_size i = 0; i < D0 ; ++i) {
                    for(x_size j = 0; j < D1; ++j) {
                        factor = 0;
                        offset = OFFSET2(D0,D1,i,j);
                        wavenumber_k = mapWavenumber(D0,i);
                        wavenumber_l = mapWavenumber(D1,j);
                        
                        factor =  - (pow(M_PII * wavenumber_k / L0, 2) + pow(M_PII * wavenumber_l / L1, 2));

                        rcmul(out[offset], factor, in[offset]);
                    }
                }


            }



    }
}
#undef PI
#undef cplx_mul(z,x,y)

#endif
#endif
