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
    

    // TODO: What would be a good copy constructor? Hint: You want to copy all
    // the inherited variable, and also name. Remember that red, green, and blue
    // are private, so you cannot assign them directly.
    

    // getters
    string get_name() const { return name; }

    // TODO: What's happening here? There is already a to_string method in Color!
    string to_string() const { return name + "=" + Color::to_string(); }

}; // class Named_color

int main()
{
    Named_color truck("firetruck", 255, 0, 0);
    Named_color bird("bird", 0, 255, 0);

    cout << "     truck name: " << truck.get_name() << endl;

    // TODO: Notice the setters called here were not defined in the Named_color class.
    cout << "    truck color: " << truck.get_red() << ", " << truck.get_green() << ", "
         << truck.get_blue() << endl;
    cout << "truck to string: " << truck.to_string() << endl;

    // TODO: Note that operator== was not defined in the Named_color class.
    if (bird == truck)
    {
        cout << "bird and truck are the same color" << endl;
    }
    else
    {
        cout << "bird and truck are different colors" << endl;
    }
}
