#include "typedef.h"
#include "field.h"

#ifndef X_FIELD_2D_H
#define X_FIELD_2D_H

namespace X {

    template <typename T, xsize P, xsize N> 
        class Field2D : public Field<T,2,P,N> {
            private:
            public:
                Field2D()  { };
                ~Field2D() { };
        };

}

#endif
