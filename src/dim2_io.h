
#ifndef X_DIM2_IO_H
#define X_DIM2_IO_H

#include "typedef.h"
#include "field2d.h"
#include <iostream>

template<typename T, X::xsize P, X::xsize N>
std::ostream& operator<<(std::ostream& out, X::Field2D<T,P,N>& field);


#include "dim2_io.cpp"

#endif
