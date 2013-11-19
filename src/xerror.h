#ifndef X_ERROR_H_X
#define X_ERROR_H_X
#include <iostream>

using namespace std;

namespace X {

    class XError {
        public:
            static void err(const char *str) {
                cerr << str << endl << flush;
                throw 1;
            }
    };
}


#endif
