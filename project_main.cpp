#include "project_header.h"

using namespace std;

/*
N is defined as extern in the other files, then given an inital value 
so that on compilation some initial space is preserved for the arrays.
before they are initialised N is given its real value.
*/

int N = 10;

int main ( int argc, char *argv[] )
{
    string instruction;
    float ground=0.0;

    //read instruction file to get the values for the mesh size and ground potential
    cin >> instruction;
    if (instruction == "Mesh" || instruction == "mesh")
	cin >> N;
    else{
	cerr << "Error! Mesh instruction not found!" << endl;
	exit(1);
    }
    cin >> instruction;
    if (instruction == "Ground" || instruction == "ground")
	cin >> ground;
    else{
	cerr << "Error! Ground instruction not found!" << endl;
	exit(1);
    }

    // we will use dynamic memory, because it is easier to pass around
    // that's how you create a 2D array on the heap:
    float **mesh = new float*[N];
    char **bmesh = new char*[N];
    for (int i = 0; i < N; i++){ 
	mesh[i] = new float[N];
	bmesh[i] = new char[N];
    }

    //if ran from project.sh file it will execute the if. Otherwise it will execute the else
    if (argc > 1){
	int f;
	char ch;

	ifstream f_in_mesh ("shell_mesh.dat"); //potential of mesh at each point
	ifstream f_in_bmesh ("shell_bmesh.dat");//boundaries 
	for (int i=0; i<N; i++)
	    for (int j=0; j<N; j++){
		f_in_mesh >> f;
		f_in_bmesh >> ch;
		mesh[i][j]=f;
		bmesh[i][j]=ch;
	    }

	f_in_mesh.close();
	f_in_bmesh.close();

	generateMesh(mesh,bmesh); 
	algorithm(mesh,bmesh,ground);

	for (int i = 0; i < N; i++){
	    delete bmesh[i];
	    delete mesh[i];
	}
	delete mesh;
	delete bmesh;
    }
    else {
	generateMesh(mesh,bmesh); 
	algorithm(mesh,bmesh,ground);
    }

    return 0;
}    


