#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "vector.h"
#include "field2.h"
#include "grid2.h"
#include "gridtool.h"

#define X_FFTW_MAGIC_DOUBLE
#include "fftw_magic.h"

#define D0 5
#define D1 3
#define GT int
#define DT double

using namespace X;
using namespace X::FFTW;
using namespace std;


void printr(DT * nums, size_x n0, size_x n1);
void printc(fftw_complex * nums, size_x n0, size_x n1);

int main() {

    Vector<GT,D0> x;
    Vector<GT,D1> y;
    Vector<GT,2> domain;
    domain << 10,20;
    
    Grid2<GT,D0,D1> xxyy;
    GridTool::setMeshgrid2(xxyy,x,y);

    Field2<DT,GT,1,D0,D1> field(&xxyy);

    GT L0 = 100;
    GT L1 = 100;
    DT *in = field.getData(0);

    fftw_plan p;
    fftw_complex *out = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);

    double step0 = (2*M_PI) / D0;
    double step1 = (2*M_PI) / D1;
    field.setFocus(0);
    for(size_x i=0; i < D0; ++i) {
        for(size_x j=0; j < D1; ++j) {
           field(i,j) = sin(i*step0);// * sin(j*step1);
        }
    }
    cout << field;
    //p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    p = fftw_plan_dft_r2c_2d(D0, D1, field.getData(0), out, FFTW_ESTIMATE);
    fftw_execute(p); /* repeat as needed */
    cout << "print wave table" << endl;
    printc(out, D0, D1);
    ipossion(0, 2, out, out, D0, D1, 2*M_PI, 2*M_PI);
    cout << "print diff wave table" << endl;
    printc(out, D0, D1);

    fftw_destroy_plan(p);
    p = fftw_plan_dft_c2r_2d(D0, D1, out, field.getData(0), FFTW_ESTIMATE);
    fftw_execute(p); 
    cout << "print final result" << endl;
    field.divBy(D0 * D1);
    cout << field;
    
    fftw_destroy_plan(p);
    fftw_free(out);
    return 0;
}


void printr(DT *nums, size_x n0, size_x n1) {
    size_x offset = 0;
    for(size_x i=0; i < n0; ++i) {
        for(size_x j=0; j < n1; ++j) {
            printf("%5.3f, ", nums[offset]);
            ++offset;
        }
        printf("\n");
    }


}
void printc(fftw_complex * nums, size_x n0, size_x n1) {
    n1 = (size_x) (n1/2 + 1);
    size_x offset = 0;
    for(size_x i=0; i < n0; ++i) {
        for(size_x j=0; j < n1; ++j) {
            printf("[%d,%d] %5.3f %+5.3fi, ",i,j, nums[offset][0], nums[offset][1]);
            ++offset;
        }
        printf("\n");
    }


}

#undef D0
#undef D1 
#undef GT 
#undef DT
