
#ifdef X_DIM2_IOSTREAM_H
#ifndef X_DIM2_IOSTREAM_CPP
#define X_DIM2_IOSTREAM_CPP

template<typename T, X::xsize P, X::xsize N>
std::ostream& operator<<(std::ostream& out, X::Field2D<T,P,N>& field) {

    T *data;
    for(X::xsize k = 0; k < N; ++k) {
        data = field[k].getPtr();
        if(k != 0) { out << endl; }
        out << '[';
            for(X::xsize i = 0; i < P1; ++i) {
                if(i!=0) { out << ','; }
                out << data[i];
            }
        }
        out << ']' << endl;
    }

    return out;
}
#endif
#endif
