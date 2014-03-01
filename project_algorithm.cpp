#include "project_header.h"

void algorithm(float **mesh)
{
    float boundaries[N][N]={{0}};
    int const maxitter=10000;
    
//    cout<<"pre boundary check"<<endl;
    //picks out the boundaries
    for (int k=0; k<N; k++)
	for (int l=0; l<N; l++)
	    if (mesh[k][l]!=0)
		boundaries[k][l]=1;
//    cout<<"starting Algorithm"<<endl;
    //algorithm
    for(int itter=0; itter<maxitter; itter++)
	for (int i=1; i<N-1; i++)//runs the algorithm for one timestep 
	    for (int j=1; j<N-1; j++)//runs the algorithm for one timestep
		if (boundaries[i][j]!=1)//if the point is not on a boundary
		    mesh[i][j]=0.25*(mesh[i+1][j]+mesh[i-1][j]+mesh[i][j+1]+mesh[i][j-1]);
		

    cout<<"finished Algorithm"<<endl;
    //creates a datafile for gnuplot
    ofstream f_out ("meshdata.dat");
    for (int i = 0; i < N; ++i){
	for (int j = 0; j < N; ++j){
	  // if ((i==0 && j==0) || (i==N && j==0) || (i==0 && j==N) || (i==N && j==N))
	     if (i==0 || j==0 || i==N || j==N)
	    continue;
	   else
	   f_out << i << " "<< j << " " << mesh[i][j] << endl;
        }
    }
    
    f_out.close();//closes file


}
