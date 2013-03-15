
#ifdef X_DIM2_IOSTREAM_H
#ifndef X_DIM2_IOSTREAM_CPP
#define X_DIM2_IOSTREAM_CPP

template<typename T, X::xsize P1, X::xsize P2, X::xsize N>
std::ostream& operator<<(std::ostream& out, X::Field2<T,P1,P2,N>& field) {

    T *data;
    for(X::xsize k = 0; k < N; ++k) {
        data = field[k].getPtr();
        if(k != 0) { out << endl; }
        out << '[';
        for(X::xsize i = 0; i < P1; ++i) {
            if(i != 0) { out << ';' << endl; }
            for(X::xsize j = 0; j < P2; ++j) {
                if(j!=0) { out << ','; }
                out << data[X::OFFSET2(P1,P2,i,j)] << "("<< X::OFFSET2(P1,P2,i,j) << ")";
            }
        }
        out << ']';
    }

    return out;
}
#endif
#endif
