#include "typedef.h"
#include "index_1.h"
#include "index_2.h"
#include <cmath>

#ifndef X_UTIL_H
#define X_UTIL_H
namespace X {
    namespace Util{
        template <typename T, xsize N1, xsize N2>
            void set2DMeshgrid(Index2<T,N1,N2>& gridx, Index2<T,N1,N2>& gridy, Index1<T,N1>& x, Index1<T,N2>& y);
  
        template <typename T, xsize N>
            void linspace(Index1<T,N>&, T, T);

        template <typename T, xsize N>
            void linspace2(Index1<T,N>&, T, T);
    }
}

#include "util.cpp"

#endif
