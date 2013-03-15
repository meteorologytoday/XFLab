#ifdef X_MATRIX_H

#ifndef X_MATRIX_CPP
#define X_MATRIX_CPP




#include <iostream>
#include <new>
using namespace std;

namespace X {


    template <typename T, xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>::Matrix() {
            DefaultConstructor();
        }

    template <typename T, xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>::Matrix(T* data) {
            this->data = data;
            this->resetOffset();
            this->manage_memory = false;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>::Matrix(T init_value) {
            DefaultConstructor();
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>::Matrix(Matrix<T,ROWS,COLS>& original) {
            DefaultConstructor();
            this->copyFrom(original);
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>::~Matrix() {
            std::cout << "Matrix destructor called" << std::endl;
            if(this->manage_memory == true) 
                delete [] data;
        }

    template <typename T,xsize ROWS, xsize COLS>
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
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::copyFrom(Matrix<T,ROWS,COLS>& mtxB) {
            for(xsize i=0; i < this->getElms(); ++i) {
                (this->getPtr())[i] = (mtxB.getPtr())[i];
            }
            return *this;
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::negate() {
            for(xsize i=0; i < this->getElms(); ++i) {
                this->data[i] = -this->data[i];
            }

            return *this;
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::reciprocal() {
            for(xsize i=0; i < this->getElms(); ++i) {
                this->data[i] = 1/this->data[i];
            }

            return *this;
        }

}

#endif
#endif
