// Segment.cpp

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

struct Segment
{
  private:
    Point start;
    Point end;

  public:
    Segment(const Point& start, const Point& end)
    {
        this->start.set_x(start.get_x());
        this->start.set_y(start.get_y());
        this->end.set_x(end.get_x());
        this->end.set_y(end.get_y());
    }

    // constructor with start and end points as integers
    Segment(int start_x, int start_y, int end_x, int end_y)
    {
        this->start.set_x(start_x);
        this->start.set_y(start_y);
        this->end.set_x(end_x);
        this->end.set_y(end_y);
    }


    //
    // copy constructor
    //
    Segment(const Segment& other)
    {
        this->start.set_x(other.start.get_x());
        this->start.set_y(other.start.get_y());
        this->end.set_x(other.end.get_x());
        this->end.set_y(other.end.get_y());
    }

    //
    // setters and getters
    //
    void set_start(const Point& start)
    {
        this->start.set_x(start.get_x());
        this->start.set_y(start.get_y());
    }
    void set_end(const Point& end)
    {
        this->end.set_x(end.get_x());
        this->end.set_y(end.get_y());
    }
    Point get_start() const { return this->start; }
    Point get_end() const { return this->end; }

    //
    // other methods
    //
    double length() const { return this->start.dist_to(this->end); }

    //
    // Since Points store integers, the midpoint will also be an integer, and
    // there may be rounding errors.
    //
    Point midpoint() const
    {
        int mid_x = (this->start.get_x() + this->end.get_x()) / 2;
        int mid_y = (this->start.get_y() + this->end.get_y()) / 2;
        return Point{mid_x, mid_y};
    }

    void print() const
    {
        cout << "Segment: start=" << this->start.toString() << ", end=" << this->end.toString();
    }

    void println() const
    {
        print();
        cout << "\n";
    }
}; // struct Segment

void demo1()
{
    Point p1{1, 2};
    Point p2{3, 4};
    Segment s{p1, p2};
    s.println();
    cout << "  length: " << s.length() << "\n";
    cout << "midpoint: " << s.midpoint().toString() << "\n";

    cout << "\nSetting start to (5, 6) ...\n";
    s.set_start(Point(5, 6));
    s.println();
    cout << "  length: " << s.length() << "\n";
    cout << "midpoint: " << s.midpoint().toString() << "\n";
}

void demo2()
{
    vector<Segment> segments = {Segment(1, 2, 3, 4), Segment(5, 6, 7, 8), Segment(9, 10, 11, 12)};

    for (const Segment& s : segments)
    {
        s.println();
    }
}

int main()
{
    // demo1();
    demo2();
}
