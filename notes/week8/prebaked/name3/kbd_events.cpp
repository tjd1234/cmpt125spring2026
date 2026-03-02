// kbd_events.cpp

#include <string>

using namespace std;

namespace event
{

// Returns true if s is a whitespace character.
bool is_whitespace(const string& s)
{
    return s == " " || s == "\n" || s == "\t" || s == "\r" || s == "\\n" || s == "\\t" ||
           s == "\\r";
}

} // namespace event
