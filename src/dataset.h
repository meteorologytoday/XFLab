#include "typedef.h"
#include "vector.h"
#include "index_1.h"

#ifndef X_DATASET_H
#define X_DATASET_H

namespace X {
    
    template <typename DT, xsize N>
        class Dataset : Index1<DT,N> {
            private:
                DT *data;

            public:
                Dataset();
                ~Dataset();


            public:
                using Index1<DT,N>::operator();
                using Index1<DT,N>::operator[];
        };

}

#include "dataset.cpp"

#endif
