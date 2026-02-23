// demo2.cpp
// separate_compilation_demo.cpp

//
// This is another program that uses the RGB_color class.
//
// Rules for have been added to the makefile to compile and build the
// executable. Run "make demo2" to build the executable.
//

#include "RGB_color.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Separate compilation: .h and .cpp files\n";
    
    RGB_color a(10, 20, 200);
    RGB_color b(a);
    RGB_color c; // black by default

    cout << "a: " << a.to_string() << endl;
    cout << "b: " << b.to_string() << endl;
    cout << "c: " << c.to_string() << endl;
    a.invert();
    b.invert();
    c.invert();
    cout << "a inverted: " << a.to_string() << endl;
    cout << "b inverted: " << b.to_string() << endl;
    cout << "c inverted: " << c.to_string() << endl;
}
