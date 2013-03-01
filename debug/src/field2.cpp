#ifdef X_FIELD2_H

#ifndef X_FIELD2_CPP
#define X_FIELD2_CPP

#include <iostream>
using namespace std;

namespace X {

    template <typename T, x_size P1, x_size P2, x_size N>
        Field2<T,P1,P2,N>::Field2() {
        }

    template <typename T, x_size P1, x_size P2, x_size N> 
        Field2<T,P1,P2,N>::Field2(Grid2<T,P1,P2>& grid) : Field<T,2,P1*P2,N>(grid) {
        }

    template <typename T, x_size P1, x_size P2, x_size N> 
        Field2<T,P1,P2,N>::~Field2() {

        }

    template <typename T, x_size P1, x_size P2, x_size N> 
        T& Field2<T,P1,P2,N>::operator()(x_size n, x_size i, x_size j) {
            return Field<T,2,P1*P2,N>::operator()(n,OFFSET2(P1,P2,i,j));
        }

}



#endif
#endif
