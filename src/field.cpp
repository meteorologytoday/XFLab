#ifdef X_FIELD_H
#ifndef X_FIELD_CPP
#define X_FIELD_CPP

namespace X {


    template <typename T, xsize D, xsize P, xsize N>
        void Field<T,D,P,N>::DefaultConstructor() {
            grid = NULL;
            raw_data = new T[P*N]();
            vec = new Vector<T,P>*[N]();
            
            for(xsize i=0; i < N; ++i) {
                vec[i] = new Vector<T,P>(raw_data + i*P);
            }

        }

    template <typename T, xsize D, xsize P, xsize N>
        Field<T,D,P,N>::Field() {
            this->DefaultConstructor();
        }

    template <typename T, xsize D, xsize P, xsize N>
        Field<T,D,P,N>::Field(Matrix<T,D,P>& grid) {
            this->DefaultConstructor();
            this->setMatrix(grid);
        }

   
    // Operator part

    template <typename T, xsize D, xsize P, xsize N>
        Field<T,D,P,N>::~Field() {

            for(xsize i=0; i < N; ++i) {
                delete vec[i];
            }
            delete [] this->vec;
            delete [] this->raw_data;
            if(this->grid != NULL) { delete this->grid; this->grid = NULL;}

        }

    template <typename T, xsize D, xsize P, xsize N>
       void Field<T,D,P,N>::setMatrix(Grid<T,D,P>& grid) {
           if(this->grid == NULL) 
               this->grid = new Matrix<T,D,P>();

           this->grid->copyFrom(grid);
        }
 
    template <typename T, xsize D, xsize P, xsize N>
       Matrix<T,D,P>* Field<T,D,P,N>::getGrid() {
           if(this->grid == NULL) 
               this->grid = new Matrix<T,D,P>();

           return this->grid;
        }   

    template <typename T, xsize D, xsize P, xsize N>
        Vector<T,P>& Field<T,D,P,N>::operator[](xsize i) {
            return *vec[i];
        }

    template <typename T, xsize D, xsize P, xsize N>
        T& Field<T,D,P,N>::operator()(xsize i, xsize offset) {
            return vec[i]->operator()(0,offset);
        }





}

#endif
#endif
