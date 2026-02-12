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
# build the namespace demo program
#

# only called if the .h file has changed since the .o file was last created
xavier.o: xavier.cpp
	g++ $(CPPFLAGS) -c xavier.cpp

yang.o: yang.cpp
	g++ $(CPPFLAGS) -c yang.cpp

# only called if the .cpp file has changed since the .o file was last created
namespace_demo.o: namespace_demo.cpp
	g++ $(CPPFLAGS) -c namespace_demo.cpp

# only called if the .o files have changed since the executable file was last created
namespace_demo: namespace_demo.o xavier.o yang.o
	g++ $(CPPFLAGS) -o namespace_demo namespace_demo.o xavier.o yang.o

# remove the executable file and the object files by typing "make clean:
clean:
	rm -f *.o namespace_demo
