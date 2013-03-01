#ifdef X_FIELD_H
#ifndef X_FIELD_CPP
#define X_FIELD_CPP

namespace X {


    template <typename T, x_size D, x_size P, x_size N>
        void Field<T,D,P,N>::DefaultConstructor() {

            grid = new Grid<T,D,P>();

            raw_data = new T[P]();

            vec = new Vector<T,P>*[N]();
            for(x_size i=0; i < N; ++i) {
                vec[i] = new Vector<T,P>(i*P);
            }

        }

    template <typename T, x_size D, x_size P, x_size N>
        Field<T,D,P,N>::Field() {
            this->DefaultConstructor();
        }

    template <typename T, x_size D, x_size P, x_size N>
        Field<T,D,P,N>::Field(Grid<T,D,P>& grid) {
            this->DefaultConstructor();
            this->setGrid(grid);
        }

   
    // Operator part

    template <typename T, x_size D, x_size P, x_size N>
        Field<T,D,P,N>::~Field() {

            for(x_size i=0; i < N; ++i) {
                delete vec[i];
            }
            delete [] vec;
            delete [] this->raw_data;
            delete this->grid;

        }

    template <typename T, x_size D, x_size P, x_size N>
       void Field<T,D,P,N>::setGrid(Grid<T,D,P>& grid) {
           this->grid->copyFrom(grid);
        }
    
    template <typename T, x_size D, x_size P, x_size N>
        Vector<T,P>& Field<T,D,P,N>::operator[](x_size i) {
            return *vec[i];
        }

    template <typename T, x_size D, x_size P, x_size N>
        T& Field<T,D,P,N>::operator()(x_size i, x_size offset) {
            return vec[i]->operator()(0,offset);
        }

}

#endif
#endif
