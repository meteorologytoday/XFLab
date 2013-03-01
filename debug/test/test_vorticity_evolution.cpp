#define _USE_MATH_DEFINES
#include <cmath>

#include <fstream>
#include <iostream>

#include <string>
#include <sstream>

#define X_INCLUDE_IOSTREAM
#define X_INCLUDE_DIM2
#define X_INCLUDE_FFTW
#define X_FFTW_MAGIC_DOUBLE
#include "xdmlab.h"

typedef double T;

using namespace X;
using namespace X::FFTW;
using namespace std;


const x_size DATASIZE = 8;
enum DATA { vort = 0, vortgdx, vortgdy, u, v, vortlap, vortm, vortp};
enum RK4{k1 = 0, k2, k3, k4};

const T nu = 50;
const x_size D0 = 128;
const x_size D1 = 128;
const double delta_t = 50;
const double time_filter = 0.01;
const x_size total_time = 3600 * 20;
const x_size final_timestep = (x_size) (total_time/delta_t);
const x_size recording_timestep = 20;


void output_field(const char *filename, T *field, T *x, T *y, x_size n0, x_size n1);
void printr(T * nums, x_size n0, x_size n1);
void printc(fftw_complex * nums, x_size n0, x_size n1);

int main() {
    cout << vort << "," << vortgdx << "," << vortgdy << endl;
    cout << "# Program start" << endl << flush;
    T L0 = 400000;
    T L1 = 400000;


    Vector<T,D0> x;
    Vector<T,D1> y;

    cout << "Allocating matrix..." << endl << flush;

    Grid2<T,D0,D1> xxyy;
    Util::linspace2(x, (T) 0, L0);
    Util::linspace2(y, (T) 0, L1);

    cout << x << endl;
    cout << "Set meshgrid..." << endl << flush;
    Util::setMeshgrid2(xxyy,x,y);

    cout << "Meshgrid set." << endl << flush;
    Field2<T,D0,D1,DATASIZE> f(xxyy);

    fftw_plan vort_sink;
    fftw_plan vortgdx_rise,
              vortgdy_rise,
              u_rise,
              v_rise,
              vortlap_rise;

    cout << "Allocating wavetable..." << endl << flush;
    fftw_complex *w_vort = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);
    fftw_complex *w_stream = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);
    fftw_complex *w_u = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);
    fftw_complex *w_v = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);
    fftw_complex *w_vortgdx = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);
    fftw_complex *w_vortgdy = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);
    fftw_complex *w_vortlap = (fftw_complex*) fftw_malloc_wave_table2(D0,D1);

    T step0 = (2 * M_PI) / D0;
    T step1 = (2 * M_PI) / D1;

    cout << "Setting vorticity..." << endl << flush;

    for(x_size i=0; i < D0; ++i) {
        for(x_size j=0; j < D1; ++j) {
            f(vort,i,j) = sin(i*2*step0) * sin(j*2*step1) * 0.0001 
                + 0.0008 * exp( - (pow(xxyy(0,i,j) - L0/2 ,2) + pow(xxyy(1,i,j) - L1/2 ,2)) / (2*pow(50000.0,2)))
                + 0.0005 * exp( - (pow(xxyy(0,i,j) - L0/2 + 150000 ,2) + pow(xxyy(1,i,j) - L1/2 ,2)) / (2*pow(50000.0,2)));
        }
    }
    string filename("init_vort");
    output_field(filename.c_str(), f[vort].getPtr(), x.getPtr(), y.getPtr(), D0, D1);


    cout << "Making fftw plans..." << endl << flush;
    vort_sink =     fftw_plan_dft_r2c_2d(D0, D1, f[vort].getPtr(),  w_vort, FFTW_ESTIMATE);
    vortgdx_rise =  fftw_plan_dft_c2r_2d(D0, D1, w_vortgdx, f[vortgdx].getPtr(), FFTW_ESTIMATE);
    vortgdy_rise =  fftw_plan_dft_c2r_2d(D0, D1, w_vortgdy, f[vortgdy].getPtr(), FFTW_ESTIMATE);
    u_rise =        fftw_plan_dft_c2r_2d(D0, D1, w_u,       f[u].getPtr(), FFTW_ESTIMATE);
    v_rise =        fftw_plan_dft_c2r_2d(D0, D1, w_v,       f[v].getPtr(), FFTW_ESTIMATE);
    vortlap_rise =  fftw_plan_dft_c2r_2d(D0, D1, w_vortlap, f[vortlap].getPtr(), FFTW_ESTIMATE);
    cout << "fftw plans done" << endl << flush;
    cout << "fftw plans done" << endl << flush;
    //cout << f << endl;    
    // Evolution starts ~~
    T d2t = delta_t;
    f[vortm] = f[vort];
    for(x_size timestep = 1; timestep <= final_timestep; ++ timestep ) {

        cout << "timestep : " << ( timestep * delta_t ) << ". ";

        //for(int rk_stage = 0; rk_stage < 4; ++rk_stage) {

        fftw_execute(vort_sink);

        diff2(0, 1, w_vort, w_vortgdx, D0, D1, L0, L1);
        diff2(1, 1, w_vort, w_vortgdy, D0, D1, L0, L1);

        laplacian(w_vort, w_vortlap, D0, D1, L0, L1);

        ipoisson(w_vort, w_stream, D0, D1, L0, L1);

        diff2(0, 1, w_stream, w_v, D0, D1, L0, L1);
        diff2(1, 1, w_stream, w_u, D0, D1, L0, L1);

        fftw_execute(vortgdx_rise); 
        fftw_execute(vortgdy_rise); 
        fftw_execute(u_rise); 
        fftw_execute(v_rise); 
        fftw_execute(vortlap_rise); 


        f[vortgdx].divBy(D0*D1);
        f[vortgdy].divBy(D0*D1);
        f[u].divBy(D0*D1);
        f[v].divBy(D0*D1);
        f[vortlap].divBy(D0*D1);

        //printf("stream(%d,%d) = %e", 100,100, stream(0,100,100));
        // vort = vort - dt * (u*gradx + v*grady);

        T sum = 0;
        for(int i = 0; i < D0; ++i) {
            for(int j = 0; j < D1; ++j) {
                //dvort(0,i,j) =  - delta_t * (- velocity(0,i,j) * gradvort(0,i,j) + velocity(1,i,j) * gradvort(1,i,j));
                f(vortp,i,j) = f(vortm,i,j) +  d2t * ( f(vortlap,i,j) * nu + f(u,i,j) * f(vortgdx,i,j) - f(v,i,j) * f(vortgdy,i,j));
                f(vortm,i,j) = f(vort,i,j) + time_filter * (f(vortm,i,j) + f(vortp,i,j) - 2 * f(vort,i,j));
                f(vort,i,j) = f(vortp,i,j);

                sum += f(vort,i,j);

                d2t = 2*delta_t;
            }
        }
        cout << "sum of vorticity : " << sum; 
        if(timestep % recording_timestep == 0) {
            int t = timestep * delta_t;
            cout << "   Recording...";
            std::stringstream uss, gradxss, streamss,vortss,dvortss;
            vortss << t << "_vort";
            output_field(vortss.str().c_str(), f[vort].getPtr(), x.getPtr(), y.getPtr(), D0, D1);
        }

        cout << endl;

    }

    fftw_destroy_plan(vort_sink);
    fftw_destroy_plan(vortgdx_rise);
    fftw_destroy_plan(vortgdy_rise);
    fftw_destroy_plan(u_rise);
    fftw_destroy_plan(v_rise);
    fftw_destroy_plan(vortlap_rise);

    fftw_free(w_vort);
    fftw_free(w_stream);
    fftw_free(w_u);
    fftw_free(w_v);
    fftw_free(w_vortgdx);
    fftw_free(w_vortgdy);
    fftw_free(w_vortlap);

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

    void output_field(const char *filename, T *field, T *x, T *y, x_size n0, x_size n1) {
        ofstream myFile;
        float* row = new float[n1+1]();

        myFile.open (filename, ios::out | ios::binary);

        // first line
        for(x_size j = 0; j < (n1+1); ++j) {
            if(j==0) 
                row[j] = (float) n1; 
            else {
                row[j] = (float) y[j-1];
                //cout << "row[" << j-1 << "] = " <<  row[j] << endl;
            }
        }

        myFile.write((char *)row, (n1+1) * sizeof(float));
        // rest

        for(x_size i=0; i < n0; ++i) {
            for(x_size j=0; j < (n1+1); ++j) {
                if(j==0) 
                    row[j] = (float) x[i];
                else 
                    row[j] = (float) field[i*n1 + (j-1)]; 

                //    cout << row[j];
            }
            myFile.write((char *)row, (n1+1) * sizeof(float));
        }
        myFile.close();
        delete [] row;
    }

#undef D0
#undef D1 
#undef T 
#undef T
