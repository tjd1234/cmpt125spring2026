// color_demo.cpp

#include <iostream>

using namespace std;

//
// Color represents an RGB color, i.e. a tuple of three integers (red, green,
// blue) that represent the intensity of each color. Each value is from 0 to
// 255, where 0 is the minimum intensity and 255 is the maximum intensity.
//
class Color
{
    // TODO: How does C++ know that these are private?
    int red;
    int green;
    int blue;

  public:
    Color(int r, int g, int b)
    {
        // TODO: How could you check that the values are in the range 0-255?
        red   = r;
        green = g;
        blue  = b;
    }

    // TODO: What would be a good default constructor?

    // TODO: What would be a good copy constructor?

    // setters
    int get_red() const { return red; }

    int get_green() const { return green; }

    int get_blue() const { return blue; }

    // TODO: Why no getters?

    // TODO: What should operator== and operator!= do?
    // bool operator==(const Color& other) const
    // {
    //     // ...
    // }

    // bool operator!=(const Color& other) const
    // {
    //     // ...
    // }

    string to_string() const
    {
        // TODO: Is std:: necessary here?
        string r = std::to_string(red);
        string g = std::to_string(green);
        string b = std::to_string(blue);
        return "rgb(" + r + ", " + g + ", " + b + ")";
    }

}; // class Color

int main()
{
    Color truck(255, 0, 0);
    Color bird(0, 255, 0);
    Color cloud(128, 128, 128);
    Color ink(0, 0, 0);
    Color background(255, 255, 255);

    cout << "     truck: " << truck.to_string() << endl;
    cout << "      bird: " << bird.to_string() << endl;
    cout << "     cloud: " << cloud.to_string() << endl;
    cout << "       ink: " << ink.to_string() << endl;
    cout << "background: " << background.to_string() << endl;
}
