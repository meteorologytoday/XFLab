#ifdef X_MATRIX_H

#ifndef X_MATRIX_CPP
#define X_MATRIX_CPP




#include <iostream>
#include <new>
using namespace std;

namespace X {

    
    template <typename T, x_size ROWS, x_size COLS>
        Matrix<T,ROWS,COLS>::Matrix() {
            DefaultConstructor();
        }

    template <typename T, x_size ROWS, x_size COLS>
        Matrix<T,ROWS,COLS>::Matrix(T* data) {
            this->data = data;
            this->resetOffset();
            this->manage_memory = false;
        }


    template <typename T,x_size ROWS, x_size COLS>
        Matrix<T,ROWS,COLS>::Matrix(T init_value) {
            DefaultConstructor();
        }

    template <typename T,x_size ROWS, x_size COLS>
        Matrix<T,ROWS,COLS>::Matrix(Matrix<T,ROWS,COLS>& original) {
            DefaultConstructor();
            this->copyFrom(original);
        }

    template <typename T,x_size ROWS, x_size COLS>
        Matrix<T,ROWS,COLS>::~Matrix() {
            std::cout << "Matrix destructor called" << std::endl;
            if(this->manage_memory == true) 
                delete [] data;
        }

    template <typename T,x_size ROWS, x_size COLS>
        void Matrix<T,ROWS,COLS>::DefaultConstructor() {
            cout << "default!" << endl;
            // # Pending : Need to check if rows*cols overflows
            try {
                this->data = new T[ROWS * COLS]();
            } catch (std::bad_alloc &exc) {
                cerr << "bad_alloc caught" << exc.what() << endl;    
            }
            this->resetOffset();
            this->manage_memory = true;
        }


    // tools
    template <typename T,x_size ROWS, x_size COLS>
         Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::copyFrom(Matrix<T,ROWS,COLS>& mtxB) {
            for(x_size i=0; i < getElms(); ++i) {
                this->data[i] = mtxB.data[i];
            }
            return *this;
        }

    template <typename T,x_size ROWS, x_size COLS>
         Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::negate() {
            for(x_size i=0; i < this->getElms(); ++i) {
                this->data[i] = -this->data[i];
            }

            return *this;
        }

    template <typename T,x_size ROWS, x_size COLS>
         Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::reciprocal() {
            for(x_size i=0; i < this->getElms(); ++i) {
                this->data[i] = 1/this->data[i];
            }

            return *this;
        }
/*
    template <typename T,x_size ROWS, x_size COLS>
        inline x_size Matrix<T,ROWS,COLS>::getElms() const{
            return ROWS * COLS;
        }

    template <typename T,x_size ROWS, x_size COLS>
        inline T* Matrix<T,ROWS,COLS>::getPtr() const {
            return this->data;
        }

    template <typename T,x_size ROWS, x_size COLS>
        inline x_size Matrix<T,ROWS,COLS>::getOffset() const {
            return this->offset;
        }

    template <typename T,x_size ROWS, x_size COLS>
        inline void Matrix<T,ROWS,COLS>::resetOffset() {
            this->offset = 0;
        }

    template <typename T,x_size ROWS, x_size COLS>
        inline void Matrix<T,ROWS,COLS>::setOffset(x_size offset) {
            if(offset < ROWS * COLS)
                this->offset = offset;
            else
                throw 1;
        }

*/

    /*
    // operations
    template <typename T,x_size ROWS, x_size COLS>
    inline Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::mulOf(Matrix<T,ROWS,COLS>& mtxA, Matrix<T,ROWS,COLS>& mtxB) {
    Matrix<T,ROWS,COLS> *mtxp;
    if(mtxA.getCols() == mtxB.getRows()) { // valid operation
    if(this->isTmp()) {
    if(this->rows == mtxA.getRows() && this->cols == mtxB.getCols()) { // valid dimension
    mtxp = this;
    } else {
    // Error
    }
    } else {
    mtxp = new Matrix<T,ROWS,COLS>(mtxA.getRows(), mtxB.getCols());
    Memory::add_pointer(mtxp);
    }
    } else {
    // Error
    }
    mtxp->zero();
// Multiplication
for(x_size j=0; j < mtxB.getCols(); ++j) {
for(x_size i=0; i < mtxA.getRows(); ++i) {
for(x_size k=0; i < mtxA.getCols(); ++k) {
(*mtxp)(i,j) += (mtxA(i,k) * mtxB(k,j));
}}

}

return *mtxp;
}*/
}

#endif
#endif
