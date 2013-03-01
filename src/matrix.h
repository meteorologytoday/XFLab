#include "typedef.h"
#include "offset.h"

#define DEBUG
#include <assert.h>

#ifndef X_MATRIX_H
#define X_MATRIX_H
#include <iostream>
using namespace std;
namespace X {

    template <typename T, x_size ROWS, x_size COLS>
        class Matrix {
            private:
                T *data;
                x_size offset;
                bool manage_memory;
            public:
                Matrix(); 
                Matrix(T *data);
                Matrix(T init_value);
                Matrix(Matrix<T,ROWS,COLS>& original);
                ~Matrix();
                void DefaultConstructor();

            public: // operations
                Matrix<T,ROWS,COLS>& copyFrom(Matrix<T,ROWS,COLS>& mtxB);
                Matrix<T,ROWS,COLS>& negate();
                Matrix<T,ROWS,COLS>& reciprocal();


            public:
                Matrix<T,ROWS,COLS>& each(void (*)(T)) const;


            public: // getter and setters
                inline x_size getElms() const {return ROWS*COLS;}
                inline T* getPtr() const { return this->data; }

            public:
                Matrix<T,ROWS,COLS>& addBy(Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& subBy(Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& mulBy(Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& divBy(Matrix<T,ROWS,COLS>&);

                Matrix<T,ROWS,COLS>& addBy(T);
                Matrix<T,ROWS,COLS>& subBy(T);
                Matrix<T,ROWS,COLS>& mulBy(T);
                Matrix<T,ROWS,COLS>& divBy(T);

                Matrix<T,ROWS,COLS>& addOf(Matrix<T,ROWS,COLS>&, Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& subOf(Matrix<T,ROWS,COLS>&, Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& mulOf(Matrix<T,ROWS,COLS>&, Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& divOf(Matrix<T,ROWS,COLS>&, Matrix<T,ROWS,COLS>&);

                Matrix<T,ROWS,COLS>& addOf(T, Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& subOf(T, Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& mulOf(T, Matrix<T,ROWS,COLS>&);
                Matrix<T,ROWS,COLS>& divOf(T, Matrix<T,ROWS,COLS>&);

                Matrix<T,ROWS,COLS>& addOf(Matrix<T,ROWS,COLS>&, T);
                Matrix<T,ROWS,COLS>& subOf(Matrix<T,ROWS,COLS>&, T);
                Matrix<T,ROWS,COLS>& mulOf(Matrix<T,ROWS,COLS>&, T);
                Matrix<T,ROWS,COLS>& divOf(Matrix<T,ROWS,COLS>&, T);

            public:
                inline void resetOffset() {this->offset = 0;}
                inline void setOffset(x_size offset) { this->offset = offset;}
                inline x_size getOffset() const {return this->offset;}
            
            public: // operators overloading
                Matrix<T,ROWS,COLS>& operator=(Matrix<T,ROWS,COLS>&);
                T& operator()(x_size);
                T& operator()(x_size, x_size);
                Matrix<T,ROWS,COLS>& operator<<(T);
                Matrix<T,ROWS,COLS>& operator,(T);
        };

}

#include "matrix.cpp"
#include "matrix_operators.cpp"
#include "matrix_iterators.cpp"

#endif
