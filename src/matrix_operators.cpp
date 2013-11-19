
#ifdef X_MATRIX_H

#ifndef X_MATRIX_OPERATORS_CPP
#define X_MATRIX_OPERATORS_CPP

#include <iostream>
using namespace std;

namespace X {
    // Operator overloading

    template <typename T, xsize ROWS, xsize COLS>
        T& Matrix<T,ROWS,COLS>::operator()(xsize i) {
            return data[i]; 
        }
    template <typename T,xsize ROWS, xsize COLS>
        T& Matrix<T,ROWS,COLS>::operator()(xsize i, xsize j) {
            return data[OFFSET2(ROWS,COLS,i,j)]; 
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::operator<<(T value) {
            data[offset] = value;

            this->offset++;
            
            if(this->offset >= (ROWS*COLS))
                this->resetOffset();

            return *this;
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::operator=(Matrix<T,ROWS,COLS>& mtxB) { 
            this->copyFrom(mtxB);
            return *this;
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::operator,(T value) {
            if(offset >= this->getElms()) {
                resetOffset();
            } else {
                (this->getPtr())[offset] = value;
                ++offset;
            }
            return *this;
        }

    // Add by matrix
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::addBy(Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] += (mtxB.getPtr())[i];
                }
            return *this;
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::subBy(Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] -= (mtxB.getPtr())[i];
                }
            return *this;
        }

     template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::mulBy(Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] *= (mtxB.getPtr())[i];
                }
            return *this;
            }


     template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::divBy(Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] /= (mtxB.getPtr())[i];
                }
            return *this;
        }

    // Add by val
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::addBy(T val) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] += val;
                }
            return *this;
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::subBy(T val) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] -= val;
                }
            return *this;
        }

     template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::mulBy(T val) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] *= val;
                }
            return *this;
        }


     template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::divBy(T val) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] /= val;
                }
            return *this;
        }


    // add of 2 matrices
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::addOf(Matrix<T,ROWS,COLS>& mtxA, Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = (mtxA.getPtr())[i] + (mtxB.getPtr())[i];
                }
            return *this;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::subOf(Matrix<T,ROWS,COLS>& mtxA, Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = (mtxA.getPtr())[i] - (mtxB.getPtr())[i];
                }
            return *this;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::mulOf(Matrix<T,ROWS,COLS>& mtxA, Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = (mtxA.getPtr())[i] * (mtxB.getPtr())[i];
                }
            return *this;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::divOf(Matrix<T,ROWS,COLS>& mtxA, Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = (mtxA.getPtr())[i] / (mtxB.getPtr())[i];
                }
            return *this;
        }


    // add of val and matrix
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::addOf(T valA, Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = valA + (mtxB.getPtr())[i];
                }
            return *this;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::subOf(T valA, Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = valA - (mtxB.getPtr())[i];
                }
            return *this;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::mulOf(T valA, Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = valA * (mtxB.getPtr())[i];
                }
            return *this;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::divOf(T valA, Matrix<T,ROWS,COLS>& mtxB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = valA / (mtxB.getPtr())[i];
                }
            return *this;
        }


    // add of matrix and val
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::addOf(Matrix<T,ROWS,COLS>& mtxA, T valB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = (mtxA.getPtr())[i] + valB;
                }
            return *this;
        }

      template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::subOf(Matrix<T,ROWS,COLS>& mtxA, T valB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = (mtxA.getPtr())[i] - valB;
                }
            return *this;
        }

   template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::mulOf(Matrix<T,ROWS,COLS>& mtxA, T valB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = (mtxA.getPtr())[i] * valB;
                }
            return *this;
        }

   template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::divOf(Matrix<T,ROWS,COLS>& mtxA, T valB) {
                for(xsize i = 0; i < this->getElms(); ++i) {
                    (this->getPtr())[i] = (mtxA.getPtr())[i] / valB;
                }
            return *this;
        }


/*
    // Addition
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator+=(Matrix<T,ROWS,COLS>& lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(lhs.match(rhs)) {
                T *lhs_data = lhs.getPtr();
                T *rhs_data = rhs.getPtr();
                for(xsize i = 0; i < lhs.getElms(); ++i) {
                    lhs_data[i] += rhs_data[i];
                }
            } else {

            }

            return lhs;
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator+=(Matrix<T,ROWS,COLS>& lhs, S rhs) {
            T *lhs_data = lhs.getPtr();
            for(xsize i = 0; i < lhs.getElms(); ++i) {
                lhs_data[i] += (T)rhs;
            }
            return lhs;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator+(Matrix<T,ROWS,COLS>& lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(lhs.isTmp()) {
                return lhs += rhs;
            } else if(rhs.isTmp()) {
                return rhs += lhs;
            } else {
                // Create tmp object
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(lhs.getRows(),lhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copy(lhs);
                (*new_tmp) += rhs;
                return *new_tmp; 
            }
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator+(Matrix<T,ROWS,COLS>& lhs, S rhs) {
            if(lhs.isTmp()) {
                return lhs += rhs;
            } else {
                // Create tmp object
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(lhs.getRows(),lhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copy(lhs);
                (*new_tmp) += rhs;
                return *new_tmp; 
            }
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator+(S lhs, Matrix<T,ROWS,COLS>& rhs) {
            return rhs + lhs;
        }


    // Substraction
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator-=(Matrix<T,ROWS,COLS>& lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(lhs.match(rhs)) {
                T *lhs_data = lhs.getPtr();
                T *rhs_data = rhs.getPtr();
                for(xsize i = 0; i < lhs.getElms(); ++i) {
                    lhs_data[i] -= rhs_data[i];
                }
            } else {

            }

            return lhs;
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator-=(Matrix<T,ROWS,COLS>& lhs, S rhs) {
            T *lhs_data = lhs.getPtr();
            for(xsize i = 0; i < lhs.getElms(); ++i) {
                lhs_data[i] -= (T)rhs;
            }
            return lhs;
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator-(Matrix<T,ROWS,COLS>& mtx) {
            Matrix<T,ROWS,COLS> *mtxp;
            if(mtx.isTmp()) {
                mtxp = &mtx;
            } else {
                mtxp = new Matrix<T,ROWS,COLS>(mtx);
                Memory::add_pointer(mtxp);
                mtxp->setTmp();
            }
            mtxp->negate();
            return *mtxp;
        }

    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator-(Matrix<T,ROWS,COLS>& lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(lhs.isTmp()) {
                return lhs -= rhs;
            } else if(rhs.isTmp()) {
                return (-rhs) + lhs;
            } else {
                // Create tmp object
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(lhs.getRows(),lhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copy(lhs);
                (*new_tmp) -= rhs;
                return *new_tmp; 
            }
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator-(Matrix<T,ROWS,COLS>& lhs, S rhs) {
            if(lhs.isTmp()) {
                return lhs -= rhs;
            } else {
                // Create tmp object
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(lhs.getRows(),lhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copy(lhs);
                (*new_tmp) -= rhs;
                return *new_tmp; 
            }
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator-(S lhs, Matrix<T,ROWS,COLS>& rhs) {
            return (-rhs) + lhs;
        }


    // Multiplication
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator*=(Matrix<T,ROWS,COLS>& lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(lhs.match(rhs)) {
                T *lhs_data = lhs.getPtr();
                T *rhs_data = rhs.getPtr();
                for(xsize i = 0; i < lhs.getElms(); ++i) {
                    lhs_data[i] *= rhs_data[i];
                }
            } else {

            }

            return lhs;
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator*=(Matrix<T,ROWS,COLS>& lhs, S rhs) {
            T *lhs_data = lhs.getPtr();
            for(xsize i = 0; i < lhs.getElms(); ++i) {
                lhs_data[i] *= (T)rhs;
            }
            return lhs;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator*(Matrix<T,ROWS,COLS>& lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(lhs.isTmp()) {
                return lhs *= rhs;
            } else if(rhs.isTmp()) {
                return rhs *= lhs;
            } else {
                // Create tmp object
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(lhs.getRows(),lhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copy(lhs);
                (*new_tmp) *= rhs;
                return *new_tmp; 
            }
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator*(Matrix<T,ROWS,COLS>& lhs, S rhs) {
            if(lhs.isTmp()) {
                return lhs *= rhs;
            } else {
                // Create tmp object
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(lhs.getRows(),lhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copy(lhs);
                (*new_tmp) *= rhs;
                return *new_tmp; 
            }
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator*(S lhs, Matrix<T,ROWS,COLS>& rhs) {
            return rhs*lhs;
        }


    // Division
    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator/=(Matrix<T,ROWS,COLS>& lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(lhs.match(rhs)) {
                T *lhs_data = lhs.getPtr();
                T *rhs_data = rhs.getPtr();
                for(xsize i = 0; i < lhs.getElms(); ++i) {
                    lhs_data[i] /= rhs_data[i];
                }
            } else {

            }

            return lhs;
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator/=(Matrix<T,ROWS,COLS>& lhs, S rhs) {
            T *lhs_data = lhs.getPtr();
            for(xsize i = 0; i < lhs.getElms(); ++i) {
                lhs_data[i] /= (T)rhs;
            }
            return lhs;
        }


    template <typename T,xsize ROWS, xsize COLS>
        Matrix<T,ROWS,COLS>& operator/(Matrix<T,ROWS,COLS>& lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(lhs.isTmp()) {
                return lhs /= rhs;
            } else if(rhs.isTmp()) {
                return rhs.reciprocal() *= lhs;
            } else {
                // Create tmp object
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(lhs.getRows(),lhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copy(lhs);
                (*new_tmp) /= rhs;
                return *new_tmp; 
            }
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator/(Matrix<T,ROWS,COLS>& lhs, S rhs) {
            if(lhs.isTmp()) {
                return lhs /= rhs;
            } else {
                // Create tmp object
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(lhs.getRows(),lhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copyFrom(lhs);
                (*new_tmp) /= rhs;
                return *new_tmp; 
            }
        }

    template <typename T, typename S>
        Matrix<T,ROWS,COLS>& operator/(S lhs, Matrix<T,ROWS,COLS>& rhs) {
            if(rhs.isTmp()) {
                return rhs.reciprocal() * lhs;
            } else {
                Matrix<T,ROWS,COLS> *new_tmp = new Matrix<T,ROWS,COLS>(rhs.getRows(),rhs.getCols());
                Memory::add_pointer(new_tmp);

                new_tmp->setTmp();
                new_tmp->copyFrom(rhs);            
                return new_tmp->reciprocal() * lhs;
            }

    }
    */
};

#endif
#endif
