#ifndef X_NORMAL_OPERATION_H
#define X_NORMAL_OPERATION_H

#include "typedef.h"

class NormalOperation<typename T, xsize N> {
template <typename T, N>
Matrix<T,ROWS,COLS>& Matrix<T,ROWS,COLS>::addBy(Matrix<T,ROWS,COLS>& mtxB) {
    for(xsize i = 0; i < this->getElms(); ++i) {
        (this->getPtr())[i] += (mtxB.getPtr())[i];
    }
    return *this;
}
}
#endif

