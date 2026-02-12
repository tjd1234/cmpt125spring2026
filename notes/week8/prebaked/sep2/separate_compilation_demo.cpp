// separate_compilation_demo.cpp

//
// This version prepares for separate compilation by putting the method
// definitions outside the class.
//

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// definition of RGB_color
class RGB_color
{
    int red   = 0;
    int green = 0;
    int blue  = 0;

  public:
    // constructors
    RGB_color(); // default constructor
    RGB_color(int r, int g, int b);
    RGB_color(const RGB_color& other); // copy constructor

    // getters
    int get_red() const;
    int get_green() const;
    int get_blue() const;

    void invert();

    string to_string() const;

}; // class RGB_color

// definition of RGB_color
RGB_color::RGB_color()
{
    // red, green, and blue are initialized to 0 above
}

RGB_color::RGB_color(int r, int g, int b) : red(r), green(g), blue(b)
{
    if (red < 0 || red > 255)
        throw runtime_error("bad red value");
    if (green < 0 || green > 255)
        throw runtime_error("bad green value");
    if (blue < 0 || blue > 255)
        throw runtime_error("bad blue value");
}

RGB_color::RGB_color(const RGB_color& other) : RGB_color(other.red, other.green, other.blue) {}

int RGB_color::get_red() const
{
    return red;
}
int RGB_color::get_green() const
{
    return green;
}
int RGB_color::get_blue() const
{
    return blue;
}

void RGB_color::invert()
{
    red   = 255 - red;
    green = 255 - green;
    blue  = 255 - blue;
}

string RGB_color::to_string() const
{
    return "rgb(" + std::to_string(red) + ", " + std::to_string(green) + ", " +
           std::to_string(blue) + ")";
}

int main()
{
    cout << "Separate compilation: methods defined outside the class\n";
    RGB_color c(255, 0, 0);
    cout << "c: " << c.to_string() << endl;
    c.invert();
    cout << "c: " << c.to_string() << endl;
}
