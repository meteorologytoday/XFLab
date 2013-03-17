
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

                inline virtual void setData(Data&) {  }
                inline virtual Data& getData() { return data; }


        };
}

#include "data.cpp"

#endif
