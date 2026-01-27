// c_string_demo.cpp

//
// Demonstrates the complexity of working with C-strings compared to C++
// strings. This example shows: creating, copying, appending, and deallocating
// C-strings.
//

#include <cstring> // for strlen, strcpy, strcat
#include <iostream>

using namespace std;

int main()
{
    //
    // Create some C-strings.
    //
    // The string literals "Hello" and " World!" are not stored in free store
    // memory so we don't need to worry about de-allocating them. The pointer
    // variables first and second are stored on the call stack.
    //
    // C++ automatically adds a null terminator to the end of string literals.
    //
    const char* first  = "Hello"; 
    const char* second = " World!";

    //
    // Print them.
    //
    // C++ knows when to stop printing because of the null terminators at the
    // end of the strings.
    //
    cout << " first: \"" << first << "\"\n";
    cout << "second: \"" << second << "\"\n";

    //
    // Copy the first string.
    //
    // To copy a C-string we use the standard strcpy function. We must first
    // manually allocate the result string, ensuring it has enough space to hold
    // the source string.
    //
    // The result string is allocated on the free store because, in general, we
    // don't know how long the result string will be (e.g if we read the values
    // of first and second from a file we would not know their lengths until
    // runtime).
    //
    int first_len = strlen(first); // get the length of the first string

    //
    // The size of the result string is +1 the size of the string being copied
    // because we need to add a null terminator.
    //
    char* result = new char[first_len + 1]; // + 1 for the null terminator

    //
    // Copy the first string into our allocated memory.
    //
    strcpy(result, first);

    cout << "result: \"" << result << "\"\n";

    //
    // Append two C-strings.
    //
    // To append C-strings we must first allocate a new result string big enough
    // to hold the strings being appended.
    //
    int second_len = strlen(second);
    int new_len    = first_len + second_len;

    //
    // Allocate the result string.
    //
    char* new_result = new char[new_len + 1]; // + 1 for the null terminator

    //
    // Copy the previous result into new_result
    //
    strcpy(new_result, result);

    //
    // Append the second string into new_result
    //
    strcat(new_result, second);

    cout << "new_result: \"" << new_result << "\"\n";

    //
    // We're done with the result strings, so de-allocate them.
    //
    delete[] result;
    delete[] new_result;
}
