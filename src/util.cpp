
#ifdef X_UTIL_H
#ifndef X_UTIL_CPP
#define X_UTIL_CPP

#include <iostream>
using namespace std;

namespace X {
    namespace Util {

        template <typename T, xsize P1, xsize P2>
            void set2DMeshgrid(Matrix<T,2,P1*P2>& grid, Vector<T,P1>& x, Vector<T,P2>& y) {
                for(xsize i=0; i < P1; ++i) {
                    for(xsize j=0; j < P2; ++j) {
                        grid(0,OFFSET2(P1,P2,i,j)) = x(i);
                        grid(1,OFFSET2(P1,P2,i,j)) = y(j);
                    }
                }
            }

        template <typename T, xsize P, xsize N>
            void distance(Field2D<T,P,N>& f, T centX, T centY, xsize where) {
                Matrix<T,2,P> *grid = f.getGrid();
                for(xsize i=0; i < P; ++i) {
                    f(where,i) = sqrt(pow((*grid)(0,i) - centX, 2) + pow((*grid)(1,i) - centY, 2));
                }
            }


        template <typename T, xsize N>
            void linspace(Vector<T,N>& vec, T start, T end) {
                for(xsize i=0; i < N; ++i) {
                    vec(i) = start + (end - start) / (N-1) * i;
                }
            }


        template <typename T, xsize N>
            void linspace2(Vector<T,N>& vec, T start, T end) {
                for(xsize i=0; i < N; ++i) {
                    vec(i) = start + (end - start) / N * i;
                }
            }



    }
}

#endif
#endif
