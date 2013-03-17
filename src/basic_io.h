#include "typedef.h"
#include "offset.h"
#include "matrix.h"
#include "vector.h"
#include "field.h"

#include <iostream>
#include <fstream>

#ifndef X_BASIC_IO_H
#define X_BASIC_IO_H

using namespace X;
using namespace std;

template<typename T, xsize ROWS, xsize COLS> 
ostream& operator<<(ostream& out, const Matrix<T,ROWS,COLS>& mtx);

template<typename T, xsize N>
ostream& operator<<(ostream& out, const Vector<T,N>& vec);

namespace X {
    // binary output
    template<typename T, xsize ROWS, xsize COLS>
        void writeBinary(const Matrix<T,ROWS,COLS>& mtx, const char *filename);

    template<typename T, xsize N>
        void writeBinary(const Vector<T,N>& mtx, const char *filename);

}


#include "basic_io.cpp"

#endif
