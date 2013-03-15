
#ifndef X_OFFSET_H
#define X_OFFSET_H

namespace X {


    inline xsize OFFSET2(xsize rows, xsize cols, xsize i, xsize j) {
        return i * cols + j;
    }



}

#include "offset.cpp"


#endif
