#ifndef X_INDEX_H
#define X_INDEX_H
namespace X {
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
