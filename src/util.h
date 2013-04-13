#include "typedef.h"
#include "index_1.h"
#include "index_2.h"
#include "data_index_2.h"
#include <cmath>

#ifndef X_UTIL_H
#define X_UTIL_H
namespace X {
    namespace Util{
        template <typename T, xsize N1, xsize N2>
            void ddMeshgrid(Index2<T,N1,N2>& gridx, Index2<T,N1,N2>& gridy, Index1<T,N1>& x, Index1<T,N2>& y);
  
        template <typename T, xsize N>
            void dLinspace1(Index1<T,N>&, T, T);

        template <typename T, xsize N>
            void dLinspace2(Index1<T,N>&, T, T);

        // Laplacian with Neumann boundary condition
        // Neumann boundary condition means you have to specify first derivative yourself,
        // Please specify the value of 1st derivative of x and y direction in bc_dx and bc_dy
        //
        // In the function, x and y are equally spaced.
        template <typename T, xsize N1, xsize N2>
            void ddLaplacianNeumann1(Index2<T,N1,N2>& in, Index2<T,N1,N2>& out, Index2<T, N1, N2>& bc_dx, Index2<T, N1, N2>& bc_dy, T dx, T dy);


        // interpolation
        template <typename T, xsize N1, xsize N2, xsize N3, xsize N4>
            void ddInterp1(Index2<T,N1,N2>& in, Index2<T,N3,N4>& out);




    }
}

#include "util.cpp"

#endif
