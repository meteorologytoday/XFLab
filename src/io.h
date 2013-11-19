
#ifndef X_IO_H
#define X_IO_H

#include <iostream>
#include <fstream>

namespace X {

    namespace IO {

        // without converting function
        template <typename T, xsize N>
            void writeBinaryData(Data<T,N>& data, ostream& out);

        // without converting function
        template <typename T, xsize N>
            void readBinaryData(Data<T,N>& data, istream& in);
 
        // with converting function
        template <typename T, xsize N, typename Fn>
            void writeBinaryData(Data<T,N>& data, ostream& out, xsize bytes, Fn f);

        // with converting function
        template <typename T, xsize N, typename Fn>
            void readBinaryData(Data<T,N>& data, istream& in, xsize bytes, Fn f);
    }

}

#include "io.cpp"

#endif
