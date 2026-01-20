// scratch.py

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> tokens;
    cout << "--> ";
    string tok;
    while (cin >> tok) {
        tokens.push_back(tok);
    }
    for (string t : tokens) {
        cout << t << " ";
    }
    cout << "\n";
}