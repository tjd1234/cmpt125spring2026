// get_name.cpp

#include <iostream>
#include <string>

using namespace std;

string get_name(const string& prompt = "What's your name? ") {
    cout << prompt;
    string name;
    getline(cin, name);
    return name;
}

int main()
{
    string name = get_name();
    cout << "Hello, " << name << "!\n";
}
