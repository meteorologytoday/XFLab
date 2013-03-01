#include "typedef.h"
#include "field.h"
#include "grid2.h"

#ifndef X_FIELD2_H
#define X_FIELD2_H

namespace X {

    template <typename T, x_size P1, x_size P2, x_size N> 
        class Field2 : private Field<T,2,P1*P2,N> {
            private:
            public:
                Field2();
                Field2(Grid2<T,P1,P2>&);
                ~Field2();

                using Field<T,2,P1*P2,N>::operator[];
                T& operator()(x_size n, x_size i, x_size j);
                //Matrix<DT,N,D1*D2>& operator<<(Vector<DT,N>);
        };

}

#include "field2.cpp"

#endif
