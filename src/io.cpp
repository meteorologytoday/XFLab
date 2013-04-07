#ifdef X_IO_H
#ifndef X_IO_CPP
#define X_IO_CPP

#include <iostream>
using namespace std;
namespace X {
    namespace IO { 

        // Without converting function
        template <typename T, xsize N>
            void writeBinaryData(Data<T,N>& data, ostream& out) {
                
                xsize size = N;
                T * datap = data.getDataPointer();

                char * buffer = new char[4]();
                
                out.write((char *)(&size), sizeof(xsize));
                for(xsize i=0; i < N; ++i) {
                    *(reinterpret_cast<float*>(buffer)) = static_cast<float>(datap[i]);
                    out.write(buffer, sizeof(char) * 4);
                }

                delete buffer;
        }


        // Without converting function
        template <typename T, xsize N>
            void readBinaryData(Data<T,N>& data, istream& in) {
                xsize size = 0;

                T * datap = data.getDataPointer();
                in.read(reinterpret_cast<char*>(&size), sizeof(xsize));
                if( static_cast<xsize>(N) != size ) { throw 1; }
                
                char * buffer = new char[4];
                for(xsize i=0; i<N; ++i) {
                    in.read(reinterpret_cast<char*>(buffer), sizeof(char) * 4);
                    datap[i] = static_cast<T>( *(reinterpret_cast<float*>(buffer)) );
                }
            }
 
        
        
        // With converting function
        template <typename T, xsize N, typename Fn>
            void writeBinaryData(Data<T,N>& data, ostream& out, xsize bytes, Fn f) {

                xsize size = N;
                T * datap = data.getDataPointer();

                if(bytes <= 0) { bytes = 4; } // standard 4 bytes
                char * buffer = new char[bytes]();
                
                out.write(reinterpret_cast<char*>(&size), sizeof(xsize));
                for(xsize i=0; i < N; ++i) {
                    f(&(datap[i]), reinterpret_cast<void*>(buffer));
                    out.write(buffer, sizeof(char) * bytes);
                }

                delete buffer;
        }
        // With converting function
        template <typename T, xsize N, typename Fn>
            void readBinaryData(Data<T,N>& data, istream& in, xsize bytes, Fn f) {
                xsize size = 0;
                if(bytes <= 0) { bytes = 4; } // standard 4 bytes

                char * buffer = new char[bytes]();

                T * datap = data.getDataPointer();
                in.read(reinterpret_cast<char*>(&size), sizeof(xsize));

                if( static_cast<xsize>(N) != size ) { throw 1; }

                for(xsize i=0; i < N; ++i) {
                    in.read(buffer, sizeof(char) * bytes);
                    f(reinterpret_cast<void*>(buffer), &(datap[i]));
                }
                delete buffer;
            }
    }
}



#endif
#endif
