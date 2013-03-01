
#ifdef X_DIM2_IOSTREAM_H
#ifndef X_DIM2_IOSTREAM_CPP
#define X_DIM2_IOSTREAM_CPP

template<typename T, X::x_size P1, X::x_size P2, X::x_size N>
std::ostream& operator<<(std::ostream& out, X::Field2<T,P1,P2,N>& field) {

    T *data;
    for(X::x_size k = 0; k < N; ++k) {
        data = field[k].getPtr();
        if(k != 0) { out << endl; }
        out << '[';
        for(X::x_size i = 0; i < P1; ++i) {
            if(i != 0) { out << ';' << endl; }
            for(X::x_size j = 0; j < P2; ++j) {
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
