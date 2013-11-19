#ifndef X_DATA_INDEX_3_H
#define X_DATA_INDEX_3_H

#include "typedef.h"
#include "index_3.h"
#include "data.h"


namespace X {

    template <typename T, xsize N1, xsize N2, xsize N3>
        class DataIndex3 : public Data<T,N1*N2*N3>, public Index3<T,N1,N2,N3>{
            private:
                void DefaultConstructor();
            
            public:
                DataIndex3();
                ~DataIndex3();
    
                using Data<T,N1*N2*N3>::operator+=;
                using Data<T,N1*N2*N3>::operator-=;
                using Data<T,N1*N2*N3>::operator*=;
                using Data<T,N1*N2*N3>::operator/=;
                using Index3<T,N1,N2,N3>::operator();
        };


}

#include "data_index_3.cpp"

#endif
