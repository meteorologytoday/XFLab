
// basic
#include "typedef.h"
#include "complex.h"
#include "offset.h"
#include "matrix.h"
#include "vector.h"
#include "grid.h"
#include "field.h"
#include "util.h"

#ifdef X_INCLUDE_IOSTREAM
#include "basic_iostream.h"
#endif

#ifdef X_INCLUDE_DIM2
// dimension 2 expansion
#include "grid2.h"
#include "field2.h"

#ifdef X_INCLUDE_IOSTREAM
#include "dim2_iostream.h"
#endif

#endif

#ifdef X_INCLUDE_FFTW
// fftw expansion
#include "fftw_magic.h"
#endif
