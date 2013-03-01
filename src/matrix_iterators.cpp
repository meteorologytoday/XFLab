#ifdef X_MATRIX_H

#ifndef X_MATRIX_ITERATORS_CPP
#define X_MATRIX_ITERATORS_CPP
namespace X {
    template <typename T, x_size ROWS, x_size COLS>
        Matrix<T, ROWS, COLS>& Matrix<T, ROWS, COLS>::each(void (*f)(T)) const {
            for(x_size i = 0; i < this->getElms(); ++i) {
                (*f)((this->getData())[i]);
            }

            return *this;
    }

}
#endif
#endif
