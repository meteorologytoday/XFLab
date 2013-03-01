#include "typedef.h"
#include "matrix.h"

#ifndef X_GRID_H
#define X_GRID_H

namespace X {

    // T  : precision
    // N  : Number of kinds of data
    template <typename T, x_size D, x_size P> 
        class Grid : public Matrix<T,D,P> {
            private:
            public:
                Grid();
                ~Grid();

                T& operator()(x_size d, x_size p);
        };
}

#include "grid.cpp"

#endif
