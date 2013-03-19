
#ifndef X_DATA_H
#define X_DATA_H
namespace X {
    template <typename T, xsize N>
        class Data {
            private:
                T *data;
                bool manage_memory;
            public:
                Data();
                Data(T*);      // initialize by an pre-defined array
                ~Data();

                inline T* getDataPointer() { return this->data; }
                inline T* p() { return this->getDataPointer(); }
                inline T& getData(xsize i) { return this->data[i]; }
                inline xsize getSize() { return this->N; }
                inline void copyData(Data<T,N>& data) { for(xsize i=0; i < N; ++i) (this->getData(i)) = data.getData(i); }

            public:
                inline void operator+=(Data<T,N>& B) {  for(xsize i=0; i < N; ++i) (this->data)[i] += (B.getDataPointer())[i]; }
                template <typename B> inline void operator+=(B b) {  for(xsize i=0; i < N; ++i) (this->data)[i] += static_cast<T>(b); } 
                inline void operator-=(Data<T,N>& B) {  for(xsize i=0; i < N; ++i) (this->data)[i] -= (B.getDataPointer())[i]; }
                template <typename B> inline void operator-=(B b) {  for(xsize i=0; i < N; ++i) (this->data)[i] -= static_cast<T>(b); } 
                inline void operator*=(Data<T,N>& B) {  for(xsize i=0; i < N; ++i) (this->data)[i] *= (B.getDataPointer())[i]; }
                template <typename B> inline void operator*=(B b) {  for(xsize i=0; i < N; ++i) (this->data)[i] *= static_cast<T>(b); } 
                inline void operator/=(Data<T,N>& B) {  for(xsize i=0; i < N; ++i) (this->data)[i] /= (B.getDataPointer())[i]; }
                template <typename B> inline void operator/=(B b) {  for(xsize i=0; i < N; ++i) (this->data)[i] /= static_cast<T>(b); } 
        };
}

#include "data.cpp"

#endif
