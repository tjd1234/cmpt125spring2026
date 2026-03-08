// Point.cpp

#include <iostream>

using namespace std;

struct Point
{
  private:
    int x;
    int y;

  public:
    // default constructor
    Point()
    {
        // using -> notation to distinguish between the class variables
        // parameters
        this->x = 0;
        this->y = 0;
    }

    // constructor
    Point(int x, int y)
    {
        this->x = x; // x = x would be wrong
        this->y = y; // y = y would be wrong
    }

    // copy constructor
    Point(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
    }

    // setters and getters
    void set_x(int x) { this->x = x; }
    void set_y(int y) { this->y = y; }
    int get_x() const { return this->x; }
    int get_y() const { return this->y; }

    double dist_to(const Point& other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    // test if two points are equal or not
    bool operator==(const Point& other) const { return x == other.x && y == other.y; }
    bool operator!=(const Point& other) const { return !(*this == other); }

    string toString() const { return "Point(" + to_string(x) + ", " + to_string(y) + ")"; }

}; // struct Point

void demo1()
{
    Point origin;
    Point p1{1, 2};
    Point p2{p1};

    cout << "origin: " << origin.toString() << "\n";
    cout << "p1: " << p1.toString() << "\n";
    cout << "p2: " << p2.toString() << "\n";
    cout << "p1 == p2: " << (p1 == p2) << "\n";
    cout << "p1 != p2: " << (p1 != p2) << "\n";

    cout << "distance between p1 and origin: " << p1.dist_to(origin) << "\n";
}

int main()
{
    demo1();
}
