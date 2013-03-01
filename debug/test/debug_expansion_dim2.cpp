#define X_INCLUDE_IOSTREAM
#define X_INCLUDE_DIM2
#include "xdmlab.h"
#include <iostream>

using namespace std;
using namespace X;

typedef float T;
const x_size D = 2;
const x_size P1 = 3;
const x_size P2 = 5;
const x_size N = 2;


int main() {

    
    Field2<T,P1,P2,N> f2;
    f2[0] << 1,2,3,4,5,6,7;
    f2[1] << 10,20;

    cout << f2[0] << endl;
    

    return 0;
}
