#include <iostream>
#include <fstream>
#include <math.h>
//The code produced file datafile.dat with three arrays of data: x z V(x,z)

using namespace std;

//function prototypes
float V(float,float,float,float,float,float);

//start of code

int main()
{
    //change the mesh by changing denominator in dl and dd
    float l=10.0, d=10.0; //length of the plates and distance between them
    float dl=0.1, dd=0.1; //mesh
    float R=1.5, Vp=100.0, Vn=-100.0;//radius of sphere and potential of the plates
    float E=(Vp-Vn)/d; // E-field between plates
    int n=0; //itteration counter
    ofstream f_out ("datafile.dat");//opens file for writing
    for (float x=0.0; x<l+dl; x+=dl)//itterates through x
	for (float z=0.0+dd; z<d+dd; z+=dd){ // itterates through z 
	    f_out << x << ' ' << z << ' ' << V(x,z,E,R,l,d) << endl; // writes x z V(x,z) into the datafile
	    cout << "Itteration number " << n << "  x = " << x << 
		" z = " << z << endl;
	    n++;
	}
    f_out.close();//closes file
}

float V(float x, float z, float E, float R, float l, float d)
{
    //(l/2, d/2) is the centre point, and so if (x,z) that was passed 
    //to this function is within R from that point it means that the point
    //is within the sphere (V=0)
    if ( R>=sqrt(pow(l/2-x,2)+pow(d/2-z,2)) ){
	float value=-100;
	return value;
    }
    float equation= -E*sqrt(x*x+z*z)*(1-pow(R,3)*pow(x*x+z*z,-1.5))*cos(atan(z/x));

    if (equation>0){
	float value=0;
	return value;
    }

    return equation; //V(x,z) (cartesian coordinates)
}
