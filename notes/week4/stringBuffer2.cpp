// stringBuffer.cpp

#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

struct StringBuffer
{
    char* str;
    int size;
    int capacity;
};

//
// Returns a new StringBuffer with the given text.
//
StringBuffer make_StringBuffer(const char* text)
{
    // get the length of the text
    int len = strlen(text);

    // allocate a new array of characters
    char* str = new char[len]; // no \0 at the end (!)

    // copy the characters from text to str
    for (int i = 0; i < len; i++)
    {
        str[i] = text[i];
    }

    // return the new StringBuffer
    return StringBuffer{str, len, len + 10};
}

//
// Returns a new StringBuffer that is a copy of the given StringBuffer.
//
StringBuffer make_copy(const StringBuffer& s)
{
    // make a new array of characters of the same size as s, plus some extra
    // space for growth
    int capacity  = s.size + 10;
    char* new_str = new char[capacity];

    // copy the characters from s to the new array
    for (int i = 0; i < s.size; i++)
    {
        new_str[i] = s.str[i];
    }
    return StringBuffer{new_str, s.size, capacity};
}

//
// De-allocates the given StringBuffer.
//
// Sets the string to nullptr and the size and capacity to -1.
//
void destroy_StringBuffer(StringBuffer& s)
{
    delete[] s.str;
    s.str      = nullptr;
    s.size     = -1;
    s.capacity = -1;
}

//
// Appends StringBuffer other to the end of StringBuffer s.
//
// s is modified, and other is not changed.
//
void append(StringBuffer& s, const StringBuffer& other)
{
    // if capacity of s is less than the size of the new string, then create a
    // new array with double its capacity
    if (s.capacity < s.size + other.size)
    {
        int capacity  = 2 * (s.size + other.size);
        char* new_str = new char[capacity];
        
        // copy the s characters to the new array
        for (int i = 0; i < s.size; i++)
        {
            new_str[i] = s.str[i];
        }
        
        // de-allocate the old array
        delete[] s.str;
        
        // make s point to the new array and update the size and capacity
        s.str      = new_str;
        s.size     = s.size + other.size;
        s.capacity = capacity;
    }

    // at this point s has enough capacity to hold the new string, so we just
    // copy the other string to the end of s
    for (int i = 0; i < other.size; i++)
    {
        s.str[s.size + i] = other.str[i];
    }

    // the size of s has changed (but not the capacity or string pointer)
    s.size = s.size + other.size;
}

//
// helper functions
//

void print(const StringBuffer& s)
{
    for (int i = 0; i < s.size; i++)
    {
        cout << s.str[i];
    }
}

void println(const StringBuffer& s)
{
    print(s);
    cout << "\n";
}

void debug(const StringBuffer& s)
{
    cout << "{\"";
    print(s);
    cout << "\", size: " << s.size << "}\n";
}

void debug2(const StringBuffer& s)
{
    cout << "{\"";
    for (int i = 0; i < s.size; i++)
    {
        cout << s.str[i];
    }
    cout << "\", size: " << s.size << "}\n";
}

void demo1()
{
    StringBuffer s = make_StringBuffer("Hello");
    cout << s.size << "\n";          // prints 5
    for (int i = 0; i < s.size; i++) // prints "Hello"
    {
        cout << s.str[i];
    }
    cout << "\n";

    StringBuffer t = make_StringBuffer(" World");
    cout << t.size << "\n"; // prints 6

    // append t to s, modifying s to be "Hello World"
    // append(s, t);
    cout << s.size << "\n";          // prints 11
    for (int i = 0; i < s.size; i++) // prints "Hello World"
    {
        cout << s.str[i];
    }
    cout << "\n";

    destroy_StringBuffer(s);
    destroy_StringBuffer(t);
    // dangling pointers
}

void demo2()
{
    StringBuffer s = make_StringBuffer("Hello");
    debug(s);

    StringBuffer t = make_copy(s);
    debug(t);

    append(s, t); // append t to s, modifying s to be "Hello World"
    debug(s);

    destroy_StringBuffer(s);
    destroy_StringBuffer(t);
}

//
// Performance test for appending words from a file to a StringBuffer.
//

//
// Performance without growth capacity (new called on every append)
//
// Performance test for tenKwords.txt ...
//   Used:   65880 bytes,   64 KB (100.0%)
// Unused:       0 bytes,    0 KB (0.0%)
//  Total:   65880 bytes,   64 KB ( 100%)
// (8 bits per char)
//
// ________________________________________________________
// Executed in  301.24 millis    fish           external
//    usr time  289.72 millis   94.00 micros  289.63 millis
//    sys time    8.67 millis  657.00 micros    8.01 millis
//
////////////////////////////////////////////////////////////
//
// Performance test for enable1.txt ...
// Used: 1570508 bytes, 1533 KB (100.0%)
// Unused:       0 bytes,    0 KB (0.0%)
//  Total: 1570508 bytes, 1533 KB ( 100%)
// (8 bits per char)
//
// ________________________________________________________
// Executed in  113.80 secs    fish           external
//    usr time  112.92 secs    0.12 millis  112.92 secs
//    sys time    0.28 secs    1.22 millis    0.28 secs
//

//
// Performance with growth capacity (new called only when capacity is exceeded)
//
////////////////////////////////////////////////////////////
//
// Performance test for enable1.txt ...
//   Used: 1570664 bytes, 1533 KB (60.5%)
// Unused: 1026116 bytes, 1002 KB (39.5%)
//  Total: 2596780 bytes, 2535 KB ( 100%)
// (8 bits per char)
//
// ________________________________________________________
// Executed in  336.15 millis    fish           external
//    usr time   51.67 millis   84.00 micros   51.58 millis
//    sys time    4.58 millis  560.00 micros    4.02 millis
//
////////////////////////////////////////////////////////////
//
// Performance test for tenKwords.txt ...
//   Used:   65984 bytes,   64 KB (52.0%)
// Unused:   60906 bytes,   59 KB (48.0%)
//  Total:  126890 bytes,  123 KB ( 100%)
// (8 bits per char)

// ________________________________________________________
// Executed in  308.58 millis    fish           external
//    usr time    9.07 millis    0.14 millis    8.94 millis
//    sys time    5.03 millis    1.15 millis    3.88 millis
void append_performance_test()
{
    // const string filename = "tenKwords.txt";
    const string filename = "enable1.txt";
    cout << "Performance test for " << filename << " ...\n";
    StringBuffer s = make_StringBuffer("");
    ifstream words(filename);
    string word;
    while (words >> word)
    {
        append(s, make_StringBuffer(word.c_str()));
    }

    //
    // report the results
    //
    int total_bytes   = s.capacity();
    int used_bytes    = s.size();
    int unused_bytes  = total_bytes - used_bytes;
    double pct_used   = double(used_bytes) / total_bytes;
    double pct_unused = double(unused_bytes) / total_bytes;

    cout << fixed << setprecision(1);
    cout << "  Used: " << setw(7) << used_bytes << " bytes, " << setw(4) << used_bytes / 1024
         << " KB (" << pct_used * 100 << "%)\n";
    cout << "Unused: " << setw(7) << unused_bytes << " bytes, " << setw(4) << unused_bytes / 1024
         << " KB (" << pct_unused * 100 << "%)\n";
    cout << " Total: " << setw(7) << total_bytes << " bytes, " << setw(4) << total_bytes / 1024
         << " KB ( 100%)\n";
    cout << "(" << CHAR_BIT << " bits per char)\n";
}

//
// Test code
//

void test_make_StringBuffer()
{
    cout << "test_make_StringBuffer ...\n";
    // empty string
    StringBuffer s = make_StringBuffer("");
    assert(s.size == 0);
    destroy_StringBuffer(s);

    // single character
    s = make_StringBuffer("A");
    assert(s.size == 1);
    assert(s.str[0] == 'A');
    destroy_StringBuffer(s);

    // normal string
    s = make_StringBuffer("Hello");
    assert(s.size == 5);
    assert(s.str[0] == 'H');
    assert(s.str[1] == 'e');
    assert(s.str[2] == 'l');
    assert(s.str[3] == 'l');
    assert(s.str[4] == 'o');
    destroy_StringBuffer(s);

    cout << "... all test_make_StringBuffer tests passed\n";
}

void test_make_copy()
{
    cout << "test_make_copy ...\n";
    // empty string
    StringBuffer s = make_StringBuffer("");
    assert(s.size == 0);
    StringBuffer t = make_copy(s);
    assert(s.size == t.size);
    destroy_StringBuffer(s);
    destroy_StringBuffer(t);

    // single character
    s = make_StringBuffer("A");
    t = make_copy(s);
    assert(s.size == t.size);
    assert(s.str[0] == t.str[0]);
    destroy_StringBuffer(s);
    destroy_StringBuffer(t);

    // normal string
    s = make_StringBuffer("Hello");
    t = make_copy(s);
    assert(s.size == t.size);
    assert(s.str[0] == t.str[0]);
    assert(s.str[1] == t.str[1]);
    assert(s.str[2] == t.str[2]);
    assert(s.str[3] == t.str[3]);
    assert(s.str[4] == t.str[4]);
    destroy_StringBuffer(s);
    destroy_StringBuffer(t);

    cout << "... all test_make_copy tests passed\n";
}

void test_append()
{
    cout << "test_append ...\n";
    // append empty to empty
    StringBuffer empty = make_StringBuffer("");
    append(empty, empty);
    assert(empty.size == 0);
    destroy_StringBuffer(empty);

    // append empty to one character
    StringBuffer s = make_StringBuffer("A");
    empty          = make_StringBuffer("");
    append(s, empty);
    assert(s.size == 1);
    assert(s.str[0] == 'A');
    assert(empty.size == 0);
    destroy_StringBuffer(s);
    destroy_StringBuffer(empty);

    // append one character to empty
    s                   = make_StringBuffer("A");
    StringBuffer result = make_StringBuffer("");
    append(result, s);
    assert(result.size == 1);
    assert(result.str[0] == 'A');
    assert(s.size == 1);
    assert(s.str[0] == 'A');
    destroy_StringBuffer(s);
    destroy_StringBuffer(result);

    // append one character to one character
    s      = make_StringBuffer("A");
    result = make_StringBuffer("B");
    append(result, s);
    assert(result.size == 2);
    assert(result.str[0] == 'B');
    assert(result.str[1] == 'A');
    assert(s.size == 1);
    assert(s.str[0] == 'A');
    destroy_StringBuffer(s);
    destroy_StringBuffer(result);

    // append two regular strings
    result = make_StringBuffer("Hello");
    s      = make_StringBuffer("World");
    append(result, s);
    assert(result.size == 10);
    assert(result.str[0] == 'H');
    assert(result.str[1] == 'e');
    assert(result.str[2] == 'l');
    assert(result.str[3] == 'l');
    assert(result.str[4] == 'o');
    assert(result.str[5] == 'W');
    assert(result.str[6] == 'o');
    assert(result.str[7] == 'r');
    assert(result.str[8] == 'l');
    assert(result.str[9] == 'd');
    assert(s.size == 5);
    assert(s.str[0] == 'W');
    assert(s.str[1] == 'o');
    assert(s.str[2] == 'r');
    assert(s.str[3] == 'l');
    assert(s.str[4] == 'd');
    destroy_StringBuffer(s);
    destroy_StringBuffer(result);

    cout << "... all test_append tests passed\n";
}

int main()
{
    // test_make_StringBuffer();
    // test_make_copy();
    // test_append();
    // demo1();
    // demo2();
    append_performance_test();
} // main
