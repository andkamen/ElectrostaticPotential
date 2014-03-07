#include "project_header.h"

extern int N;

void algorithm(float **mesh, char **bmesh, float ground)
{
  int counter=0, counter_vals=N*N, counter_zeros=0;
  float zeroish=0.02;
  float dx=1,dy=1,b=dx/dy;
  //initialize mesh1 and mesh2 and set it to be equal to mesh
  float mesh_old[N][N], mesh_new[N][N];
  for(int k=0; k<N; k++)
    for(int l=0; l<N; l++){
      mesh_old[k][l]=mesh[k][l];
      mesh_new[k][l]=mesh[k][l];
    }
  cout << "Starting Algorithm" << endl;

  while(1){
    for (int i=1; i<N-1; i++)//runs the algorithm for one timestep 
      for (int j=1; j<N-1; j++)//runs the algorithm for one timestep
	if (bmesh[i][j]!='#')//if the point is not on a boundary
	  mesh[i][j]=(mesh[i+1][j]+mesh[i-1][j]+b*b*mesh[i][j+1]+b*b*mesh[i][j-1])/(2*(1+b*b));

    if (counter%1000==0){
      if (counter != 0)
	cout << "I have just done "<< counter/1000 << "k itterations!"<< endl;
      for(int k=0; k<N; k++)
	for(int l=0; l<N; l++){
	  mesh_old[k][l]=mesh_new[k][l];
	  mesh_new[k][l]=mesh[k][l];
	  if (abs(mesh_old[k][l]-mesh_new[k][l])<zeroish)
	    counter_zeros++;
	}
      if (counter_zeros == counter_vals)
	break;
    }
    counter++;
    counter_zeros=0;
  }
  cout<<"Finished Algorithm"<<endl;


    //creates a datafile for gnuplot
    ofstream f_out ("meshdata.dat");
    for (int i = 0; i < N; i++){
	for (int j = 0; j < N;j++){
	   f_out << i << " "<< j << " " << mesh[i][j] << endl;
      	}
    }
    
    f_out.close();//closes file
}
