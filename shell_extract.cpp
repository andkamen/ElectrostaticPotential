#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

/*
This program will read the instruction file and extract the value following one of lines.
Ex:  Mesh 100 
     Ground 0

when executing the program you give it a word to look for (mesh or ground)
and it will find where in the file it is and return the value after it.
*/

int main(int argc, char *argv[])
{
    if (argc != 2){
	cerr << "Error! Wrong number of command line arguments" << endl;
	exit(-1); 
    }
    string target = argv[1];
    string str;
    int value;

    ifstream f_in ("inst.txt");
    while (!f_in.eof()){
	f_in >> str;
	if (str.string::compare(target)==0){
	    f_in >> value;
	    return value;
	}
    }

    f_in.close();
    return 0; 
}
