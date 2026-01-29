// c_string_funcs.cpp

//
// This files shows some simple implementations of the C-string functions
// strlen, strcpy, and strcat. 
//
// They are for educational purposes only: they may not be as efficient, safe,
// or complete as the standard library functions.
//

#include <cstring>
#include <iostream>

using namespace std;

int my_strlen(const char* s)
{
    int len = 0;
    for (const char* p = s; *p != '\0'; p++)
    {
        len++;
    }
    return len;
}

char* my_strcpy(char* dest, const char* src)
{
    char* original_dest = dest;
    for (const char* p = src; *p != '\0'; p++)
    {
        *dest = *p;
        dest++;
    }
    *dest = '\0';
    return original_dest;
}

void my_strcat(char* dest, const char* src)
{
    // first, find the end of dest (the null terminator)
    while (*dest != '\0')
    {
        dest++;
    }

    // now append src starting from the end of dest
    for (const char* p = src; *p != '\0'; p++)
    {
        *dest = *p;
        dest++;
    }
    *dest = '\0';
}

int main()
{
    const char* first = "Hello";

    // print the string using array indexing
    for (int i = 0; first[i] != '\0'; i++)
    {
        cout << first[i];
    }
    cout << endl;

    // print the string using a pointer
    for (const char* p = first; *p != '\0'; p++)
    {
        cout << *p;
    }
    cout << endl;

    cout << "length of first: " << my_strlen(first) << " (my_strlen)" << endl;
    cout << "length of first: " << strlen(first) << " (strlen)" << endl;

    char* result = new char[my_strlen(first) + 1];
    my_strcpy(result, first);
    cout << "result: " << result << endl;
}
