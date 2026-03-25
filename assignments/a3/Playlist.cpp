#include "Playlist.h"
#include <iostream>
//
// Put other necessary #includes here.
//

// ...

using namespace std;

//
// If you need helper functions, make them static (i.e. start with 'static') so
// that they have internal linkage, i.e. they are not visible outside this file.
//
// E.g.:
//
// static std::string some_helper_function(const std::string& s) {
//     // ...
// }
//

//
// Put the definitions of the the Playlist methods here, both public and
// private.
//
// Put definitions (if any) of private methods here. They would look like this:
//
// void Playlist::some_helper_method() {
//     // ...
// }
//
// int Playlist::some_other_helper_method(const std::string& s) const {
//     // ...
// }
//

//
// Make sure to implement a sensible default constructor. The one here is just a
// placeholder.
//
Playlist::Playlist()
{
    cout << "Playlist constructor called ... implement me!" << endl;
    cout << "    size: " << size << endl;     // just
    cout << "capacity: " << capacity << endl; // for
    cout << "   songs: " << songs << endl;    // show
}

//
// Make sure to implement a sensible destructor.
//
Playlist::~Playlist()
{
    cout << "Playlist destructor called ... implement me!" << endl;
}

//
// Put implementations of other public Playlist methods here.
//
// E.g. here is the implementation of the get_size() method whose header is in
// Playlist.h:
//
//   int Playlist::get_size() const;
//

// ...
