#include "project_header.h"

using namespace std;

int N = 10;

int main ( int argc, char *argv[] )
{
  int * N_ptr = &N;
  string instruction;
  float ground=0.0;

  cin >> instruction;
  if (instruction == "Mesh")
    cin >> *N_ptr;
  cin >> instruction;
  if (instruction == "Ground")
    cin >> ground;

    // we will use dynamic memory, because it is easier to pass around
    // that's how you create a 2D array on the heap:
   float **mesh = new float*[N];
   char **bmesh = new char*[N];
    //void * memset ( void * ptr, int value, size_t num )
    //Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char)
   for (int i = 0; i < N; i++){ 
     mesh[i] = new float[N];
     bmesh[i] = new char[N];
   }
  
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < N; j++){
      mesh[i][j] = ground;
      bmesh[i][j] ='.';
      }
  generateMesh(mesh,bmesh); 
  algorithm(mesh,bmesh,ground);

    return 0;
}    





