#ifndef X_EDC_CPP
#define X_EDC_CPP

#include "xdmlab"
#include <iostream>
#include <cmath>

using namespace X;
using namespace std;

namespace X {
    namespace EDC {
        template<typename T, xsize D0, xsize D1, xsize LEVS> 
            void calEDC(DataIndex2<T,D0,D1>& input, DataIndex1<T,D0>& x, DataIndex1<T,D1>& y, T kappa, DataIndex2<T,D0,D1>& output, DataIndex1<T,LEVS>& conc, Index1<T,LEVS>& edc, bool div_by_area) {
                DataIndex2<T,D0,D1> dA;
                DataIndex2<T,D0,D1> grad_square;
                DataIndex2<T,D0,D1> grid_input;
                Enumerator2<D0,D1> enu_data;
                
                Enumerator1<LEVS> enu_levs;
                DataIndex1<T,LEVS> dAdC;
                DataIndex1<T,LEVS> AC;
                DataIndex1<T,LEVS> dIdC;

                // Calculate delta area
                enu_data.each_index([&] (xsize i, xsize j) {
                        T dx = 0;
                        T dy = 0;

                        if(i==0) 
                        dx = (x(1) - x(0)) / 2;
                        else if(i == D0-1) 
                        dx = (x(D0-1) - x(D0-2)) / 2;
                        else
                        dx = (x(i+1) - x(i-1)) / 2;

                        if(j==0) 
                        dy = (y(1) - y(0)) / 2;
                        else if(j == D1-1)
                        dy = (y(D1-1) - y(D1-2)) / 2;
                        else
                        dy = (y(j+1) - y(j-1)) / 2;

                        dA(i,j) = dx*dy;


                });
                
                // grid field 
                T min = input(0,0);
                T max = input(0,0);
                enu_data.each_index([&] (xsize i, xsize j) {
                    if(input(i,j) > max)
                        max = input(i,j);
                    if(input(i,j) < min)
                        min = input(i,j);
                });

                T dc = (max - min) / LEVS;
                //cout << "max = " << max << ", min = " << min << ", dc = " << dc << "levs = " << LEVS << endl;
                enu_data.each_index([&] (xsize i, xsize j) {
                    T g = floor( (input(i,j) - min) / dc);
                    grid_input(i,j) = (g >= LEVS) ? LEVS-1 : g;
               
            });
                
                // calculate grad tracer
                enu_data.each_index([&] (xsize i, xsize j) {
                    T gradx, grady;
                    if(i == 0) 
                        gradx = (input(1,j) - input(0,j)) / (x(1)-x(0));
                    else if(i == D0-1) 
                        gradx = (input(D0-1,j) - input(D0-2,j)) / (x(D0-1)-x(D0-2));
                    else 
                        gradx = (input(i+1,j) - input(i-1,j)) / (x(i+1)-x(i-1)); 

                    if(j == 0)
                        grady = (input(i,1) - input(i,0)) / (y(1)-y(0));
                    else if(j == D1-1)
                        grady = (input(i,D1-1) - input(i,D1-2)) / (y(D1-1)-y(D1-2));
                     else 
                        grady = (input(i,j+1) - input(i,j-1)) / (y(j+1)-y(j-1)); 

   
                    grad_square(i,j) = pow(gradx,2) + pow(grady,2);
                });

                // count area
                enu_data.each_index([&] (xsize i, xsize j) {
                    dAdC(static_cast<xsize>(grid_input(i,j))) += dA(i,j);
                    dIdC(static_cast<xsize>(grid_input(i,j))) += grad_square(i,j) * dA(i,j) * kappa;
                });

                //cout << "Integrating area... " << flush;
                // integrate area
                for(xsize i = 0; i < LEVS; ++i) {
                    xsize j = LEVS - i - 1;
                    if(j == LEVS - 1) {
                        AC(j) = dAdC(j);
                    } else {
                        AC(j) = AC(j+1) + dAdC(j);
                    }
                }
                
                //cout << "Calculate edc... " << flush;
            
                T sum_dAdC = 0;
                // calculate edc

                if(div_by_area == true) {
                    enu_levs.each_index([&](xsize i) {
                        edc(i) = dAdC(i) * dIdC(i) / (AC(i) * (dc*dc));
                        conc(i) = min + i * dc;
                        sum_dAdC += dAdC(i);
                    });
                } else {
                    enu_levs.each_index([&](xsize i) {
                        edc(i) = dAdC(i) * dIdC(i) / ((dc*dc));
                        conc(i) = min + i * dc;
                        sum_dAdC += dAdC(i);
                    });
                
                }
                //cout << sum_dAdC ;
                //cout << "done." << endl;
                enu_data.each_index([&](xsize i, xsize j) {
                    output(i,j) = edc(static_cast<xsize>(grid_input(i,j)));
                });

            }

    }
}

#endif
