#ifdef X_DATA_H
#ifndef X_DATA_CPP
#define X_DATA_CPP

namespace X {
    template <typename T, xsize N>
        Data<T,N>::Data() {
            manage_memory = true;
            data = new T[N]();
        }

 template <typename T, xsize N>
        Data<T,N>::Data(T* data) {
            manage_memory = false;
            this->data = data;
        }


 template <typename T, xsize N>
        Data<T,N>::~Data() {
            if(manage_memory == true)
                delete [] data;
        }

}





#endif
#endif
