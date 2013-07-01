
#ifndef X_INDEX_3_H
#define X_INDEX_3_H

#include "data.h"
#include "index.h"
#include "typedef.h"
#include "offset.h"
namespace X {
    
    /*! 
     * \class Index3 index_3.h
     * \author Hsu, Tien-Yiao
     * \copyright NTUAS DMLab
     * \date 2013/05/09
     * \version 1.1
     *  
     * \brief This class is the class for 3-dimensional index using row-major data arrangement.\n
     *  So the (i,j,k)-th element is at the (i*N2*N3 + j*N3 + k)th position.
     */
    template <typename T, xsize N1, xsize N2, xsize N3>
        class Index3 : public Index<T> {
            private:
            public:
                Index3() {}
                Index3(T* data) {this->setTargetDataPointer(data);}
                ~Index3() {}
            
            public:
                inline virtual T& operator()(xsize i, xsize j, xsize k) {
                    return this->getTargetDataPointer()[OFFSET3(N1,N2,N3,i,j,k)];
                }
        };
}


#endif
