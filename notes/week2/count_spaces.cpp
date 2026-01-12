// count_spaces.cpp

#include <iostream>
#include <string>

using namespace std;

int count_spaces(const string& s) {
    int num_spaces = 0;
    for (char c : s) {
        if (c == ' ') {
            num_spaces++;
        }
    }
    return num_spaces;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Number of spaces: " << count_spaces(s) << "\n";
}
