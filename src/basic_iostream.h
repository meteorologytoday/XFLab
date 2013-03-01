#include "typedef.h"
#include "offset.h"
#include "matrix.h"
#include "vector.h"
#include "grid.h"
#include "field.h"

#include <iostream>

#ifndef X_BASIC_IOSTREAM_H
#define X_BASIC_IOSTREAM_H

template<typename T, X::x_size ROWS, X::x_size COLS> 
std::ostream& operator<<(std::ostream& out, const X::Matrix<T,ROWS,COLS>& mtx);

template<typename T, X::x_size N>
std::ostream& operator<<(std::ostream& out, const X::Vector<T,N>& vec);


#include "basic_iostream.cpp"

#endif
