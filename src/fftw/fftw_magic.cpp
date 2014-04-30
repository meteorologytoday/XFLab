
#ifdef X_FFTW_MAGIC_H
#ifndef X_FFTW_MAGIC_CPP
#define X_FFTW_MAGIC_CPP



#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES
#include <cmath>

namespace X {

    /*!
     * \namespace FFTW
     * \author Hsu, Tien-Yiao
     * \copyright NTUAS DMLab
     * \date 2013/04/29
     * \version 1.0
     *  
     * \brief This class is the class for 2-dimensional index using row-major data arrangement.\n
     *  So the (i,j)-th element is at the (i*N2 + j)th position.
 
     *
     */
    namespace FFTW {

                template <typename T>
            void diff2(xsize dir, int order,FFTW_COMPLEX *in, FFTW_COMPLEX *out, xsize D0, xsize D1, T L0, T L1) {
                FFTW_REAL factor = 0;
                xsize offset = 0;
                int oddity = order%4;
                FFTW_REAL k,l;
                FFTW_COMPLEX complex_indicator = {1,0};
                D1 = (xsize)(D1/2+1);
                switch(oddity) {
                    case 0:
                        complex_indicator[0] = 1;
                        complex_indicator[1] = 0;
                        break;
                    case 1:
                        complex_indicator[0] = 0;
                        complex_indicator[1] = 1;
                        break;
                    case 2:
                        complex_indicator[0] = -1;
                        complex_indicator[1] = 0;
                        break;
                    case 3:
                        complex_indicator[0] = 0;
                        complex_indicator[1] = -1;
                        break;
                }

                if(dir == 0) { // dimension 0
                    for(xsize i = 0; i < D0 ; ++i) {
                        factor = pow(((M_PII * fftw_map_wavenumber(D0,i)) / L0) , static_cast<FFTW_REAL>(order));
                        for(xsize j = 0; j < D1; ++j) {

                            offset = OFFSET2(D0,D1,i,j);
                            fftw_ccmul(out[offset], in[offset], complex_indicator);
                            fftw_rcmul(out[offset], factor, out[offset]);
                        }
                    }


                } else if(dir == 1) { // dimension 1
                    for(xsize i = 0; i < D0 ; ++i) {
                        for(xsize j = 0; j < D1; ++j) {
                            factor = pow(((M_PII * fftw_map_wavenumber(D1,j)) / L1) , static_cast<FFTW_REAL>(order));
                            offset = OFFSET2(D0,D1,i,j);
                            fftw_ccmul(out[offset], in[offset], complex_indicator);
                            fftw_rcmul(out[offset], factor, out[offset]);
                        }
                    }


                } else {
                    // error
                    throw 1;
                }

            }

        template <typename T>
            void ipoisson(FFTW_COMPLEX *in, FFTW_COMPLEX *out, xsize D0, xsize D1, T L0, T L1) {
                FFTW_REAL factor = 0;
                FFTW_REAL wavenumber_k = 0, wavenumber_l = 0;
                
                xsize offset = 0;
                FFTW_REAL k,l;
                D1 = (xsize)(D1/2+1);

                for(xsize i = 0; i < D0 ; ++i) {
                    for(xsize j = 0; j < D1; ++j) {
                        factor = 0;
                        offset = OFFSET2(D0,D1,i,j);
                        wavenumber_k = fftw_map_wavenumber(D0,i);
                        wavenumber_l = fftw_map_wavenumber(D1,j);
                        
                        if(wavenumber_k == 0 && wavenumber_l == 0) {
                            out[offset][0] = 0;
                            out[offset][1] = 0;
                            continue;
                        
                        } else {
                            factor =  - (pow(M_PII * wavenumber_k / L0, 2) + pow(M_PII * wavenumber_l / L1, 2));
                        }

                        fftw_rcmul(out[offset], 1 / factor, in[offset]);
                    }
                }


            }

        template <typename T>
            void laplacian(FFTW_COMPLEX *in, FFTW_COMPLEX *out, xsize D0, xsize D1, T L0, T L1) {
                FFTW_REAL factor = 0;
                FFTW_REAL wavenumber_k = 0, wavenumber_l = 0;
                
                xsize offset = 0;
                FFTW_REAL k,l;
                D1 = (xsize)(D1/2+1);

                for(xsize i = 0; i < D0 ; ++i) {
                    for(xsize j = 0; j < D1; ++j) {
                        factor = 0;
                        offset = OFFSET2(D0,D1,i,j);
                        wavenumber_k = fftw_map_wavenumber(D0,i);
                        wavenumber_l = fftw_map_wavenumber(D1,j);
                        
                        factor =  - (pow(M_PII * wavenumber_k / L0, 2) + pow(M_PII * wavenumber_l / L1, 2));

                        fftw_rcmul(out[offset], factor, in[offset]);
                    }
                }


            }



    }
}

#endif
#endif
