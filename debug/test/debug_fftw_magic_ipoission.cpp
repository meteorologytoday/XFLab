#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


#define X_INCLUDE_IOSTREAM
#define X_INCLUDE_DIM2
#define X_INCLUDE_FFTW
#define X_FFTW_MAGIC_DOUBLE
#include "xdmlab.h"

using namespace X;
using namespace X::FFTW;
using namespace std;

typedef double T;

const x_size D0 = 5;
const x_size D1 = 3;

void printr(T * nums, x_size n0, x_size n1);
void printc(fftw_complex * nums, x_size n0, x_size n1);

int main() {

    cout << "Program start" << endl << flush;
    Vector<T,D0> x;
    Vector<T,D1> y;
    
    Grid2<T,D0,D1> xxyy;
    Util::setMeshgrid2(xxyy,x,y);

    cout << "Allocating field..." << endl << flush;
    Field2<T,D0,D1,1> field(xxyy);

    cout << "Allocated" << endl << flush;
    
    T L0 = M_PI * 2;
    T L1 = M_PI * 2;
    
    T *in = field[0].getPtr();

    fftw_plan p_sink, p_rise;
    fftw_complex *out = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);

    T step0 = (2 * M_PI) / D0;
    T step1 = (2 * M_PI) / D1;
    
    cout << "setting field" << endl << flush;
    for(x_size i=0; i < D0; ++i) {
        for(x_size j=0; j < D1; ++j) {
           field(0,i,j) = sin(i*step0);// * sin(j*step1);
        }
    }
    
    cout << "field set, printing..." << endl << flush;
    cout << field;
    
    p_sink = fftw_plan_dft_r2c_2d(D0, D1, in, out, FFTW_ESTIMATE);
    p_rise = fftw_plan_dft_c2r_2d(D0, D1, out, in, FFTW_ESTIMATE);
    
    fftw_execute(p_sink); /* repeat as needed */
    cout << "print wave table" << endl;
    printc(out, D0, D1);
    ipoission(out, out, D0, D1, 2*M_PI, 2*M_PI);
    cout << "print ipoission wave table" << endl;
    printc(out, D0, D1);

    fftw_execute(p_rise); 
    cout << "print final result" << endl;
    field[0].divBy(D0 * D1);
    cout << field;
    
    fftw_destroy_plan(p_rise);
    fftw_destroy_plan(p_sink);
    fftw_free(out);
    return 0;
}


void printr(T *nums, x_size n0, x_size n1) {
    x_size offset = 0;
    for(x_size i=0; i < n0; ++i) {
        for(x_size j=0; j < n1; ++j) {
            printf("%5.3f, ", nums[offset]);
            ++offset;
        }
        printf("\n");
    }


}
void printc(fftw_complex * nums, x_size n0, x_size n1) {
    n1 = (x_size) (n1/2 + 1);
    x_size offset = 0;
    for(x_size i=0; i < n0; ++i) {
        for(x_size j=0; j < n1; ++j) {
            printf("[%d,%d] %5.3f %+5.3fi, ",i,j, nums[offset][0], nums[offset][1]);
            ++offset;
        }
        printf("\n");
    }


}
