#ifdef X_IO_H
#ifndef X_IO_CPP
#define X_IO_CPP

#include <fstream>

namespace X {
    namespace IO {
        
        template <typename T, xsize N>
            void printBinaryData(Data<T,N>& data, ostream& out) {
                xsize size = N;
                T * datap = data.getDataPointer();
                out.write((char *)(&size), sizeof(xsize));
                out.write((char *)  datap, sizeof(T) * N);
        }

        template <typename T, xsize N>
            void readBinaryData(Data<T,N>& data, istream& in) {
                xsize size = 0;
                T * datap = data.getDataPointer();
                in.read((char *) (&size), sizeof(xsize));
                if(size != N) { throw 1; }

                in.read((char *) datap, sizeof(T) * N);
            
            }
    }
}



#endif
#endif
