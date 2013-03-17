#include "typedef.h"
#include "vector.h"

#ifndef X_FIELD_H
#define X_FIELD_H

namespace X {

    // T : data precision
    // N : number of data
    // P : points of field
    template <typename T, xsize D, xsize P, xsize N>
        class Field {
            private:
                Matrix<T,D,P> *grid;
                T *raw_data;
                Vector<T,P>   **vec;

            public:
                void DefaultConstructor();
                Field();
                Field(Matrix<T,D,P>&);
                ~Field();


            public:
                void setGrid(Matrix<T,D,P>& grid);
                Matrix<T,D,P>* getGrid();

            public: // operators overloading

                Vector<T,P>& operator[](xsize i);
                T& operator()(xsize n, xsize p);
        };

}

#include "field.cpp"

#endif
