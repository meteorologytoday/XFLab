#ifdef X_DATA_INDEX_2_H
#ifndef X_DATA_INDEX_2_CPP
#define X_DATA_INDEX_2_CPP

namespace X {

    template <typename T, xsize N1, xsize N2>
        DataIndex2<T,N1,N2>::DataIndex2() : Data<T,N1*N2>(), Index2<T,N1,N2>(this->getDataPointer()) {
            
        }
    template <typename T, xsize N1, xsize N2>
        DataIndex2<T,N1,N2>::~DataIndex2() {
        }
}

#endif
#endif
