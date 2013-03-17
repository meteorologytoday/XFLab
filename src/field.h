#include "typedef.h"
#include "vector.h"
#include "index_1.h"

#ifndef X_FIELD_H
#define X_FIELD_H

namespace X {
    
    template <typename DT, typename GT, xsize P, xsize N>
        class Field : Index1<DT,P> {
            private:
                GT  *grid;
                DT **data;

            public:
                Field();
                ~Field();


            public:
                inline GT * getGrid() { return this->grid; }
        };

}

#include "field.cpp"

#endif
