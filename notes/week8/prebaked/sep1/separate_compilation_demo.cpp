// separate_compilation_demo.cpp

//
// This version puts everything into a single file, with no separate compilation.
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
    // default constructor
    RGB_color()
    {
        // red, green, and blue are initialized to 0 above
    }

    RGB_color(int r, int g, int b) : red(r), green(g), blue(b)
    {
        if (red < 0 || red > 255)
            throw runtime_error("bad red value");
        if (green < 0 || green > 255)
            throw runtime_error("bad green value");
        if (blue < 0 || blue > 255)
            throw runtime_error("bad blue value");
    }

    // copy constructor
    RGB_color(const RGB_color& other) : RGB_color(other.red, other.green, other.blue) {}

    // getters
    int get_red() const { return red; }
    int get_green() const { return green; }
    int get_blue() const { return blue; }

    void invert()
    {
        red   = 255 - red;
        green = 255 - green;
        blue  = 255 - blue;
    }

    string to_string() const
    {
        return "rgb(" + std::to_string(red) + ", " + std::to_string(green) + ", " +
               std::to_string(blue) + ")";
    }

}; // class RGB_color

int main()
{
    cout << "Separate compilation: methods defined inside the class\n";
    RGB_color c(255, 0, 0);
    cout << "c: " << c.to_string() << endl;
    c.invert();
    cout << "c: " << c.to_string() << endl;
}
