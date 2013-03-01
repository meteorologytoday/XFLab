#include "typedef.h"
#include "grid.h"

#ifndef X_GRID2_H
#define X_GRID2_H

namespace X {
    template <typename T, x_size P1, x_size P2> 
        class Grid2 : public Grid<T,2,P1*P2> {
            private:
            public:
                Grid2();
                ~Grid2();
                
                T& operator()(x_size d, x_size i, x_size j);
        };
}

#include "grid2.cpp"

#endif
