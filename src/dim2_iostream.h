
#ifndef X_DIM2_IOSTREAM_H
#define X_DIM2_IOSTREAM_H

#include "typedef.h"
#include "field2.h"
#include <iostream>

template<typename T, X::x_size P1, X::x_size P2, X::x_size N>
std::ostream& operator<<(std::ostream& out, X::Field2<T,P1,P2,N>& field);

#include "dim2_iostream.cpp"

#endif
