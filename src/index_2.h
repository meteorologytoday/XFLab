
#ifndef X_INDEX_2_H
#define X_INDEX_2_H

#include "index.h"
#include "typedef.h"
#include "offset.h"
namespace X {
    template <typename T, xsize N1, xsize N2>
        class Index2 : public Index<T> {
            private:
                T* data;

            public:
                Index2() {}
                Index2(T* data) {this->data = data;}
                ~Index2() {}
            
            public:
                inline T& operator()(xsize i, xsize j) {
                    return data[OFFSET2(N1,N2,i,j)];
                }
        };
}


#endif
