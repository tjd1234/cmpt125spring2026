// hello_name_getline.cpp

//
// This reads in the users name using getline, which reads the entire line.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "What's your name? ";

    string name;
    getline(cin, name);

    cout << "Hello, " << name << "!\n";
}