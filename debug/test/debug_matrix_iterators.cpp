#include "matrix.h"
#include <iostream>

using namespace X;
using namespace std;

void say(int);

int main() {
    Matrix<int> nums();
    nums << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
    
    nums.each(say);
    
    
    return 1;
}

void say(int num) {
    cout << num << endl;
}
