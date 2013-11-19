#include "typedef.h"
#include "field2d.h"

#ifndef X_FIELD_2D_INDEX_2_H
#define X_FIELD_2D_INDEX_2_H

namespace X {

    template <typename T, xsize P1, xsize P2, xsize N> 
        class Field2DIndex2 : public Field2D<T,P1*P2,N> {
            private:
            public:
                Field2DIndex2();
                ~Field2DIndex2();

                inline T& operator()(xsize n, xsize i, xsize j) {
                    return (this->operator[](n))(OFFSET2(P1,P2,i,j));
                }

        };

}


#endif
