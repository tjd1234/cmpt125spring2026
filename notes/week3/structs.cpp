// structs.cpp

#include <iostream>

using namespace std;

struct Point
{
    double x;
    double y;
};

int main()
{
    Point* p = new Point{3, 1};

    cout << "plain pointer notation:\n";
    cout << "x: " << (*p).x << "\n";
    cout << "y: " << (*p).y << "\n";

    cout << "\narrow notation:\n";
    cout << "x: " << p->x << "\n";
    cout << "y: " << p->y << "\n";

    p->x = 5;
    p->y = 7;
    cout << "\nAfter modifying the point:\n";
    cout << "x: " << p->x << "\n";
    cout << "y: " << p->y << "\n";

    delete p;
}
