
#ifndef X_INDEX_1_H
#define X_INDEX_1_H

#include "typedef.h"
#include "offset.h"
#include "index.h"
#include "data.h"

namespace X {
    template <typename T, xsize N>
        class Index1 : public Index<T> {
            private:
            public:
                Index1() {}
                Index1(T* data) {this->setTargetDataPointer(data);}
                ~Index1() {}
            
            public:
                inline virtual T& operator()(xsize i) { return (this->getTargetDataPointer())[i]; }
                inline virtual T& operator[](xsize i) { return (this->getTargetDataPointer())[i]; }
        };
}


#endif
