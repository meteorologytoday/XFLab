#include <iostream>

#ifndef TESTHEADER_H
#define TESTHEADER_H

namespace TEST {

    typedef unsigned int XXX;

    template<XXX x>
        class Test {

        public:
            void print();
    };
}

template <TEST::XXX x>
std::ostream& operator<<(std::ostream& os, const TEST::Test<x>& test) {
        os << x;

        return os;
}


#include "testheader2.cpp"
#endif
