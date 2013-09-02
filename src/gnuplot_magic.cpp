#include <stdio.h>
#ifdef X_GNUPLOT_MAGIC_H
#ifndef X_GNUPLOT_MAGIC_CPP
#define X_GNUPLOT_MAGIC_CPP

namespace X {
    namespace GNUPLOT {
	template <typename T>
	    void output_field(const char *filename, T *field, T *x, T *y, xsize n0, xsize n1) {

		ofstream myFile;
		float* row = new float[n0+1]();

		myFile.open (filename, ios::out | ios::binary);

		// first line
		for(xsize i = 0; i < (n0+1); ++i) {
		    if(i==0) 
			row[i] = (float) n0; 
		    else
			row[i] = (float) x[i-1];
		}

		myFile.write((char *)row, (n0+1) * sizeof(float));
		// rest

		for(xsize j=0; j < n1; ++j) {
		    for(xsize i=0; i < (n0+1); ++i) {
			if(i==0) 
			    row[i] = (float) y[j];
			else 
			    row[i] = (float) field[X::OFFSET2(n0,n1,i-1,j)]; 
		    }
		    myFile.write((char *)row, (n0+1) * sizeof(float));
		}
		myFile.close();
		delete [] row;
	    }



	template <typename T>
	    void output_field_record(const char *filename, T *field, xsize n0, xsize n1) {

		ofstream myFile;
		float* row = new float[n1]();

		myFile.open (filename, ios::out | ios::binary);

		for(xsize i=0; i < n0; ++i) {
		    for(xsize j=0; j < n1; ++j) {
			row[j] = (float) field[X::OFFSET2(n0,n1,i,j)]; 
		    }
		    myFile.write((char *)row, n1 * sizeof(float));
		}
		myFile.close();
		delete [] row;

		

	    }

    }

}

#endif
#endif
