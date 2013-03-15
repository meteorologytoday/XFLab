#include <fftw3.h>
#include "typedef.h"
#include "offset.h"

#ifndef X_FFTW_MAGIC_H
#define X_FFTW_MAGIC_H

namespace X {

#ifdef X_FFTW_MAGIC_FLOAT

#define FFTW(func) fftwf_##func
        typedef float FFTW_REAL;
        typedef fftwf_complex FFTW_COMPLEX;

#else

#define FFTW(func) fftw_##func
        typedef double FFTW_REAL;
        typedef fftw_complex FFTW_COMPLEX;

#endif
 
    

#define M_PII (2*M_PI)

#define fftw_ccmul(z,x,y) (z)[0] = (x)[0] * (y)[0] - (x)[1] * (y)[1]; (z)[1] = (x)[0] * (y)[1] + (x)[1] * (y)[0];
#define fftw_rcmul(z,r,c) (z)[0] = r * (c)[0]; (z)[1] = r * (c)[1];

#define fftw_ccadd(z,x,y) (z)[0] = (x)[0] + (y)[0]; (z)[1] = (x)[1] + (y)[1];
#define fftw_ccsub(z,x,y) (z)[0] = (x)[0] - (y)[0]; (z)[1] = (x)[1] - (y)[1];


    namespace FFTW {

       // inline functions 
        inline void* fftw_malloc_wave_table(xsize D0, xsize D1) { return FFTW(malloc)(sizeof(FFTW_COMPLEX) * D0 * ((xsize) (D1/2)+1)); }
        constexpr inline xsize fftw_wave_table_size(xsize D0, xsize D1) { return  D0 * ((xsize) (D1/2)+1); }
        inline void setComplex(FFTW_COMPLEX& x, FFTW_REAL a, FFTW_REAL b) {x[0] = a; x[1] = b;}
        inline void setComplex(FFTW_COMPLEX& x, FFTW_COMPLEX& y) {x[0] = y[0]; x[1] = y[1];}

        // for even , kreal = -Nx/2 + (k - Nx/2) = -Nx + k 
        // for odd  , kreal = -(Nx-1)/2 + k - ((Nx-1)/2 + 1) = -Nx + k
        inline FFTW_REAL mapWavenumber(xsize dim, xsize i) { return (i <= (xsize)(dim/2)) ? static_cast<FFTW_REAL>(i) : static_cast<FFTW_REAL>(i) - dim ; }



        template <typename T> void diff2(xsize dir, int order, FFTW_COMPLEX *in, FFTW_COMPLEX *out, xsize D0, xsize D1, T L0, T L1);
        template <typename T> void ipoisson(FFTW_COMPLEX *in, FFTW_COMPLEX *out, xsize D0, xsize D1, T L0, T L1);
        template <typename T> void laplacian(FFTW_COMPLEX *in, FFTW_COMPLEX *out, xsize D0, xsize D1, T L0, T L1);

    }
}
/*
// operator overloading
inline X::FFTW_COMPLEX& operator*(X::FFTW_COMPLEX& x, X::FFTW_COMPLEX& y) {
    X::FFTW_COMPLEX z = {x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]};
    return z;
}

inline void operator*=(X::FFTW_COMPLEX& x, X::FFTW_COMPLEX& y) {
    x[0] = x[0]*y[0] - x[1]*y[1];
    x[1] = x[0]*y[1] + x[1]*y[0];
}

inline X::FFTW_COMPLEX& operator+(X::FFTW_COMPLEX& x, X::FFTW_COMPLEX& y) {
    X::FFTW_COMPLEX z = {x[0] + y[0], x[1] + y[1]};
    return z;
}

inline void operator+=(X::FFTW_COMPLEX& x, X::FFTW_COMPLEX& y) {
    x[0] += y[0];
    x[1] += y[1];
}

inline X::FFTW_COMPLEX& operator-(X::FFTW_COMPLEX& x, X::FFTW_COMPLEX& y) {
    X::FFTW_COMPLEX z = {x[0] - y[0], x[1] - y[1]};
    return z;
}

inline void operator-=(X::FFTW_COMPLEX& x, X::FFTW_COMPLEX& y) {
    x[0] -= y[0];
    x[1] -= y[1];
}
*/
#include "fftw_magic.cpp"


#undef M_PII
#endif


