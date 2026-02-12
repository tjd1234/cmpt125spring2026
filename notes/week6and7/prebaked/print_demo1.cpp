// print_demo.cpp

#include <iostream>
#include <string>

using namespace std;

class Point
{
  private:
    double x;
    double y;

  public:
    // default constructor
    Point() : x(0), y(0) {}

    // copy constructor
    Point(const Point& other) : x(other.x), y(other.y) {}

    Point(double a, double b) : x(a), y(b) {}

    // getters
    double get_x() const { return x; }
    double get_y() const { return y; }

    void print() const { cout << '(' << x << ", " << y << ')'; }

    void println() const
    {
        print();
        cout << "\n";
    }
}; // class Point

class Person
{
    string name;
    int age;

  public:
    Person(const string& n, int a) : name{n}, age{a}
    {
        if (age < 0)
            throw runtime_error("negative age");
    }

    string get_name() const { return name; }
    int get_age() const { return age; }

    void print() const { cout << "Name: '" << name << ", Age: " << age; }

    void println() const
    {
        print();
        cout << "\n";
    }
}; // class Person

class Reading
{
  private:
    string loc;
    double temp;

  public:
    Reading(const string& l, double t) : loc{l}, temp{t} {}

    string get_loc() const { return loc; }
    double get_temp() const { return temp; }

    void print() const { cout << temp << " degrees at " << loc; }

    void println() const
    {
        print();
        cout << "\n";
    }
}; // class Reading

int main()
{
    Point a{1, 2};
    a.println();

    Person b{"Katja", 22};
    b.println();

    Reading c{"backyard", 2.4};
    c.println();
}
