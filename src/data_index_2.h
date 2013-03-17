#ifndef X_DATA_INDEX_2_H
#define X_DATA_INDEX_2_H

#include "typedef.h"
#include "index_2.h"
#include "data.h"


namespace X {

    template <typename T, xsize N1, xsize N2>
        class DataIndex2 : public Data<T,N1*N2>, public Index2<T,N1,N2>{
            private:

            public:
                void DefaultConstructor();
                DataIndex2();
                DataIndex2(T*);
                ~DataIndex2();
            
                using Index2<T,N1,N2>::operator();
        };


}

#include "data_index_2.cpp"

#endif
