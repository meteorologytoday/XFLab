#include "typedef.h"
#include "matrix.h"

#ifndef X_VECTOR_H
#define X_VECTOR_H
namespace X {

    template <typename T, x_size N>
        class Vector : public Matrix<T,1,N> {
            public:
                Vector(); 
                Vector(T *data);
                Vector(T init_value);
                Vector(Vector<T,N>& original);

                inline T* getPtr() { return ((Matrix<T,1,N>*)this)->getPtr(); }
        };

}

#include "vector.cpp"

#endif
