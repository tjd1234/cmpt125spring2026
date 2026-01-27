// cpp_append.cpp

#include <climits>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

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
//
// ________________________________________________________
// Executed in  308.58 millis    fish           external
//    usr time    9.07 millis    0.14 millis    8.94 millis
//    sys time    5.03 millis    1.15 millis    3.88 millis

////////////////////////////////////////////////////////////
//
// Performance of standard string append
//
// Performance test for enable1.txt ...
//   Used: 1570508 bytes, 1533 KB (100.0%)
// Unused:       0 bytes,    0 KB (0.0%)
//  Total: 1570508 bytes, 1533 KB ( 100%)
// (8 bits per char)
//
// ________________________________________________________
// Executed in   58.58 millis    fish           external
//    usr time   52.92 millis  115.00 micros   52.81 millis
//    sys time    4.64 millis  977.00 micros    3.67 millis
void append_performance_test()
{
    // const string filename = "tenKwords.txt";
    const string filename = "enable1.txt";
    cout << "Performance test for " << filename << " ...\n";
    string s;
    ifstream words(filename);
    string word;
    while (words >> word)
    {
        s += word;
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

int main()
{
    append_performance_test();
}
