// basic_types_auto.cpp

//
// This uses the auto keyword to infer the types of variables.
//
// For most programs in this course we will avoid using auto, and instead
// explicitly declare the types of variables.
//

#include <iostream>

using namespace std;

int main()
{
    auto a = 5;    // the types of
    auto x = 6.22; // a, x, and c
    auto c = 'm';  // are explicitly given
    auto s = "hello";
    // important: s has type const char *, not string

    cout << a << ' ' << x << ' ' << c << ' ' << s << "\n";
}
