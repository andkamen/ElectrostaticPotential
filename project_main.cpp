#include "project_header.h"

using namespace std;

void generateMesh(float **mesh );


int main ( int argc, char *argv[] )
{
    // we will use dynamic memory, because it is easier to pass around
    // that's how you create a 2D array on the heap:
    float **mesh = new float*[N];
    char **bmesh = new char*[N];
 
    // harcore C hack to initialise mesh to 0
    // (requires string.h or cstring to be included)
    //void * memset ( void * ptr, int value, size_t num )
    //Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char)
    for (int i = 0; i < N; i++) {
	mesh[i] = new float[N];
	bmesh[i] = new char[N];
	memset(mesh[i], 0, N * sizeof(float));
	memset(bmesh[i], '.', N * sizeof(char));
    }


    generateMesh(mesh);
    algorithm(mesh);
/*    
    // test print of mesh at the end of everything
     cout<<"This is end result"<<endl;
    for (int i = 0; i < N; ++i){
	for (int j = 0; j < N; ++j){
	    cout << mesh[i][j] << ' ';
	}
	cout << endl;
    }

  cout<<"This is boundary"<<endl;
    for (int i = 0; i < N; ++i){
	for (int j = 0; j < N; ++j){
	    cout << bmesh[i][j] << ' ';
	}
	cout << endl;
    }
*/

    return 0;
}    



void generateMesh(float **mesh)
{
    // Boundary b;
    Boundary *b_ptr;
    string instruction;
    while (!cin.eof()) {
	cin >> instruction;
	if (instruction == "Point")
	    b_ptr = new Point();
	if (instruction == "Circle") 
	    b_ptr = new Circle();
	if (instruction == "Rectangle") 
	    b_ptr = new Rectangle();
	if (instruction == "Line") 
	    b_ptr = new Line();
	if (instruction == "break")
	    break;
	b_ptr->injectInto( mesh );
//	b_ptr->print_to_terminal( mesh );
    }
    delete b_ptr;
}





