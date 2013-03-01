#ifdef X_GRID_H
#ifndef X_GRID_CPP
#define X_GRID_CPP

namespace X {

    template <typename T, x_size D, x_size P> 
        Grid<T,D,P>::Grid() {
        }

    template <typename T, x_size D, x_size P> 
        Grid<T,D,P>::~Grid() {
        }

    template <typename T, x_size D, x_size P> 
        T& Grid<T,D,P>::operator()(x_size d, x_size p) {
            return Matrix<T,D,P>::operator()(d,p);
        }
}


#endif
#endif
