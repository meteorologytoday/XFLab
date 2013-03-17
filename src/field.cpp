#ifdef X_FIELD_H
#ifndef X_FIELD_CPP
#define X_FIELD_CPP

namespace X {

    template <typename DT, typename GT, xsize P, xsize N>
        Field<DT,GT,P,N>::Field() {
            data = new DT*[N]();
            for(xsize i=0; i < N; ++i) {
                data[i] = new DT();
            }
            grid = new GT();
        }

    template <typename DT, typename GT, xsize P, xsize N>
         Field<DT,GT,P,N>::~Field() {
            delete grid;

            for(xsize i=0; i < N; ++i) {
                delete data[i];
            }
 
            delete [] data;
        }
}

#endif
#endif
