#include <fftw3.h>
#include "typedef.h"
#include "offset.h"

#ifndef X_FFTW_MAGIC_H
#define X_FFTW_MAGIC_H

namespace X {
    namespace FFTW {



#ifdef X_FFTW_MAGIC_FLOAT

#define FFTW(func) fftwf_##func
        typedef float FFTW_REAL;
        typedef fftwf_complex FFTW_COMPLEX;

#else

#define FFTW(func) fftw_##func
        typedef double FFTW_REAL;
        typedef fftw_complex FFTW_COMPLEX;

#endif
        void* fftw_malloc_wave_table2(x_size D0, x_size D1);
        template <typename T> void diff2(x_size dir, int order, FFTW_COMPLEX *in, FFTW_COMPLEX *out, x_size D0, x_size D1, T L0, T L1);

        template <typename T> void ipoisson(FFTW_COMPLEX *in, FFTW_COMPLEX *out, x_size D0, x_size D1, T L0, T L1);
        template <typename T> void laplacian(FFTW_COMPLEX *in, FFTW_COMPLEX *out, x_size D0, x_size D1, T L0, T L1);

    }
}

#include "fftw_magic.cpp"

#endif


