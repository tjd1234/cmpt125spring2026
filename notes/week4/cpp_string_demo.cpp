// cpp_string_demo.cpp

//
// Demonstrates the C++ strings.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    //
    // Create some C++ strings.
    //
    // "Hello" and " World!" are string literals, and have the type const char*.
    //
    string first  = "Hello";
    string second = " World!";

    //
    // Print them.
    //
    // C++ knows when to stop printing because C++ strings know their own
    // length.
    //
    cout << " first: \"" << first << "\"\n";
    cout << "second: \"" << second << "\"\n";

    //
    // Copy the first string.
    //
    // To copy a C++ string we use the assignment operator.
    //
    string result = first;

    cout << "result: \"" << result << "\"\n";

    //
    // Append another C-string
    //
    // To append a C-string we need to allocate a new result string big enough
    // to hold the two strings being appended.
    //
    string new_result = result + second;

    cout << "new_result: \"" << new_result << "\"\n";
}
