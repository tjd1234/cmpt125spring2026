// abs_value.cpp

#include <iostream>

using namespace std;

double abs_value(double n)
{
    if (n < 0)
    {
        return -n;
    }
    return n;
}

int main()
{
    double x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "The absolute value of " << x << " is " << abs_value(x) << "\n";
}
