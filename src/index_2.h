
#ifndef X_INDEX_2_H
#define X_INDEX_2_H

#include "data.h"
#include "index.h"
#include "typedef.h"
#include "offset.h"
#include <iostream>
namespace X {
    
    /*! 
     * \class Index2 index_2.h
     * \author Hsu, Tien-Yiao
     * \copyright NTUAS DMLab
     * \date 2013/04/29
     * \version 1.0
     *  
     * \brief This class is the class for 2-dimensional index using row-major data arrangement.\n
     *  So the (i,j)-th element is at the (i*N2 + j)th position.
     */
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
