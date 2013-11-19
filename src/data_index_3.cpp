#ifdef X_DATA_INDEX_3_H
#ifndef X_DATA_INDEX_3_CPP
#define X_DATA_INDEX_3_CPP

namespace X {

    template <typename T, xsize N1, xsize N2, xsize N3>
        DataIndex3<T,N1,N2,N3>::DataIndex3() : Data<T,N1*N2*N3>(), Index3<T,N1,N2,N3>(this->getDataPointer()) {
            
        }

    template <typename T, xsize N1, xsize N2, xsize N3>
        DataIndex3<T,N1,N2,N3>::~DataIndex3() {
        }
}

#endif
#endif
