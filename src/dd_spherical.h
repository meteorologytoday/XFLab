#ifndef X_DD_SPHERICAL_H_X
#define X_DD_SPHERICAL_H_X

#include "data_index_2.h"

namespace X {
    namespace DDSPHERICAL {
        template <typename T, xsize N1, xsize N2>
            class ddSphericalDescriptor {
                public:
                    T r;
                    DataIndex1<T, N2>   dx;
                    T dy;

                    DataIndex1<T,N1> phi;
                    DataIndex1<T,N2> theta;

                public:
                    ddSphericalDescriptor(T r);
                    void setup();
            };


        template <typename T, xsize N1, xsize N2>
            class ddSphericalTool {
                public:
                    static void gradient_xy(ddSphericalDescriptor<T,N1,N2>&, DataIndex2<T,N1,N2>& in, DataIndex2<T,N1,N2>& out_x, DataIndex2<T,N1,N2>& out_y);
                    static void laplacian(ddSphericalDescriptor<T,N1,N2>&, DataIndex2<T,N1,N2>& in, DataIndex2<T,N1,N2>& out);
    
            };
    }
}

#include "dd_spherical.cpp"

#endif
