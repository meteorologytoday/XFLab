
#ifndef X_IO_H
#define X_IO_H

namespace X {

    namespace IO {

        template <typename T, xsize N>
            void printBinaryData(Data<T,N>& data, ostream& out);

        template <typename T, xsize N>
            void readBinaryData(Data<T,N>& data, istream& in);
    }

}

#include "io.cpp"

#endif
