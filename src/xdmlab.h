
// basic
#include "typedef.h"
#include "xcomplex.h"
#include "offset.h"
//#include "matrix.h"
//#include "vector.h"
#include "field.h"
#include "dataset.h"
#include "util.h"
#include "enumerator.h"
#include "data_index_1.h"
#include "data_index_2.h"

#ifdef X_INCLUDE_IO
#include "io.h"
#endif
/*
#ifdef X_INCLUDE_DIM2
// dimension 2 expansion
#include "field2d.h"
#include "field2dindex2.h"

#ifdef X_INCLUDE_IO
#include "dim2_io.h"
#endif

#endif
*/
#ifdef X_INCLUDE_FFTW
// fftw expansion
#include "fftw_magic.h"
#endif

#ifdef X_INCLUDE_GNUPLOT
// gnuplot expansion
#include "gnuplot_magic.h"
#endif

#ifdef X_INCLUDE_EDC
// effectiv diffusivity coefficient tool
#include "edc.cpp"
#endif
