#include "project_header.h"
/*
   void print_mesh(int **mesh, Boundary *boundary,int choice)
   {
   switch (choice){//looks at the command line argument passed
   case 1:
   boundary.print_to_terminal(mesh);
   break;
   case 2:
   boundary.print_to_file(mesh);
   break;
   default:
   cerr<< "Neither file nor terminal output was selected!" << endl;
   break;
   }
   }
 */
void Boundary::print_to_terminal(float **mesh)
{
    for (int i = 0; i < N; ++i){
	for (int j = 0; j < N; ++j){
	    cout << mesh[i][j] << ' ';
	}
	cout << endl;
    }
}

void Boundary::print_to_file(float **mesh)
{
    ofstream f_out ("mesh.dat");//opens file for writing
    for (int i = 0; i < N; ++i){
	for (int j = 0; j < N; ++j){
	    f_out << mesh[i][j] << " ";
	}
	f_out << endl;
    }
    f_out.close();//closes file
    // system("gedit mesh.dat &");
}

void Point::injectInto (float **mesh) {
    mesh[x_origin][y_origin]=potential;
}

void Circle::injectInto (float **mesh){

    int x,y,p; //used by circle plotting algorithm below
    p=3-2*radius;
    x=0;
    y=radius;

    mesh[x_origin][y_origin+radius]=potential;
    mesh[x_origin][y_origin-radius]=potential;
    mesh[x_origin+radius][y_origin]=potential;
    mesh[x_origin-radius][y_origin]=potential;

    while (x<=y){
	x++;
	if(p<0){
	    p+=4*x+6;
	}
	else{
	    p+=4*(x-y)+10;
	    y--;
	}
	mesh[x_origin+x][y_origin+y]=potential;
	mesh[x_origin+x][y_origin-y]=potential;
	mesh[x_origin-x][y_origin+y]=potential;
	mesh[x_origin-x][y_origin-y]=potential;
	mesh[x_origin+y][y_origin+x]=potential;
	mesh[x_origin-y][y_origin+x]=potential;
	mesh[x_origin+y][y_origin-x]=potential;
	mesh[x_origin-y][y_origin-x]=potential;

    }
    for (int i=0; i<=radius; i++){
	for (int j=0; j<=radius; j++){

	    if (mesh[x_origin+i][y_origin+j]==0){

		mesh[x_origin+i][y_origin+j]=potential;
		mesh[x_origin+i][y_origin-j]=potential;
		mesh[x_origin-i][y_origin+j]=potential;
		mesh[x_origin-i][y_origin-j]=potential;
	    }
	    else break;

	}
    }
}

void Rectangle::injectInto (float **mesh) {

    for (int x = ( x_origin ); x < ( x_origin + height ); x++ )
	for (int y = ( y_origin); y < ( y_origin + width ); y++ )
	    mesh[x][y]=potential;
}

void Line::injectInto (float **mesh) {


    switch (choice) {

	case 1:
	    //horizontal line
		for (int y=0;y<N;y++){
		    mesh[row][y] = potential;
		}
	    break;
	case 2:
	    //vertical line line
	    for (int x=0;x<N;x++) {
		    mesh[x][column] = potential;
		}
	    break;
	case 3:
	    //right diagonal line below main diagonal
	    for (int x=0;x<N;x++) {
		for (int y=0;y<N;y++) {
		    if (x==y+start) {
			mesh[x][y] = potential;
		    }
		}
	    }
	    break;
	case 4:
	    //right diagonal line above main diagonal
	    for (int x=0;x<N;x++) {
		for (int y=0;y<N;y++) {
		    if (y==x+start) {
			mesh[x][y] = potential;
		    }
		}
	    }
	    break;
	case 5:
	    //left diagonal line above main diagonal
	    for (int x=0;x<=N/2;x++) {
		mesh[x][start] = potential;
		start = start-1;
	    }
	    break;
	case 6:
	    //left diagonal line below main diagonal
	    for (int x=N/2;x<=N;x++) {
		mesh[x][start] = potential;
		start = start-1;
	    }
	    break;
    }
}
