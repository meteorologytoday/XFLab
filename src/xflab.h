
// c lib
#define _USE_MATH_DEFINES
#include <cmath>

// basic
#include "typedef.h"
#include "xerror.h"
#include "xcomplex.h"
#include "offset.h"
#include "field.h"
#include "dataset.h"
#include "util.h"
#include "enumerator.h"
#include "data_index_1.h"
#include "data_index_2.h"
#include "data_index_3.h"
#include "dd_spherical.h"


#ifdef X_INCLUDE_IO
#include "io.h"
#endif

#ifdef X_INCLUDE_FFTW
// fftw expansion
#include "fftw/fftw_magic.h"
#endif

#ifdef X_INCLUDE_GNUPLOT
// gnuplot expansion
#include "gnuplot_magic.h"
#endif

#ifdef X_INCLUDE_EDC
// effectiv diffusivity coefficient tool
#include "edc.cpp"
#endif
