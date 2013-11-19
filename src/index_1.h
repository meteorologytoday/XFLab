
#ifndef X_INDEX_1_H
#define X_INDEX_1_H

#include "typedef.h"
#include "offset.h"
#include "index.h"
#include "data.h"

namespace X {

    /*! \class Index1 index_1.h
     *  \author Hsu, Tien-Yiao
     *  \copyright NTUAS DMLab
     *  \date 2013/04/27
     *  \version 1.0
     *  
     *  \brief This class is the class for 1-dimensional index.
     */

    template <typename T, xsize N>
        class Index1 : public Index<T> {
            private:
            public:
                
                Index1(T* data) {this->setTargetDataPointer(data);}
                ~Index1() {}
            
            public:

                /*!
                 * Using DataIndex1 as an example:
                 * \code{.cpp}
                 * DataIndex1<float,10> data;
                 * data(0) = 1.0;
                 * \endcode
                 *
                 * Note that this function returns left-value.
                 * 
                 */
                inline virtual T& operator()(xsize i) { return (this->getTargetDataPointer())[i]; }
                inline virtual T& operator[](xsize i) { return (this->getTargetDataPointer())[i]; } /*!< Same as #operator()(xsize).*/
        };
}


#endif
