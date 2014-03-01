#include "project_header.h"
boundary instructions(int mesh[N][N])
{
boundary boundary1(mesh);
boundary1.circle_parameters(50, 50, 10, 10);
boundary1.circle();
return boundary1;


/*
"string instructions" are the lines from the premade file that is fead into the program. Or if you are just doing it the its single lines from input

NB if you feed the file into main, since function below require standard input and the file serves as that it directly gives all the instructions to the code below.

circle 5 5 6
square 3 3 2
rect 7 5 9 8


while copying check if mesh is zero if yess- proceed if no break and say which figure is the culprit
*/

void generateMesh(int mesh[N][N]) {
	Boundary b;
	string instruction;
	while (!cin.eof()) {
		cin >> instruction;
		if (instruction == "circle")
			b = Circle();
		else
			b = Square();

		b.injectInto (mesh);
	}
}

class Boundary {
	public:
	void virtual injectInto (int **mesh);
};

class Circle : Boundary {
	int x, y, r;

	public:
	Circle () {
		cin >> x >> y >> r;
	}
	void injectInto (int **mesh) {
		code specific to circle
	}
};

class Rect : Boundary {
	int x, y, w, h;

	public:
	Rect () {
		cin >> x >> y >> w >> h;
	}
	void injectInto (int **mesh) {
		code specific to circle
	}
};






--------------------------
class Rect : Boundary {
	int x, y, w, h;

	public:
	Rect (int x2, int y2, int w2, h2) : x(x2), y(y2), w(w2), h(h2) {}
	void injectInto (int **mesh) {
		code specific to circle
	}
};
