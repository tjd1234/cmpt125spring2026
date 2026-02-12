// separate_compilation_demo.cpp

//
// This version is based on sep2/separate_compilation_demo.cpp, but now uses
// three files:
//
// - RGB_color.h: contains the class and function headers (i.e. the
//   declarations).
// - RGB_color.cpp: contains the implementations (i.e. the definitions) of the
//   class and functions that appear in RGB_color.h.
// - separate_compilation_demo.cpp: contains the main function.
//
// To compile the program, first compile the .cpp files into .o files:
//
//   $ g++ -c RGB_color.cpp $ g++ -c separate_compilation_demo.cpp
//
// The -c option tells g++ to compiles the files into object files: RGB_color.o
// and separate_compilation_demo.o are created. No executable file is created
// yet.
//
// To create the executable file, we link the objects files together using the
// -o option:
//
//   $ g++ -o separate_compilation_demo separate_compilation_demo.o RGB_color.o
//
// This creates the executable file separate_compilation_demo:
//
//   $ ./separate_compilation_demo
//
// To simplify the process of runnning these commands, we add some extra rules
// in the makefile: go take a look at it. Note that the makefile is a little bit
// smart: it only re-runs a command if the file has changed. This can speed up
// compiling big programs that have many files.
//

#include "RGB_color.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Separate compilation: .h and .cpp files\n";
    RGB_color c(255, 0, 0);
    cout << "c: " << c.to_string() << endl;
    c.invert();
    cout << "c: " << c.to_string() << endl;
}
