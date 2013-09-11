#ifndef X_GNUPLOT_MAGIC_H
#define X_GNUPLOT_MAGIC_H

#include "typedef.h"
#include <fstream>

namespace X {
    namespace GNUPLOT {
        template <typename T>
            void output_field(const char *filename, T *field, T *x, T *y, xsize n0, xsize n1);
        
	template <typename T>
            void output_field_record(const char *filename, T *field, xsize n0, xsize n1);
    }
}

#include "gnuplot_magic.cpp"

#endif
