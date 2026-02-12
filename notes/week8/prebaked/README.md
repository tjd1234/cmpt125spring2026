# Sample Code

## Separate compilation

- [sep1](sep1/): everything in a single file
- [sep2](sep2/): method bodies defined out the class (still in a single file)
- [sep3](sep3/): `RGB_color` split into two files:
  [RGB_color.h](sep3/RGB_color.h), [RGB_color.cpp](sep3/RGB_color.cpp). Each
  main program includes the `.h` file. The [makefile](sep3/makefile) has new
  rules for compiling and linking the program.

## Namespaces

- [name1](name1/): Shows a linker error due to the same function name being
  defined in two different files. Type `make namespace_demo` to build the
  program, and `./namespace_demo` to run it.
- [name2](name2/): Uses namespaces to avoid name collisions. Type
  `make namespace_demo` to build the program, and `./namespace_demo` to run it.
- [name3](name3/): Adds more separately compiled files to show that namespaces
  can be split across multiple files. Type `make namespace_demo` to build the
  program, and `./namespace_demo` to run it.

## Exceptions

## Recursion
