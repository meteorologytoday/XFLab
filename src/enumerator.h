#ifndef X_ENUMERATOR_H
#define X_ENUMERATOR_H

namespace X {

    template <xsize P1>
        class Enumerator1 {

            public: // iterator
                template <typename Fn> static void each_index(Fn f) {
                    for(xsize i = 0 ; i < P1; ++i) {
                        f(i);
                    }
                }

        };

    template <xsize P1, xsize P2>
        class Enumerator2 {
            public: // iterator
                template <typename Fn> static void each_index(Fn f) {
                    for(xsize i = 0 ; i < P1; ++i) {
                        for(xsize j = 0; j < P2; ++j) {
                            f(i,j);
                        }
                    }
                }
        };


    template <xsize P1, xsize P2, xsize P3>
        class Enumerator3 {
            public: // iterator
                template <typename Fn> static void each_index(Fn f) {
                    for(xsize i = 0 ; i < P1; ++i) {
                        for(xsize j = 0; j < P2; ++j) {
                            for(xsize k = 0; k < P3; ++k) {
                                f(i,j,k);
                            }
                        }
                    }
                }
        };
}

#endif
