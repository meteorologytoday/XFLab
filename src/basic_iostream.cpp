
#ifdef X_BASIC_IOSTREAM_H
#ifndef X_BASIC_IOSTREAM_CPP
#define X_BASIC_IOSTREAM_CPP

template<typename T, X::x_size ROWS, X::x_size COLS>
std::ostream& operator<<(std::ostream& out, const X::Matrix<T,ROWS,COLS>& mtx) {

    const T *data = mtx.getPtr();
    out << '[';
    for(X::x_size i = 0; i < ROWS; ++i) {
        if(i != 0) { out << ';' << std::endl; }
        for(X::x_size j = 0; j < COLS; ++j) {
            if(j!=0) { out << ','; }
            out << data[X::OFFSET2(ROWS,COLS,i,j)];
        }
    }

    out << ']'; 
    return out;
}


template<typename T, X::x_size N>
std::ostream& operator<<(std::ostream& out, const X::Vector<T,N>& vec) {
    return operator<<(out, *((X::Matrix<T,1,N> *) (&vec)));
}



#endif
#endif
