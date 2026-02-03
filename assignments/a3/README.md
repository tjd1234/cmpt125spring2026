# Assignment 3: Managing a Playlist

In this assignment, you will create a program to manage a playlist of songs. You
will create a class called `Playlist` that stores a dynamic list of `Song`
objects. When created, the playlist will read the songs from a file, and when
destroyed, it will save the songs (which might be different from the original)
to the file. The user can interactively print, add, remove, shuffle, and find
songs in the playlist.

This assignment has multiple files:

- [a3.cpp](a3.cpp) is where you will implement the main program. It uses the
  `Playlist` class to manage the playlist, and when run it will work like the
  sample run below.
- [Playlist.h](Playlist.h) is a header file that stores the headers (i.e.
  *declarations*) of the methods of the `Playlist` class.
- [Playlist.cpp](Playlist.cpp) stores the implementations (i.e. *definitions*)
  of the `Playlist` class (see those files for examples). **Important**: Read
  the comments in [Playlist.h](Playlist.h) and [Playlist.cpp](Playlist.cpp)
  carefully! You are not allowed to change some variables and methods. You will
  also need to implement other methods of your choice to help implement the main
  program.
- [Song.h](Song.h) is a header file that stores the `Song` struct for
  representing a song. **Don't change this file in any way!**.
- [songs.txt](songs.txt) and [songs200.txt](songs200.txt) contain sample data
  for testing.

This assignment also uses **separate compilation**. [Playlist.cpp](Playlist.cpp)
and [a3.cpp](a3.cpp) are compiled separately. The [makefile](makefile) for this
assignment is already set up to do this. After you download the files, typing
`make a3` should do this:

```bash
$ make a3
g++ -c a3.cpp -o a3.o               # compile a3.cpp to a3.o
g++ -c Playlist.cpp -o Playlist.o   # compile Playlist.cpp to Playlist.o
g++ a3.o Playlist.o -o a3           # link a3.o and Playlist.o to make executable a3
# the usual g++ options have been removed for brevity

$ ./a3
Playlist Manager!
Not yet implemented ...
Playlist constructor called ... implement me!
    size: 0
capacity: 0
   songs: 0x0
Playlist destructor called ... implement me!
```

To make the executable file `a3`, [a3.cpp](a3.cpp) and
[Playlist.cpp](Playlist.cpp) are first compiled into `.o` object files. Then
those object files are linked together to make the executable file `a3`, which
you can run.

You can also run the command `make clean` to remove the executable file and the
`.o` object files if you want to re-create them.

## Sample Run

Below is a sample run of the program that shows how each feature works. Your
program's output does not need to be identical, but it should work similarly and
be at least as easy to use (make it as user-friendly as you can!).

```
Playlist Manager!

Loading playlist from songs.txt...
Playlist has 5 songs.

Commands:
    1 or p :  Print the playlist
    2 or a :  Add a song
    3 or r :  Remove a song
    4 or s :  Shuffle the songs
    5 or ft:  Find a song by title
    6 or fa:  Find a song by artist
    7 or q :  Quit

--> p
(print)
All You Need Is Love, The Beatles, 3:47
Shake It Off, Taylor Swift, 3:39
Help!, The Beatles, 2:18
Smells Like Teen Spirit, Nirvana, 5:01
Let It Be, The Beatles, 4:03

--> 2
(add)
Enter title: Gummy Shoes
Enter artist: The Targets
Enter length: 255

--> p
(print)
All You Need Is Love, The Beatles, 3:47
Shake It Off, Taylor Swift, 3:39
Help!, The Beatles, 2:18
Smells Like Teen Spirit, Nirvana, 5:01
Let It Be, The Beatles, 4:03
Gummy Shoes, The Targets, 4:15

--> 3
(remove)
[1] All You Need Is Love, The Beatles, 3:47
[2] Shake It Off, Taylor Swift, 3:39
[3] Help!, The Beatles, 2:18
[4] Smells Like Teen Spirit, Nirvana, 5:01
[5] Let It Be, The Beatles, 4:03
[6] Gummy Shoes, The Targets, 4:15

Pick the song # to remove: 4

--> p
(print)
All You Need Is Love, The Beatles, 3:47
Shake It Off, Taylor Swift, 3:39
Help!, The Beatles, 2:18
Let It Be, The Beatles, 4:03
Gummy Shoes, The Targets, 4:15

--> 4
(shuffle)
Playlist shuffled in random order!

--> p
(print)
Let It Be, The Beatles, 4:03
All You Need Is Love, The Beatles, 3:47
Gummy Shoes, The Targets, 4:15
Shake It Off, Taylor Swift, 3:39
Help!, The Beatles, 2:18

--> ft
(find by title)
Enter title: It
Let It Be, The Beatles, 4:03
Shake It Off, Taylor Swift, 3:39

--> 6
(find by artist)
Enter artist: Swift
Shake It Off, Taylor Swift, 3:39

--> p
(print)
Let It Be, The Beatles, 4:03
All You Need Is Love, The Beatles, 3:47
Gummy Shoes, The Targets, 4:15
Shake It Off, Taylor Swift, 3:39
Help!, The Beatles, 2:18

--> q
(quit)
Goodbye!
```

For testing purpose, the file [songs200.txt](songs200.txt) is provided, which
contains 200 songs. (You can ask AI to create more test data like this if you
like)

## Submit Your Work

All your code  for this assignment should be in the files [a3.cpp](a3.cpp),
[Playlist.h](Playlist.h) and [Playlist.cpp](Playlist.cpp). When they're ready,
compress then into a single zip file named `a3.zip`. Then submit `a3.zip` on
Canvas.

*Don't* submit any other files. A copy of [Song.h](Song.h) will be in the same
folder as your code when the marker tests your program.

The assignment [makefile](makefile) will create `a3.zip` for you if you type
`make submit`:

```bash
$ make submit
rm -f a3.zip
zip a3.zip a3.cpp Playlist.h Playlist.cpp
  adding: a3.cpp (deflated 57%)
  adding: Playlist.h (deflated 58%)
  adding: Playlist.cpp (deflated 61%)
```

[a3.cpp](a3.cpp) should include a `main()` function that runs the program, and
so after compiling your files the marker will run `./a3`. The marker will test
your code with their own tests cases, and may run it with tools like `valgrind`
or `leaks` to check for memory errors.

## Basic Requirements

- **Your programs must compile using the [assignment makefile](makefile)**. A
  standard Linux/Unix compiler will be used, e.g. g++ or c++. If your program
  doesn't compile, then the marker might spend a minute or two checking it to
  see if the problem is a simple mistake or typo. But if they can't quickly and
  easily fix it, then they will mark it as 0. Ensuring your program compiles is
  your responsibility.

  Please note that if you choose to develop your programs without using the
  [assignment makefile](makefile), you are still responsible for ensuring it
  compiles and runs properly with it.

- **The student info and statement of originality is in each file**. If either
  is missing/incomplete, then the program might not be marked.

  A copy of [cmpt_error.h](cmpt_error.h) will be in the same folder as
  [a3.cpp](a3.cpp) when it's compiled, so your program can use `cmpt::error`
  if necessary.

## Checking for Memory Errors

Memory-related errors are common in C++ programming, and so here aer some tools
to help you find them.

### Valgrind (Linux)

`valgrind` helps find memory leaks and other memory errors. After you install
it, you can run it like this:

```bash
$ valgrind ./a3
  
// ... lots of output ... 
```

A program is considered to have no memory error if:

- In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and `possibly
  lost` must all be 0.

- The `ERROR SUMMARY` reports 0 errors.

- It is usually okay if **still reachable** reports a non- zero number of bytes.

### Leaks (macOS)

`leaks` is a tool that comes with macOS and that can help you find memory leaks
and other memory errors. You can run it like this:

```bash
$ leaks -atExit -- ./a3
  
// ... lots of output ...

leaks Report Version: 4.0, multi-line stacks
Process 52960: 187 nodes malloced for 15 KB
Process 52960: 0 leaks for 0 total leaked bytes.
```

### Compiler Sanitizers

The compiler has some built-in tools to help find memory errors. You can use
them like this:

```bash
$ g++ -fsanitize=address -fsanitize=leak -g a3.cpp -o a3
```

On some systems `-fsanitize=leak` is not supported, so in that case use just
`-fsanitize=address`.

Also, tools like `leaks` might not work if you compile with
`-fsanitize=address`. So remove that option when you use `leaks`.


## Marking Scheme

### **5 marks: Overall source code readability**
- All code is sensibly and consistently indented, and all lines are 100
  characters in length, or less.
- Whitespace is used to group related pieces of a code to make it easier for
  humans to read. All whitespace should have a purpose.
- Variable and function names are self-descriptive.
- Appropriate features of C++ are used, as discussed in class and in the notes.
  **Note** If you use a feature that we haven't discussed in class, **you must
  explain it in a comment**, even if you think it's obvious.
- Comments are used when needed to explain chunks of code whose purpose is not
  obvious from the code itself. There should be *no* commented-out code from
  previous versions.

### **2 marks: Overall source code performance and memory usage**
- No unnecessary work is done.
- No unnecessary memory is used.

### **10 marks: Source code correctness**
To get full marks, your functions must pass all the test cases the marker uses
for that question. The marker may use test cases not given in the assignment.

- **1 mark** for loading the playlist from `songs.txt` when the program starts.
  Assume each line is tab-separated (i.e there is `\t` between the title,
  artist, and length), and the first string is the title, the second string is
  the artist, and the third string is the length in seconds. See
  [songs.txt](songs.txt) for an example. If there is no `songs.txt`, or if it is
  empty, the program should start with an empty playlist. You can assume the
  file is always properly formatted.
- **1 mark** for each of these features correctly implemented:
  - printing the playlist when the user enters `p` or `1`
  - adding a song to the playlist when the user enters `a` or `2`
  - removing a song from the playlist when the user enters `r` or `3`
  - shuffling the playlist when the user enters `s` or `4`
  - finding a song by title when the user enters `ft` or `5`
  - finding a song by artist when the user enters `fa` or `6`
  - quitting the program when the user enters `q` or `7`
- **1 mark**: re-prompt the user in a friendly way if they enter an invalid
  command.
- **1 mark** for correctly displaying songs in a user-friendly way using a
  comma-separated format (instead of the tab-separated format of `songs.txt`),
  and for writing the time in the format `MM:SS`, e.g. 100 seconds is "1:40" or
  "01:40".

- **1 mark** for correctly implementing a useful *default constructor* for the
  `Playlist` class.
- **1 mark** for correctly implementing a useful *destructor* for the `Playlist`
  class, e.g. saving the current playlist to `songs.txt` when the program ends
  and deleting the underlying array.
- **1 mark** for correctly using at least one useful `const` method in the
  `Playlist` class.
- **3 mark** for correctly implementing `Playlist` using the given `Song*`
  array, size, and capacity variables. Make sure to use them sensibly and keep
  them `private`.

### Deductions
- up to **-2 marks** if you change the two `delete`-ed methods in
  [Playlist.h](Playlist.h).
- up to **-2 mark** if your program does not compile using the [assignment
  makefile](makefile). Depends on the severity of the error.
- up to **-5 marks** if your program has any memory leaks or other memory errors
  (e.g. found using `valgrind` or `leaks`).
- **-1 mark** if your file does not have the correct name, or you submit it in
  the incorrect format.
- up to **-3 marks** if you do not include your full name, email, and SFU ID in
  the header of your file.
- **a score of 0** if you submit a "wrong" non-working file, and then *after the
  due date* submit the "right" file. If you can provide evidence that you
  finished the assignment on time, then it may be marked (probably with a late
  penalty).

### Hints

- You will need to decide what code to put in [a3.cpp](a3.cpp) and what code to
  put in [Playlist.cpp](Playlist.cpp). Sometimes the decision might not be
  obvious, and different approaches can work. Aim for code that is simple and
  readable.
- When you add a new method to the `Playlist` class, you need to add the header
  in [Playlist.h](Playlist.h) and the implementation in
  [Playlist.cpp](Playlist.cpp). The names and types of the method match exactly.
  See those files for examples.
- Use the provided sample data in [songs.txt](songs.txt) and
  [songs200.txt](songs200.txt) to test your program. You can easily make more
  test data by asking AI.
- Since the program has raw pointers, make sure to test it for memory errors
  using `valgrind` or `leaks` (on macOS).
