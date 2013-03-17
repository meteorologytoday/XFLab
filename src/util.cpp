
#ifdef X_UTIL_H
#ifndef X_UTIL_CPP
#define X_UTIL_CPP

#include <iostream>
using namespace std;

namespace X {
    namespace Util {

        template <typename T, xsize N1, xsize N2>
            void set2DMeshgrid(Index2<T,N1,N2>& gridx, Index2<T,N1,N2>& gridy, Index1<T,N1>& x, Index1<T,N2>& y) {
                for(xsize i=0; i < N1; ++i) {
                    for(xsize j=0; j < N2; ++j) {
                        gridx(i,j) = x(i);
                        gridy(i,j) = y(j);
                    }
                }
            }

        template <typename T, xsize N>
            void linspace(Index1<T,N>& vec, T start, T end) {
                for(xsize i=0; i < N; ++i) {
                    vec(i) = start + (end - start) / (N-1) * i;
                }
            }


        template <typename T, xsize N>
            void linspace2(Index1<T,N>& vec, T start, T end) {
                for(xsize i=0; i < N; ++i) {
                    vec(i) = start + (end - start) / N * i;
                }
            }
    }
}

#endif
#endif
