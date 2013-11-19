#ifndef X_TYPEDEF_H
#define X_TYPEDEF_H

#ifndef NULL
#define NULL 0
#endif

namespace X {

    // Define real number type
    typedef unsigned int xsize;
    typedef float xrealf;
    typedef double xreald;
    typedef int xreali;
    typedef short xreals;

    // Define complex number type
    typedef double xcomplexd[2];
    typedef float  xcomplexf[2];


}


#endif
