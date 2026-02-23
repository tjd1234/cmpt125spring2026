// RGB_color.h

// Important! #pragma once prevents multiple inclusion. 
#pragma once

#include <string>

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

    std::string to_string() const;

}; // class RGB_color
