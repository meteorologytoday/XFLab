#ifdef X_DATA_INDEX_1_H
#ifndef X_DATA_INDEX_1_CPP
#define X_DATA_INDEX_1_CPP

namespace X {

    template <typename T, xsize N>
        DataIndex1<T,N>::DataIndex1() : Data<T,N>(), Index1<T,N>(this->getDataPointer()) {
            
        }
 
    template <typename T, xsize N>
        DataIndex1<T,N>::DataIndex1(T* data) : Data<T,N>(data), Index1<T,N>(this->getDataPointer()) {
        }


    template <typename T, xsize N>
        DataIndex1<T,N>::~DataIndex1() {
        }
}

#endif
#endif
