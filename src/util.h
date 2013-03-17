#include "typedef.h"
#include "field2d.h"
#include "vector.h"
#include <cmath>

#ifndef X_UTIL_H
#define X_UTIL_H
namespace X {
    namespace Util{
        template <typename T, xsize P1, xsize P2>
            void set2DMeshgrid(Matrix<T,2,P1*P2>& grid, Vector<T,P1>& x, Vector<T,P2>& y);
  
        template <typename T, xsize P, xsize N>
            void distance(Field2D<T,P,N>& f, T centX, T centY, xsize where);

        template <typename T, xsize N>
            void linspace(Vector<T,N>& , T, T);

        template <typename T, xsize N>
            void linspace2(Vector<T,N>&, T, T);
    }
}

#include "util.cpp"

#endif
