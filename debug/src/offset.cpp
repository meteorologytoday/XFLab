#ifdef X_OFFSET_H
#ifndef X_OFFSET_CPP
#define X_OFFSET_CPP

namespace X {

    x_size OFFSET2(x_size rows, x_size cols, x_size i, x_size j) {
        return i * cols + j;
    }


}

#endif
#endif
