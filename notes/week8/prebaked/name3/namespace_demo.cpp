// namespace_demo.cpp

#include "kbd_events.h"
#include "render.h"
#include "xavier.h"
#include "yang.h"
#include <iostream>

using namespace std;

int main()
{
    event::print_name();  // Xavier is working in the event namespace
    render::print_name(); // Yang is working in the render namespace

    string s     = "\n\n ";
    bool result1 = event::is_whitespace(s);
    bool result2 = render::is_whitespace(s);

    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl;
}
