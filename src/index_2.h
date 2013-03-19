
#ifndef X_INDEX_2_H
#define X_INDEX_2_H

#include "data.h"
#include "index.h"
#include "typedef.h"
#include "offset.h"
namespace X {
    template <typename T, xsize N1, xsize N2>
        class Index2 : public Index<T> {
            private:
            public:
                Index2() {}
                Index2(T* data) {this->setTargetDataPointer(data);}
                ~Index2() {}
            
            public:
                inline virtual T& operator()(xsize i, xsize j) {
                    return this->getTargetDataPointer()[OFFSET2(N1,N2,i,j)];
                }
        };
}


#endif
