#ifndef X_ENUMERATOR_H
#define X_ENUMERATOR_H

namespace X {

    template <xsize P1>
        class Enumerator1 {

            public: // iterator
                template <typename Fn> void each_index(Fn f) const {
                    for(xsize i = 0 ; i < P1; ++i) {
                        f(i);
                    }
                }

        };

    template <xsize P1, xsize P2>
        class Enumerator2 {
            public: // iterator
                template <typename Fn> void each_index(Fn f) const {
                    for(xsize i = 0 ; i < P1; ++i) {
                        for(xsize j = 0; j < P2; ++j) {
                            f(i,j);
                        }
                    }
                }
        };
}

#endif
