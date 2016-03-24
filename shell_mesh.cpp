#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{ 
  int N=atoi(argv[1]);//mesh size
  float ground = atoi(argv[2]);
  float potential;
  if (argc==4)//if potential is given assign it 
    potential = atoi(argv[3]);
  else if (argc==3)//if not set it to zero
    potential=0;
  else
    cerr << "Error! Command line argument is missing!" << endl;
  
  char **bmesh = new char*[N];
  for (int i=0; i<N; i++){
    bmesh[i]=new char[N];
   };

  //read in shell_mesh.dat
  char ch;
  ifstream f_in ("shell_chmesh.dat");
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      f_in >> ch;
      if (ch == '#')
	bmesh[i][j]='#';//not a boundary
      else 
	bmesh[i][j]='.';//boundary as defined in project_inject.cpp
    }
  }
  
  ofstream f_out_mesh ("shell_mesh.dat");
  ofstream f_out_bmesh ("shell_bmesh.dat");
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      f_out_bmesh << bmesh[i][j];
      if (bmesh[i][j]=='#'){
	f_out_mesh << ground << " ";
      }
      else{ 
	f_out_mesh << potential << " ";
      } 
    }
    f_out_mesh << endl;
    f_out_bmesh << endl;
  }
  

  for (int i=0; i<N; i++){
    delete bmesh[i];
  }
  delete bmesh;
  
  f_in.close();
  f_out_mesh.close();
  f_out_bmesh.close();

  return 0;
}
