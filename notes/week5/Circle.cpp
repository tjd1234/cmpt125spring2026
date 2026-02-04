// circle.cpp

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
    Point(double x, double y)
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

struct Circle
{
  private:
    Point center;
    double radius;

  public:
    Circle(double x, double y, double radius)
    {
        this->center.set_x(x);
        this->center.set_y(y);
        this->radius = radius;
    }

    // constructor with default center at origin
    Circle(double radius)
    {
        this->center.set_x(0);
        this->center.set_y(0);
        this->radius = radius;
    }

    // copy constructor
    Circle(const Circle& other)
    {
        this->center.set_x(other.center.get_x());
        this->center.set_y(other.center.get_y());
        this->radius = other.radius;
    }

    // setters and getters
    void set_x(double x) { this->center.set_x(x); }
    void set_y(double y) { this->center.set_y(y); }
    void set_radius(double radius) { this->radius = radius; }
    double get_x() const { return this->center.get_x(); }
    double get_y() const { return this->center.get_y(); }
    double get_radius() const { return this->radius; }

    // other methods
    double diameter() const { return 2 * this->radius; }
    double circumference() const { return 2 * 3.1415926 * this->radius; }
    double area() const { return 3.1415926 * this->radius * this->radius; }

    void print() const
    {
        cout << "Circle: center=" << this->center.toString() << ", radius=" << this->radius;
    }

    void println() const
    {
        print();
        cout << "\n";
    }

}; // struct Circle

void demo1()
{
    Circle c{1.0, 2.0, 3.0};
    c.println();
    cout << "     diameter: " << c.diameter() << "\n";
    cout << "circumference: " << c.circumference() << "\n";
    cout << "         area: " << c.area() << "\n";
}

int main()
{
    demo1();
}
