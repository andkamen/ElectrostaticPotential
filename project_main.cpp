#include "project_header.h"
//changing value of N in the project_header.h will change the size of the grid. 
//call ./project 1 to print the mesh to the terminal
//call ./project 2 to print the mesh to a text file (file opens automatically)
//call ./project for no output
int main(int argc, char* argv[])
{
  int mesh[N][N]={{0}};//initializes mesh to be at zero at every point
  int information_b1[5]; //info about a boundary
  information_b1[2] = 5;//radius
  information_b1[0]=20;//x origin
  information_b1[1]=20;//y origin
  boundary boundary_1(mesh);//creates an object "boundary_1" of class "boundary"
  boundary_1.circle(information_b1);
  if (argc!=1){ // if any print option was requested when called
    switch (atoi(argv[1])){//looks at the command line argument passed
    case 1:
      boundary_1.print_to_terminal();
      break;
    case 2:
      boundary_1.print_to_file();
      break;
    default:
      cerr<< "Neither file nor terminal output was selected!" << endl;
      break;
    }
  }
}

