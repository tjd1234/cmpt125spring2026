#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <string>

class Playlist
{
  private:
    //
    // Keep these three variables as is, and use them to implement the
    // Playlist's underlying dynamic array. Don't change them!
    //
    Song* songs{nullptr};
    int size{0};
    int capacity{0};

    //
    // These two lines ensure a Playlist cannot be copied or assigned. Don't
    // change them!
    //
    Playlist(const Playlist&)            = delete;
    Playlist& operator=(const Playlist&) = delete;

    //
    // If you want any private helper methods put their headers here (as shown
    // below), and then define them fully in Playlist.cpp.
    //
    // E.g.:
    //
    // void some_helper_method();
    //
    // int some_other_helper_method(const std::string& s) const;
    //

  public:
    //
    // Make sure to define at least one constructor (one should be enough)
    // and the destructor.
    //
    Playlist();
    ~Playlist();

    //
    // Add the headers of the public methods here, and put their definitions in
    // Playlist.cpp.
    //
    // E.g. you should add this:
    //
    //   int get_size() const;
    //
    // Then put it's implementation in Playlist.cpp.
    //

    // ...

}; // class Playlist

#endif // PLAYLIST_H
