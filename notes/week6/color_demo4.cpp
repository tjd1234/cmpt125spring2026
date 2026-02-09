// color_demo4.cpp

// color_demo2.cpp

#include <iostream>

using namespace std;

//
// Color represents an RGB color, i.e. a tuple of three integers (red, green,
// blue) that represent the intensity of each color. Each value is from 0 to
// 255, where 0 is the minimum intensity and 255 is the maximum intensity.
//
class Color
{
    int red;
    int green;
    int blue;

  public:
    Color(int r, int g, int b)
    {
        if (r < 0 || r > 255)
            throw runtime_error("bad red value");
        if (g < 0 || g > 255)
            throw runtime_error("bad green value");
        if (b < 0 || b > 255)
            throw runtime_error("bad blue value");
        red   = r;
        green = g;
        blue  = b;
    }

    // default constructor
    Color()
    {
        red   = 0;
        green = 0;
        blue  = 0;
    }

    // copy constructor
    Color(const Color& other)
    {
        red   = other.red;
        green = other.green;
        blue  = other.blue;
    }

    // setters
    int get_red() const { return red; }

    int get_green() const { return green; }

    int get_blue() const { return blue; }

    bool operator==(const Color& other) const
    {
        return red == other.red && green == other.green && blue == other.blue;
    }

    bool operator!=(const Color& other) const { return !(*this == other); }

    string to_string() const
    {
        string r = std::to_string(red);
        string g = std::to_string(green);
        string b = std::to_string(blue);
        return "rgb(" + r + ", " + g + ", " + b + ")";
    }
}; // class Color

class Named_color
{
    string name;
    Color color;

  public:
    Named_color(const string& n, int r, int g, int b)
        // initializer list
        : name(n), color(r, g, b)
    {
    }

    // default constructor.
    Named_color()
        // initializer list
        : Named_color("black", 0, 0, 0)
    {
    }

    // copy constructor
    Named_color(const Named_color& other)
        // initializer list
        : name(other.name), color(other.color)
    {
    }

    // getters
    string get_name() const { return name; }
    Color get_color() const { return color; }

    // comparison operators: Named_colors are equal if their names and colors
    // are the same
    bool operator==(const Named_color& other) const
    {
        return name == other.name && color == other.color;
    }

    bool operator!=(const Named_color& other) const { return !(*this == other); }

    string to_string() const { return name + "=" + color.to_string(); }

}; // class Named_color

int main()
{
    Named_color truck("firetruck", 255, 0, 0);
    Named_color bird("bird", 0, 255, 0);

    cout << "     truck name: " << truck.get_name() << endl;

    cout << "    truck color: " << truck.get_color().to_string() << endl;
    cout << "truck to string: " << truck.to_string() << endl;

    if (bird == truck)
    {
        cout << "bird and truck are the same color" << endl;
    }
    else
    {
        cout << "bird and truck are different colors" << endl;
    }
}
