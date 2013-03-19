#include "typedef.h"
#include "dataset.h"

#ifndef X_FIELD_H
#define X_FIELD_H

namespace X {
    
    template <typename DT, typename GT, xsize P, xsize N>
        class Field : public Dataset<DT,N> {
            private:
                GT *grid;

            public:
                Field();
                ~Field();


            public:
                inline GT& getGrid() { return *(this->grid); }
                using Dataset<DT,N>::operator[];
        };

}

#include "field.cpp"

#endif
