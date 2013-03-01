#include "typedef.h"
#include "grid2.h"
#include "vector.h"

#ifndef X_UTIL_H
#define X_UTIL_H
namespace X {
    namespace GridTool{
        template <typename T, x_size P1, x_size P2>
            void setMeshgrid2(Grid2<T,P1,P2>& grid, Vector<T,P1>& x, Vector<T,P2>& y);
  
        template <typename T, x_size N>
            void linspace(Vector<T,N>& , T, T);

        template <typename T, x_size N>
            void linspace2(Vector<T,N>&, T, T);
    }
}

#include "util.cpp"

#endif
