#ifdef X_FIELD2_H
#ifndef X_FIELD2_OPERATORS_CPP
#define X_FIELD2_OPERATORS_CPP
namespace X {
    template <typename DT, typename GT, x_size N, x_size D1, x_size D2> 
        Field2<DT,GT,N,D1,D2>& Field2<DT,GT,N,D1,D2>::operator<<(DT value) {
            Matrix<DT,N,D1*D2>::operator<<(value);
            ++(this->offset);
            return *this;
        }


    template <typename DT, typename GT, x_size N, x_size D1, x_size D2> 
        DT& Field2<DT,GT,N,D1,D2>::operator()(x_size i, x_size j) {
            return Matrix<DT,N,D1*D2>::operator()(OFFSET(N,D1*D2,this->getFocus(), OFFSET(D1,D2,i,j)));
        }
    
    template <typename DT, typename GT, x_size N, x_size D1, x_size D2> 
        DT& Field2<DT,GT,N,D1,D2>::operator()(x_size k, x_size i, x_size j) {
            return Matrix<DT,N,D1*D2>::operator()(OFFSET(N,D1*D2, k, OFFSET(D1,D2,i,j)));
        }

}

#endif
#endif
