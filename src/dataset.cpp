#ifdef X_DATASET_H
#ifndef X_DATASET_CPP
#define X_DATASET_CPP
#include <iostream>
using namespace std;
namespace X {

    template <typename DT, xsize N>
        Dataset<DT,N>::Dataset() {
            this->data = new DT[N]();
            Index1<DT,N>::setTargetDataPointer(this->data);
        }

    template <typename DT, xsize N>
         Dataset<DT,N>::~Dataset() {
            delete [] data;
        }
}

#endif
#endif
