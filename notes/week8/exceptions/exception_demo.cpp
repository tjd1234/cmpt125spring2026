// exception_demo.cpp

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void error(const string& message)
{
    throw std::runtime_error(message);
    cout << "This line is never executed!\n";
}

void example1()
{
    cout << "About to call error ...\n";
    error("thrown from example1()");
    cout << "... error called!\n"; // never executed
}

void f()
{
    cout << "this is f() ...";
    error("thrown from f()");
}

void example2()
{
    cout << "Calling f() ...\n";
    f();
    cout << "... f() called!\n"; // never executed
}

void example3()
{
    cout << "Calling f() ...\n";
    try
    {
        f();
    }
    catch (const std::runtime_error& e)
    {
        cout << "Caught a runtime exception thrown by f(): " << e.what() << "\n";
    }
    cout << "... f() called!\n"; // runs normally
}

class Mem
{
  public:
    int* p;

    Mem() { p = new int[10]; }

    ~Mem()
    {
        delete[] p;
        cout << "Mem destructor: p de-allocated" << endl;
    }
};

void example4()
{
    cout << "(call with a try/catch block in main to see destructor output)" << endl;
    Mem m;
    error("thrown from example4()");
    cout << "example4() finished." << endl;
}

//
// If an exception leaves main, then the program might not propagate the
// exception down the call stack, e.g. not calling the destructors of local
// objects. So to prevent that we put the try/catch block in main.
//
int main()
{
    try
    {
        // example1();
        // example2();
        // example3();
        example4();
    }
    catch (...)
    {
        cout << "Caught an exception!\n";
        cout << "Program terminated.\n";
    }
}
