
#ifndef X_DATA_H
#define X_DATA_H

#include <iostream>
namespace X {


    /*! \class Data data.h
     *  \author Hsu, Tien-Yiao
     *  \copyright NTUAS DMLab
     *  \date 2013/04/27
     *  \version 1.0
     *  
     *  \brief This class is the base class for all the data.
     *  \details Data needs to be specified its data type and number of elements. #data
     */
    template <typename T, xsize N>
        class Data {
            private:
                T *data; /*!< The heap memory where #data are stored. */
            public: 
                /*! 
                 * Initialize an array of N elements with type T.
                 * They are all with default initialized value.
                 */
                Data();
                
                /*! 
                 * Deconstructor frees all the heap memory of the object.
                 */
                ~Data();

                inline T* getDataPointer() { return this->data; }   /*!< Return the pointer of the data */
                inline void setDataPointer(T* data) { this->data = data; }   /*!< Return the pointer of the data */
                inline T* p() { return this->getDataPointer(); }    /*!< Abbreviation for getDataPointer() */
                inline void setp(T* data) { this->setDataPointer(data); }   /*!< Return the pointer of the data */
                inline T& getData(xsize i) { return this->data[i]; }/*!< Get the i-th element of the data. */
                
                /*!
                 *  Copies the value of another data.
                 */
                inline void copyData(Data<T,N>& data) {
					for(xsize i=0; i < N; ++i) (this->getData(i)) = data.getData(i); 
				}

            public:
                inline Data<T,N>& operator=(Data<T,N>& B) { 
					std::cout << "Why ?" << std::endl;
					this->copyData(B);	
					return *this;
				} // Danger, probably gcc compiler bug .

                template <typename B> inline Data<T,N>& operator=(B b) {for(xsize i=0; i < N; ++i) (this->data)[i] = static_cast<T>(b); return *this;} 

				inline Data<T,N>& operator+=(Data<T,N>& B) {  for(xsize i=0; i < N; ++i) (this->data)[i] += (B.getDataPointer())[i]; }
                template <typename B> inline Data<T,N>& operator+=(B b) {  for(xsize i=0; i < N; ++i) (this->data)[i] += static_cast<T>(b); }

                inline Data<T,N>& operator-=(Data<T,N>& B) {  for(xsize i=0; i < N; ++i) (this->data)[i] -= (B.getDataPointer())[i]; }
                template <typename B> inline Data<T,N>& operator-=(B b) {  for(xsize i=0; i < N; ++i) (this->data)[i] -= static_cast<T>(b); } 

                inline Data<T,N>& operator*=(Data<T,N>& B) {  for(xsize i=0; i < N; ++i) (this->data)[i] *= (B.getDataPointer())[i]; }
                template <typename B> inline Data<T,N>& operator*=(B b) {  for(xsize i=0; i < N; ++i) (this->data)[i] *= static_cast<T>(b); } 

                inline Data<T,N>& operator/=(Data<T,N>& B) {  for(xsize i=0; i < N; ++i) (this->data)[i] /= (B.getDataPointer())[i]; }
                template <typename B> inline Data<T,N>& operator/=(B b) {  for(xsize i=0; i < N; ++i) (this->data)[i] /= static_cast<T>(b); } 
        };
}

#include "data.cpp"

#endif
