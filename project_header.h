//Header ==> Function Declarations
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

using namespace std;

const int N = 40;

#ifndef BOUNDARY_H
#define BOUNDARY_H

class boundary {
public:
  //Default constructor
  boundary();

  //Overloaded constructor
  boundary(int[N][N]);

  //Default destructor
  ~boundary(); 
  
  //Print functions
  void print_to_terminal();
  void print_to_file();
  
  //Basic shapes
  void circle(int[5]);
  


  
private:
  //Member Variables
  //int newInformation[5];
 int newMesh[N][N];
};

#endif
