#ifndef X_DATA_INDEX_1_H
#define X_DATA_INDEX_1_H

#include "typedef.h"
#include "index_1.h"
#include "data.h"


namespace X {

    /*! \class DataIndex1 data_index_1.h
     *  \author Hsu, Tien-Yiao
     *  \copyright NTUAS DMLab
     *  \date 2013/04/29
     *  \version 1.0
     *  
     *  \brief This class is for 1-dimensional data. 
     */
    template <typename T, xsize N>
        class DataIndex1 : public Data<T,N>, public Index1<T,N>{
            private:

            private:
                /*!
                 * Defulat constructor
                 */
                void DefaultConstructor();
            
            public:
                DataIndex1();
                DataIndex1(T*);
                ~DataIndex1();

	 		   using Data<T,N>::operator=;			
	 		   using Data<T,N>::operator+=;
	 		   using Data<T,N>::operator-=;
	 		   using Data<T,N>::operator*=;
	 		   using Data<T,N>::operator/=;
               using Index1<T,N>::operator();
        };


}

#include "data_index_1.cpp"

#endif
