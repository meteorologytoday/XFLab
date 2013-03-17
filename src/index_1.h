
#ifndef X_INDEX_1_H
#define X_INDEX_1_H

#include "index.h"
#include "typedef.h"
#include "offset.h"

namespace X {
    template <typename T, xsize N>
        class Index1 : public Index<T> {
            private:
                T* data;

            public:
                Index1() {}
                Index1(T* data) {this->data = data;}
                ~Index1() {}
            
            public:
                inline virtual T& operator()(xsize i) {
                    return data[i];
                }
        };
}


#endif
