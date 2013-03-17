#ifndef X_DATA_INDEX_1_H
#define X_DATA_INDEX_1_H

#include "typedef.h"
#include "index_1.h"
#include "data.h"


namespace X {

    template <typename T, xsize N>
        class DataIndex1 : public Data<T,N>, public Index1<T,N>{
            private:

            public:
                void DefaultConstructor();
                DataIndex1();
                DataIndex1(T*);
                ~DataIndex1();
            
                using Index1<T,N>::operator();
        };


}

#include "data_index_1.cpp"

#endif
