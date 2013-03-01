
#ifdef X_UTIL_H
#ifndef X_UTIL_CPP
#define X_UTIL_CPP
#include <iostream>
using namespace std;
namespace X {
    namespace Util {

        template <typename T, x_size P1, x_size P2>
            void setMeshgrid2(Grid2<T, P1, P2>& grid, Vector<T,P1>& x, Vector<T,P2>& y) {
                for(x_size i=0; i < P1; ++i) {
                    for(x_size j=0; j < P2; ++j) {
                        grid(0,i,j) = x(i);
                        grid(1,i,j) = y(j);
                    }
                }
            }

        template <typename T, x_size N>
            void linspace(Vector<T,N>& vec, T start, T end) {
                for(x_size i=0; i < N; ++i) {
                    vec(i) = start + (end - start) / (N-1) * i;
                }
            }


        template <typename T, x_size N>
            void linspace2(Vector<T,N>& vec, T start, T end) {
                for(x_size i=0; i < N; ++i) {
                    vec(i) = start + (end - start) / N * i;
                }
            }



    }
}

#endif
#endif
