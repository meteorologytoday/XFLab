#ifndef X_XCOMPLEX_H
#define X_XCOMPLEX_H

namespace X {
    template <typename T>
    class xComplex {
        T dat[2];

        xComplex() {dat[0]=0; dat[1]=0;}
        xComplex(T re, T im) {dat[0]=re; dat[1] = im;}
        ~xComplex() {}

        inline xComplex operator+(const xComplex& b) {
            return xComplex(b.dat[0]+this->dat[0], b.dat[1]+this->dat[1]);
        }

        inline xComplex operator-(const xComplex& b) {
            return xComplex(this->dat[0] - b.dat[0], this->dat[1] - b.dat[1]);
        }

        inline xComplex operator*(const xComplex& b) {
            return xComplex(this->dat[0] * b.dat[0] - this->dat[1] * b.dat[1], this->dat[1] * b.dat[0] + this->dat[0] * b.dat[1]);
        }

        inline xComplex operator/(const xComplex& b) {
            return xComplex(this->dat[0] * b.dat[0] - this->dat[1] * b.dat[1], this->dat[1] * b.dat[0] + this->dat[0] * b.dat[1]);
        }

    };
}

#endif
