# Assignment 2: An Dynamic String Array

Your task is to to implement a dynamic string array using functions.

Implement each of the functions described in the header file [a2.h](a2.h).

Each function comes with a test function (in [a2.cpp](a2.cpp)) that you can you
use to help check the correctness of the function. **Remember**: it's possible
that a function could pass all the tests but still be incorrect. You can add
more tests if you like.

You can also add helper functions if needed. Just make sure to implement all the
requested functions.

So to do this assignment you should pick a function from the header file
[a2.h](a2.h), implement it in [a2.cpp](a2.cpp), and then run the test function
in [a2.cpp](a2.cpp) to check if it's (hopefully!) correct. Repeat this process
for each function in [a2.h](a2.h), and submit [a2.cpp](a2.cpp) on Canvas when
you're done.


## Submit Your Work

Please put all your code into [a2.cpp](a2.cpp), and submit it on Canvas.
Implement **all** the functions exactly as described (*don't* change the
function headers!), otherwise the marking software might give you 0.

Submit only [a2.cpp](a2.cpp), and no other files. The marker will use the
standard [makefile](makefile) to compile it, and a copy of [a2.h](a2.h) will be
in the same folder as [a2.cpp](a2.cpp) when it's compiled, so your program can
use the `str_vec` struct.

[cmpt_error.h](cmpt_error.h) will also be in the same folder as [a2.cpp](a2.cpp)
when it's tested.

The marker will run their own test functions to check the correctness of your
code.


## Basic Requirements

- **Your programs must compile using the [assignment makefile](makefile)**. A
  standard Linux/Unix compiler will be used, e.g. g++ or c++. If your program
  doesn't compile, then the marker might spend a minute or two checking it to
  see if the problem is a simple mistake or typo. But if they can't quickly and
  easily fix it, then they will mark it as 0. Ensuring your program compiles is
  your responsibility.

  If you choose to develop your programs without using the 
  [assignment makefile](makefile), you are still responsible for ensuring it 
  compiles and runs properly with g++ and the given [makefile](makefile).

- **The student info and statement of originality is in each file**. If either
  is missing/incomplete, then the program might not be marked.

  A copy of [cmpt_error.h](cmpt_error.h) will be in the same folder as
  [a2.cpp](a2.cpp) when it's compiled, so your program can use `cmpt::error`.

## Checking for Memory Errors

Memory-related errors are common in C++ programming, and so here are some tools
to help you find them.

### Valgrind (Linux)

`valgrind` helps find memory leaks and other memory errors. After you install
it, you can run it like this:

```bash
$ valgrind ./a2
  
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
$ leaks -atExit -- ./a2
  
// ... lots of output ...

leaks Report Version: 4.0, multi-line stacks
Process 52960: 187 nodes malloced for 15 KB
Process 52960: 0 leaks for 0 total leaked bytes.
```

### Compiler Sanitizers

The compiler has some built-in tools to help find memory errors. You can use
them like this:

```bash
$ g++ -fsanitize=address -fsanitize=leak -g a2.cpp -o a2
```

On some systems `-fsanitize=leak` is not supported, so in that case use just
`-fsanitize=address`.

Also, tools like `leaks` might not work if you compile with
`-fsanitize=address`. So remove that option when you use `leaks`.

## Hints

- A number of the functions can be implemented using other functions from the
  assignment. For example, `append_new` can be implemented using `append`.
- In [a2.cpp](a2.cpp), there is the commented-out function `austenTest()` that
  you can use to help test your class when it's done.
- Don't skip checking for memory errors! Even the best programmers use tools
  like `valgrind` and `leaks`.

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

### **20 marks: Source code correctness**
To get full marks, your functions must pass all the test cases the marker uses
for that question. The marker may use test cases not given in the assignment.

Correctly implementing each of these functions is worth 1 mark:

```cpp
make_str_vec()
make_str_vec(int n, const string& s)
make_str_vec(const string arr[], int n)
make_str_vec(const str_vec& other)
deallocate(str_vec& v)
to_str(const str_vec& v)
equals(const str_vec& a, const str_vec& b)
double_capacity(str_vec& v)
free_space(const str_vec& v)
squish(str_vec& v)
append(str_vec& v, const string& s)
append(str_vec& v, const str_vec& other)
count(const str_vec& v, const string& s)
contains(const str_vec& v, const string& s)
append_new(str_vec& v, const string& s)
append_new(str_vec& v, const str_vec& other)
remove(str_vec& v, int loc)
remove_first(str_vec& v, const string& s)
reverse(str_vec& v)
sort(str_vec& v)
```

### Deductions
- up to **-2 mark** if your program does not compile using the [assignment
  makefile](makefile). Depends on the severity of the error.
- **-5 marks** if your program has any memory leaks or other memory errors (e.g.
  found using `valgrind` or `leaks`).
- **-1 mark** if your file does not have the correct name, or you submit it in
  the incorrect format.
- up to **-3 marks** if you do not include your full name, email, and SFU ID in
  the header of your file.
- **a score of 0** if you submit a "wrong" non-working file, and then *after the
  due date* submit the "right" file. If you can provide evidence that you
  finished the assignment on time, then it may be marked (probably with a late
  penalty).
