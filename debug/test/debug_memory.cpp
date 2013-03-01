#include "memory.h"
#include <iostream>
using namespace X;
int main() {
    int *nums = (int*) Memory::memory_alloc(sizeof(int) * 10);
    nums[0] = 10;
    cout << nums[0] << endl;    
    Memory::memory_free_all();
    cout << nums[0] << endl;
    return 1;
}
