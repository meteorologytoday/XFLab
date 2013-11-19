#ifdef X_DATA_H
#ifndef X_DATA_CPP
#define X_DATA_CPP

namespace X {
    template <typename T, xsize N>
        Data<T,N>::Data() {
            data = new T[N]();
        }

    template <typename T, xsize N>
        Data<T,N>::~Data() {
            delete [] data;
        }

}





#endif
#endif
