#include <iostream>
#include "vector.h"
#include "field2.h"
#include "grid2.h"
#include "gridtool.h"

#define D1 3
#define D2 5
#define GT int
#define DT float

using namespace X;
using namespace std;

int main() {

    Vector<GT,D1> x;
    Vector<GT,D2> y;
    Grid2<GT,D1,D2> xxyy;

    GridTool::setMeshgrid2(xxyy,x,y);
    Field2<DT,GT,2,D1,D2> field(&xxyy);

    field << 1,2,3,4,5,6,7,8,9,10,11,12;
    field.setFocus(1);
    field << 101,102,103;
    cout <<  field << endl;

    return 0;
}
