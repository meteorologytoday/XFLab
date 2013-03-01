#include <fftw3.h>
#include <iostream>
#include <cmath>

#define PI 3.1415925
using namespace std;

int main() {
    int N = 100;
    double L = 100;
    double *in;
    fftw_complex *out;
    fftw_plan p;
    in = (double*) fftw_malloc(sizeof(double) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    double step = (2*PI) / N;
    for(int i=0; i < N; ++i) {
        in[i] = sin(i*step);
    }

    p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

    fftw_execute(p); /* repeat as needed */
    
/*    for(int i=0; i < N; ++i) {
        cout << "[" << i << "] : " << in[i] << endl;
    }


    for(int i=0; i < N; ++i) {
        cout << "[" << i << "] : " << out[i][0] << " + " << out[i][1] << "i" << endl;
    }
*/


    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);
    return 0;
}
