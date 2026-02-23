// RGB_color.cpp

#include "RGB_color.h"
#include <stdexcept>
#include <string>

using namespace std;

// default constructor
RGB_color::RGB_color()
{
    // red, green, and blue are initialized in the class
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

// copy constructor
RGB_color::RGB_color(const RGB_color& other) : RGB_color(other.red, other.green, other.blue) {}

// getters
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
