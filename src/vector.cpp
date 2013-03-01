
#ifdef X_VECTOR_H
#ifndef X_VECTOR_CPP
#define X_VECTOR_CPP
namespace X {
    template <typename T, x_size N>
        Vector<T,N>::Vector() {
        }
    template <typename T, x_size N>
        Vector<T,N>::Vector(T *data) : Matrix<T,1,N>(data) {
        }   
    template <typename T, x_size N>
        Vector<T,N>::Vector(T init_value) : Matrix<T,1,N>(init_value) {
        }
    template <typename T, x_size N>
        Vector<T,N>::Vector(Vector<T,N>& original) : Matrix<T,1,N>((Matrix<T,1,N>) original) {
        }
}

#endif
#endif
