#define X_OPT_MATRIX_IOSTREAM
#include "matrix.h"
#include <iostream>

using namespace std;
int main() {
    X::Matrix<int, 2, 2> mtxA;
        
    mtxA << 1,2,3,4;
/*    cout << mtxA(0,0) << mtxA(0,1) << mtxA(1,0) << mtxA(1,1) << endl;
    mtxA(3) = 1000;
    cout << mtxA(0,0) << mtxA(0,1) << mtxA(1,0) << mtxA(1,1) << endl;

    mtxA.mulBy(mtxA);
    cout << mtxA(0,0) << mtxA(0,1) << mtxA(1,0) << mtxA(1,1) << endl;
*/    
    cout << mtxA << endl;
    return 0;
}
