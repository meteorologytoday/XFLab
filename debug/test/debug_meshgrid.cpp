#include "gridtool.h"
#include "vector.h"
#include "grid2.h"
#include "matrix.h"
#include <iostream>
using namespace std;
using namespace X;
int main() {
    Vector<int,5> x;
    Vector<int,5> y;
    x.resetOffset();
    x << 1,2,3,4,5;
    y << 10,20,30,40,50;

    cout << x << endl;

    Grid2<int,5,5> xxyy;
    GridTool::setMeshgrid2(xxyy, x, y);
    cout << xxyy << endl;

    return 0;
}
