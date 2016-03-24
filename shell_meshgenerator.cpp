#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/*
   This program fills a mesh with zeroes and prints it on a file to be used at a later point.
 */


int main(int argc, char *argv[])
{
    if (argc!=2)
	cerr << "Error! Command line argument missing!" << endl; 

    int N=atoi(argv[1]);// read the mesh size


    // print the matrix to a file
    ofstream f_out ("shell_chmesh.dat");
    for (int i=0; i<N; i++){
	for (int j=0; j<N; j++){
	    f_out << '#';
	}
	f_out << endl;
    }

    f_out.close();

    return 0;
}
