
#ifdef X_UTIL_H
#ifndef X_UTIL_CPP
#define X_UTIL_CPP

#include <iostream>
using namespace std;

namespace X {
    namespace Util {

        template <typename T, xsize N1, xsize N2>
            void ddMeshgrid(Index2<T,N1,N2>& gridx, Index2<T,N1,N2>& gridy, Index1<T,N1>& x, Index1<T,N2>& y) {
                for(xsize i=0; i < N1; ++i) {
                    for(xsize j=0; j < N2; ++j) {
                        gridx(i,j) = x(i);
                        gridy(i,j) = y(j);
                    }
                }
            }

        template <typename T, xsize N>
            void dLinspace1(Index1<T,N>& vec, T start, T end) {
                for(xsize i=0; i < N; ++i) {
                    vec(i) = start + (end - start) / (N-1) * i;
                }
            }


        template <typename T, xsize N>
            void dLinspace2(Index1<T,N>& vec, T start, T end) {
                for(xsize i=0; i < N; ++i) {
                    vec(i) = start + (end - start) / N * i;
                }
            }

 
        template <typename T, xsize N1, xsize N2>
            void ddLaplacianNeumann1(Index2<T,N1,N2>& in, Index2<T,N1,N2>& out, Index2<T, N1, N2>& bc_dx, Index2<T, N1, N2>& bc_dy, T dx, T dy) {
                for(xsize i=0; i < N1; ++i) {
                    for(xsize j=0; j < N2; ++j) {
                        if(i==0) {
                            out(0,j) = ((in(1,j) - in(0,j))/dx - bc_dx(0,j)) / (dx/2);
                        } else if(i == N1-1) {
                            out(N1-1,j) = ( bc_dx(N1-1,j) - (in(N1-1,j) - in(N1-2,j))/dx )/(dx/2);
                        } else {
                            out(i,j) = (in(i+1,j) + in(i-1,j) - 2*in(i,j))/(dx*dx);
                        }

                        if(j==0) {
                            out(i,0) += ((in(i,1) - in(i,0))/dy - bc_dy(i,0)) / (dy/2);
                        } else if(j == N2-1) {
                            out(i,N2-1) += ( bc_dy(i,N2-1) - (in(i,N2-1) - in(i,N2-2))/dy )/(dy/2);
                        } else {
                            out(i,j) += (in(i,j+1) + in(i,j-1) - 2*in(i,j))/(dy*dy);
                        }

                    }
                }


        }


        // interpolation
        template <typename T, xsize N1, xsize N2, xsize N3, xsize N4>
            void ddInterp1(Index2<T,N1,N2>& in, Index1<T,N1>& ix, Index1<T,N2>& iy, Index2<T,N3,N4>& out, Index1<T,N3>& ox, Index1<T,N4>& oy) {
               if (N1 > N3 || N2 > N4) { throw; } 
                DataIndex2<xsize[2], N3, N4> region;
                bool ok = false;

                // first, determined the region the points belong to
                for(xsize i=0; i < N3; ++i) {
                    for(xsize j=0; j < N4; ++j) {

                        ok = false;

                        for(xsize k=0; k < N1-1; ++k) { 
                            if(ok == false && ox(i) >= ix(k) && ox(i) <= ix(k+1)) { // locate x region
                                for(xsize l=0; l < N2-1; ++l) {
                                    if(oy(j) >= iy(l) && oy(j) <= iy(l+1)) { // locate y region
                                        region(i,j)[0] = k; 
                                        region(i,j)[1] = l; 
                                        ok = true;
                                        break;
                                    }
                                }
                            }


                        }

                    }
                }
                
               xsize k,l;
                T a,b,c,d;
                T A, Aa, Ab, Ac, Ad;
                // do linear interpolation
                for(xsize i=0; i < N3; ++i) {
                    for(xsize j=0; j < N4; ++j) {
                        k = region(i,j)[0];
                        l = region(i,j)[1];
                        a = in(k,l);
                        b = in(k+1,l);
                        c = in(k+1,l+1);
                        d = in(k,l+1);
                        
                        A  = (ix(k+1)-ix(k)) * (iy(l+1)-iy(l));
                        Aa = (ox(i)-ix(k)) * (oy(j)-iy(l));
                        Ab = (ix(k+1)-ox(i)) * (oy(j)-iy(l));
                        Ac = (ix(k+1)-ox(i)) * (iy(l+1)-oy(j));
                        Ad = (ox(i)-ix(k)) * (iy(l+1)-oy(j));


                        out(i,j) = (a*Ac + b*Ad + c*Aa + d*Ab) / A;
                    }
                }

            }


    }
}

#endif
#endif
