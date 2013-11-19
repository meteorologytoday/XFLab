#ifndef X_INDEX_H
#define X_INDEX_H
#include <iostream>
namespace X {

    
    
    /*! \class Index index.h
     *  \author Hsu, Tien-Yiao
     *  \copyright NTUAS DMLab
     *  \date 2013/04/27
     *  \version 1.0
     *  
     *  \brief This class is the base class for all the Index.
     *  Data is an 1-dimensional array of data, while sometimes we need more than 1 index.
     *  Programmers may derived from this class to have their own way to access data.
     */
    template <typename T>
        class Index {
            private:
            T* data;
            public:
            inline T* getTargetDataPointer() {return this->data;} 
            inline void setTargetDataPointer(T* data) {this->data = data;}
        };
}


#endif
