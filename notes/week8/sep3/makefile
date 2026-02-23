####################################################################
#
# Makefile for CMPT 125 Spring 2026, SFU Surrey.
#
#####################################################################

# Set the C++ compiler options:
#   -std=c++17 
#    compiles using the C++17 standard
#   -Wall
#    turns on all warnings
#   -Wextra 
#    turns on even more warnings
#   -Werror
#    causes warnings to be errors 
#   -Wfatal-errors
#    stops the compiler after the first error
#   -Wno-sign-compare
#    turns off warnings for comparing signed and unsigned numbers
#   -Wnon-virtual-dtor
#    warns about non-virtual destructors
#   -g
#    puts debugging info into the executables (makes them larger)
#   -fsanitize=address
#    turns on address sanitization; don't use if using macOS leaks
#   -fsanitize=leak
#    turns on leak sanitization
#    (some compilers don't support -fsanitize)
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor #-fsanitize=address #-fsanitize=leak #-g

#
# build the separate_compilation_demo program
#

# only called if the .cpp file has changed since the .o file was last created
separate_compilation_demo.o: separate_compilation_demo.cpp
	g++ $(CPPFLAGS) -c separate_compilation_demo.cpp

# only called if the .cpp file has changed since the .o file was last created
RGB_color.o: RGB_color.cpp
	g++ $(CPPFLAGS) -c RGB_color.cpp

# only called if the .o files have changed since the executable file was last created
separate_compilation_demo: separate_compilation_demo.o RGB_color.o
	g++ $(CPPFLAGS) -o separate_compilation_demo separate_compilation_demo.o RGB_color.o

#
# build the demo2 program
#

# only called if the .cpp file has changed since the .o file was last created
demo2.o: demo2.cpp
	g++ $(CPPFLAGS) -c demo2.cpp

# only called if the .o files have changed since the executable file was last created
demo2: demo2.o RGB_color.o
	g++ $(CPPFLAGS) -o demo2 demo2.o RGB_color.o

# remove the executable file and the object files by typing "make clean:
clean:
	rm -f separate_compilation_demo separate_compilation_demo.o RGB_color.o
	rm -f demo2 demo2.o RGB_color.o
