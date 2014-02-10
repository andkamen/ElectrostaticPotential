//function definitions
#include "project_header.h"

boundary::boundary()//doesnt work :/
{
   for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      newMesh[i][j]=0;
}

boundary::boundary(int mesh[N][N])
{
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      newMesh[i][j]=mesh[i][j];
}

boundary::~boundary()
{

}

void boundary::print_to_terminal()
{
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      cout << newMesh[i][j];
    }
    cout << endl;
  }
}

void boundary::print_to_file()
{
  ofstream f_out ("mesh.dat");//opens file for writing
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      f_out << newMesh[i][j];
    }
    f_out << endl;
  }
  f_out.close();//closes file
  system("gedit mesh.dat &");
}

void boundary::circle(int information[5])
{
  int x_origin = information[0];
  int y_origin = information[1];
  int radius = information[2];
  for (int x=0;x<N;x++)
    for (int y=0;y<N;y++)
      //if the distance from the centre to the point (x,y) is less then or equal
      //to the radius of the circle change the value of that point in the mesh to 1
      if (sqrt(pow(x_origin-x,2)+pow(y_origin-y,2))<=(radius))
	newMesh[x][y]=1;
}
