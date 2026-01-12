// clamp.cpp

#include <iostream>
#include <string>

using namespace std;

// restricts n to the range [min, max]
void clamp(double& n, double min, double max) {
    if (n < min) {
        n = min;
    }
    if (n > max) {
        n = max;
    }
}

int main()
{
    const double min = 1;
    const double max = 10;
    cout << "Enter a number: ";
    double x;
    cin >> x;
    clamp(x, min, max);
    cout << "clamped between " << min << " and " << max << ": " << x << "\n";
}
