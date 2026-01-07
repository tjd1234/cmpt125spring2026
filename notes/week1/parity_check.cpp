// parity_check.cpp

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    switch (n)
    {
    case 0:
    case 2:
    case 4:
    case 6:
    case 8:
        cout << "even digit";
        break;

    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
        cout << "odd digit";
        break;

    default:
        cout << "not a digit";
    }
    
    cout << '\n';
}
