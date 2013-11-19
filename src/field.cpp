#ifdef X_FIELD_H
#ifndef X_FIELD_CPP
#define X_FIELD_CPP

namespace X {

    template <typename DT, typename GT, xsize P, xsize N>
        Field<DT,GT,P,N>::Field() : Dataset<DT,N>() {
            grid = new GT();
        }

    template <typename DT, typename GT, xsize P, xsize N>
         Field<DT,GT,P,N>::~Field() {
            delete grid;
        }
}

#endif
#endif
