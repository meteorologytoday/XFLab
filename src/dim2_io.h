
#ifndef X_DIM2_IO_H
#define X_DIM2_IO_H

#include "typedef.h"
#include "field2.h"
#include <iostream>

template<typename T, X::xsize P1, X::xsize P2, X::xsize N>
std::ostream& operator<<(std::ostream& out, X::Field2<T,P1,P2,N>& field);


#include "dim2_io.cpp"

#endif
