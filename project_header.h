#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <cstring>

using namespace std;

const int N = 100; //size of the mesh

#ifndef BOUNDARY_H
#define BOUNDARY_H

class Boundary{


    public:
	~Boundary() {}
	void virtual injectInto (float **mesh) {};
	//Print functions
	void print_to_terminal(float **mesh);
	void print_to_file(float **mesh);


};

class Point : public Boundary {
    int x_origin;
    int y_origin;
    float potential; 

    public:
    //void injectInto (int **mesh);
    Point() {
	cin >> x_origin >> y_origin >> potential;
    }

    void injectInto (float **mesh);

};

class Circle : public Boundary {
    int x_origin;
    int y_origin;
    int radius;
    float potential;

    public:
    Circle() {
	cin >> x_origin  >> y_origin >> radius >> potential;
    }
    void injectInto (float **mesh);
};

class Rectangle : public Boundary {
    int x_origin;
    int y_origin;
    int height;
    int width;
    float potential; 

    public:
    Rectangle() { 
	cin >> x_origin >> y_origin >> height >> width >> potential;
    }
    void injectInto (float **mesh);
};


class Line : public Boundary {
    int column;
    int row;
    int start;
    int choice;
    float potential; 

    public:
    Line() { 
	cin >> column >> row >> start >> choice >> potential;
    }
    void injectInto (float **mesh);
};

#endif

//function prototypes
//void print_mesh(int **mesh, Boundary boundary,int choice);

void algorithm(float **mesh);

