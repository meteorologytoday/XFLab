#include "typedef.h"
#include "vector.h"
#include "grid.h"

#ifndef X_FIELD_H
#define X_FIELD_H

namespace X {

    // T : data precision
    // N : number of data
    // P : points of field
    template <typename T, x_size D, x_size P, x_size N>
        class Field {
            private:
                Grid<T,D,P> *grid;
                T *raw_data;
                Vector<T,P> **vec;
            public:
                void DefaultConstructor();
                Field();
                Field(Grid<T,D,P>&);
                ~Field();


            public:
                inline void setGrid(Grid<T,D,P>&);
            public: // operators overloading

                Vector<T,P>& operator[](x_size i);
                T& operator()(x_size n, x_size p);
        };

}

#include "field.cpp"

#endif
