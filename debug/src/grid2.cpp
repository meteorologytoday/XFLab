#ifdef X_GRID2_H

#ifndef X_GRID2_CPP
#define X_GRID2_CPP


namespace X {



    template <typename T, x_size P1, x_size P2> 
        Grid2<T,P1,P2>::Grid2() {
            
        }


    template <typename T, x_size P1, x_size P2> 
        Grid2<T,P1,P2>::~Grid2() {
            
        }

    template <typename T, x_size P1, x_size P2> 
        T& Grid2<T,P1,P2>::operator()(x_size d, x_size i, x_size j) {
            
            return Grid<T,2,P1*P2>::operator()(d, OFFSET2(P1,P2,i,j));

        }

}

#endif
#endif
