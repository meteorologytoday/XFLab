
#ifndef X_OFFSET_H
#define X_OFFSET_H

namespace X {


    inline xsize OFFSET2(xsize n1, xsize n2, xsize i, xsize j) {
        return i * n2 + j;
    }

    inline xsize OFFSET3(xsize n1, xsize n2, xsize n3, xsize i, xsize j, xsize k) {
        return i * n2 * n3 + j * n3 + k;
    }

}

#include "offset.cpp"


#endif
