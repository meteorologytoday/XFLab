#include <fftw3.h>
#include <iostream>
#include <cmath>
#include <cstdio>

#define PI 3.1415925
#define OFFSET(r,c,i,j) ((i)*(c)+(j))

using namespace std;

void print_real(int,int,double*);
void print_cmplx(int,int,fftw_complex*);
int main() {
    int n0 = 756;
    int n1 = 756;
    int cn0 = n0;
    int cn1 = (int)(n1/2 + 1);
    double L = 100;
    double *in;
    fftw_complex *out;
    fftw_plan p;
    in = (double*) fftw_malloc(sizeof(double) * n0 * n1);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * cn0 * cn1);

    double step0 = (2*PI) / n0;
    double step1 = (2*PI) / n1;

    for(int i=0; i < n0; ++i) {
        for(int j=0; j < n1; ++j) {
            in[OFFSET(n0,n1,i,j)] = sin(i*step0) * sin(j*step1);
        }
    }

    //p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    p = fftw_plan_dft_r2c_2d(n0, n1, in, out, FFTW_ESTIMATE);

    fftw_execute(p); /* repeat as needed */

//    print_real(n0,n1,in);
//    print_cmplx(cn0,cn1,out);


    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);
    return 0;
}

void print_real(int n0, int n1, double *p) {
    for(int i=0; i < n0; ++i) {
        for(int j=0; j < n1; ++j) {

            printf("%5f ", p[OFFSET(n0,n1,i,j)]);
        }
        printf("\n");
    }
}



void print_cmplx(int n0, int n1, fftw_complex *p) {

    for(int i=0; i < n0; ++i) {
        for(int j=0; j < n1; ++j) {

            printf("%5f + %5fi ; ", p[OFFSET(n0,n1,i,j)][0], p[OFFSET(n0,n1,i,j)][1]);
        }
        printf("\n");
    }
}
