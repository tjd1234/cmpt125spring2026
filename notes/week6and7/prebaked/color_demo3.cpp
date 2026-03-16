// color_demo3.cpp

//
// Same as color_demo2.cpp, but add a brightness function.
//

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

    // getters
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

// TODO: What does : public Color mean?
class Named_color : public Color
{
    string name;

  public:
    Named_color(const string& n, int r, int g, int b)
        : Color(r, g, b), // TODO: What does this do?
          name(n)         // TODO: What does this do?
    {
        // TODO: What should we do here?
    }

    // TODO: What would be a good default constructor? Hint: Color already has a
    // default constructor.
    Named_color() : Color() { name = "black"; }

    // TODO: What would be a good copy constructor? Hint: You want to copy all
    // the inherited variable, and also name. Remember that red, green, and blue
    // are private, so you cannot assign them directly.
    Named_color(const Named_color& other) : Color(other) { name = other.name; }

    // getters
    string get_name() const { return name; }

    // TODO: What's happening here? There is already a to_string method in Color!
    string to_string() const { return name + "=" + Color::to_string(); }

}; // class Named_color

// TODO: Write a function called brightness(c) that returns the brightness of a
// color in the range 0.0 to 1.0. A colors brightness is the sum of the red,
// green, and blue values divided by 255.0 * 3.0.

// Returns the brightness of a color, from 0.0 (darkest) to 1.0 (brightest).
double brightness(const Color& c)
{
    return (c.get_red() + c.get_green() + c.get_blue()) / (255.0 * 3.0);
}

int main()
{
    Named_color truck("firetruck", 255, 0, 0);
    Named_color bird("bird", 200, 230, 2);
    
    cout << truck.get_name() << " brightness: " << brightness(truck) << endl;
    cout << bird.get_name() << " brightness: " << brightness(bird) << endl;

    // TODO: After adding the brightness function, add a color mauve (147, 112,
    // 219) of type Color. Does it work with the brightness function?
    Color mauve(147, 112, 219);
    cout << mauve.to_string() << " brightness: " << brightness(mauve) << endl;
}
