// render.cpp

#include "render.h"
#include <string>

using namespace std;

namespace render
{

// Returns true if every character in s is a whitespace character.
bool is_whitespace(const string& s)
{
    for (char c : s)
    {
        if (!(c == ' ' || c == '\n' || c == '\t' || c == '\r'))
        {
            return false;
        }
    }
    return true;
}

} // namespace render
