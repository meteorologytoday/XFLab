
#ifdef X_BASIC_IO_H
#ifndef X_BASIC_IO_CPP
#define X_BASIC_IO_CPP

template<typename T, xsize ROWS, xsize COLS>
ostream& operator<<(ostream& out, const Matrix<T,ROWS,COLS>& mtx) {

    const T *data = mtx.getPtr();
    out << '[';
    for(xsize i = 0; i < ROWS; ++i) {
        if(i != 0) { out << ';' << endl; }
        for(xsize j = 0; j < COLS; ++j) {
            if(j!=0) { out << ','; }
            out << data[OFFSET2(ROWS,COLS,i,j)];
        }
    }

    out << ']'; 
    return out;
}


template<typename T, xsize N>
ostream& operator<<(ostream& out, const Vector<T,N>& vec) {
    return operator<<(out, *((Matrix<T,1,N> *) (&vec)));
}


namespace X {

    // binary output data
    template<typename T, xsize ROWS, xsize COLS>
        void writeBinary(const char *filename, const Matrix<T,ROWS,COLS>& mtx) {
            ofstream myFile;
            myFile.open(filename, ios::out | ios::binary);
            myFile.write((char *)mtx.getPtr(), (ROWS * COLS) * sizeof(T));
            myFile.close();
        }


    template<typename T, xsize N>
        void writeBinary(const char *filename, const Vector<T,N>& mtx) {
            writeBinary( *((const Matrix<T,1,N> *) (&mtx)), filename);
        }

    // binary read data
    template<typename T, xsize ROWS, xsize COLS>
        void readBinary(const char *filename, const Matrix<T,ROWS,COLS>& mtx) {
            ofstream myFile;
            myFile.open(filename, ios::out | ios::binary);
            myFile.write((char *)mtx.getPtr(), (ROWS * COLS) * sizeof(T));
            myFile.close();
        }



}
#endif
#endif
