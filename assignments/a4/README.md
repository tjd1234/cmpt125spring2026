# Assignment 4: Simulating a Memory Allocator

In this assignment, you will build a dynamic memory allocation simulation that
shows how `new` and `delete` could work in C++.

For simplicity, memory is a sequence of 100 bytes, represented as an array of
100 `char`s in [Memory.h](Memory.h). Each `char` is considered one byte of
memory, and each byte is either *free* (a `.`) or *used* (a `#`).

We'll call an allocated contiguous sequence of `num_bytes` bytes a **block**.

In [a4.cpp](a4.cpp), you should write at least these three functions:

- `void print_memory()` prints the state of memory as a grid of characters. A
  `#` means a used byte, a `.` means a free byte. Draw it in rows as a 10x10
  grid, as shown in the examples below, and include the "legend" on the right
  side of the grid.

  It's a good idea to write this function first, so you can see how blocks are
  allocated.

- `int allocate_first_fit(int num_bytes)` allocates a new contiguous block of
  memory of size `num_bytes`. It does this by finding the *first* contiguous
  free sequence of `num_bytes` bytes. If the allocation is successful, then the
  index of the first byte is returned. This is analogous to the pointer returned
  by `new`.

  If no contiguous sequence of `num_bytes` free bytes can be found, then the
  allocation fails and returns `-1`.

  If `num_bytes` is less than, or equal to 0, then the allocation fails and
  returns `-1`.

  As the function name suggests, this is a "first fit" allocator. It finds the
  first free sequence of `num_bytes` bytes and allocates it. There are other
  strategies, such as "best fit" and "worst fit", but for this function you
  should implement "first fit".

  Note that the return value of a successful allocation will be in the range 0
  to `MEM_SIZE - 1`, and `-1` if the allocation fails.

- `bool deallocate(int block_index)` de-allocates the block of memory starting
  at location `block_index` and it's size is whatever was recorded when it was
  allocated. `block_index` must be the first byte of a block allocated by
  `allocate_first_fit`. All the memory locations of that block are set to free,
  and `true` (indicating success) is returned. If `block_index` is not the
  address of the first byte of a block currently allocated by
  `allocate_first_fit`, then nothing is done and `false` (indicating failure) is
  returned.

  Note that `block_index` is the index of the first byte of the block, and must,
  at least, be in the range 0 to `MEM_SIZE - 1`.

## Example Output

Here's what memory looks like when no blocks are allocated:

```
    Memory (100 bytes)
   0 1 2 3 4 5 6 7 8 9 
 0 . . . . . . . . . . 
 1 . . . . . . . . . .    . free byte
 2 . . . . . . . . . .    # used byte
 3 . . . . . . . . . . 
 4 . . . . . . . . . .  100 free bytes
 5 . . . . . . . . . .    0 used bytes
 6 . . . . . . . . . . 
 7 . . . . . . . . . . 
 8 . . . . . . . . . . 
 9 . . . . . . . . . . 
Blocks: none
```

Now suppose you run this code to allocate a 6-byte block:

```cpp
int a = allocate_first_fit(6);  // allocate 6 bytes
```

Then the value of `a` is 0, and `print_memory()` prints this:

```
    Memory (100 bytes)
   0 1 2 3 4 5 6 7 8 9 
 0 # # # # # # . . . . 
 1 . . . . . . . . . .    . free byte
 2 . . . . . . . . . .    # used byte
 3 . . . . . . . . . . 
 4 . . . . . . . . . .   94 free bytes
 5 . . . . . . . . . .    6 used bytes
 6 . . . . . . . . . . 
 7 . . . . . . . . . . 
 8 . . . . . . . . . . 
 9 . . . . . . . . . . 
Blocks: 
   0-5 (6 bytes)
```

Now allocate a 5-byte block:

```cpp
int b = allocate_first_fit(5);  // allocate 5 bytes
```

Then the value of `b` is 6, and `print_memory()` prints this:

```
    Memory (100 bytes)
   0 1 2 3 4 5 6 7 8 9 
 0 # # # # # # # # # # 
 1 # . . . . . . . . .    . free byte
 2 . . . . . . . . . .    # used byte
 3 . . . . . . . . . . 
 4 . . . . . . . . . .   89 free bytes
 5 . . . . . . . . . .   11 used bytes
 6 . . . . . . . . . . 
 7 . . . . . . . . . . 
 8 . . . . . . . . . . 
 9 . . . . . . . . . . 
Blocks: 
   0-5 (6 bytes)
   6-10 (5 bytes)
```

Now suppose you deallocate the block starting at index 0:

```cpp
bool result = deallocate(a);  // a is 0
print_memory();
```

Then the value of `result` is `true`, and `print_memory()` prints this:

```
    Memory (100 bytes)
   0 1 2 3 4 5 6 7 8 9 
 0 . . . . . . # # # # 
 1 # . . . . . . . . .    . free byte
 2 . . . . . . . . . .    # used byte
 3 . . . . . . . . . . 
 4 . . . . . . . . . .   95 free bytes
 5 . . . . . . . . . .    5 used bytes
 6 . . . . . . . . . . 
 7 . . . . . . . . . . 
 8 . . . . . . . . . . 
 9 . . . . . . . . . . 
Blocks: 
   6-10 (5 bytes)
```

Suppose you run this code:

```cpp
bool result = deallocate(7);  // not the first byte of a block!
print_memory();
```

Then the value of `result` is `false` because there is no block whose first
byte is at index 7. Memory is unchanged:

```
    Memory (100 bytes)
   0 1 2 3 4 5 6 7 8 9 
 0 . . . . . . # # # # 
 1 # . . . . . . . . .    . free byte
 2 . . . . . . . . . .    # used byte
 3 . . . . . . . . . . 
 4 . . . . . . . . . .   95 free bytes
 5 . . . . . . . . . .    5 used bytes
 6 . . . . . . . . . . 
 7 . . . . . . . . . . 
 8 . . . . . . . . . . 
 9 . . . . . . . . . . 
Blocks: 
   6-10 (5 bytes)
```

Since there are only 95 free bytes, this allocations fails:

```cpp
int c = allocate_first_fit(97);  // not enough free bytes!
```

Then the value of `c` is `-1` because there are not 97 contiguous free bytes
anywhere in memory. Memory is unchanged.

It is possible that a memory allocation could fail even though there are enough
total free bytes. For example, suppose we start with all free bytes and run this
code:

```cpp
int a = allocate_first_fit(10);
int b = allocate_first_fit(80);
int c = allocate_first_fit(10);
```

Memory looks like this:

```
    Memory (100 bytes)
   0 1 2 3 4 5 6 7 8 9 
 0 # # # # # # # # # # 
 1 # # # # # # # # # #    . free byte
 2 # # # # # # # # # #    # used byte
 3 # # # # # # # # # # 
 4 # # # # # # # # # #    0 free bytes
 5 # # # # # # # # # #  100 used bytes
 6 # # # # # # # # # # 
 7 # # # # # # # # # # 
 8 # # # # # # # # # # 
 9 # # # # # # # # # # 
Blocks: 
   0-9 (10 bytes)
   10-89 (80 bytes)
   90-99 (10 bytes)
```

Now let's deallocate blocks `a` and `c`:

```cpp
deallocate(a);
deallocate(c);
```

Now memory is this:

```
    Memory (100 bytes)
   0 1 2 3 4 5 6 7 8 9 
 0 . . . . . . . . . . 
 1 # # # # # # # # # #    . free byte
 2 # # # # # # # # # #    # used byte
 3 # # # # # # # # # # 
 4 # # # # # # # # # #   20 free bytes
 5 # # # # # # # # # #   80 used bytes
 6 # # # # # # # # # # 
 7 # # # # # # # # # # 
 8 # # # # # # # # # # 
 9 . . . . . . . . . . 
Blocks: 
   10-89 (80 bytes)
```

In total there are 20 free bytes, but the largest contiguous free sequence is
only 10 bytes. So if you try to allocate a block of 11 or more bytes, it will
fail:

```cpp
int d = allocate_first_fit(15);  // fails!
```

The value of `d` is `-1` because there are not 15 contiguous free bytes anywhere in
memory.

This problem of having enough free bytes but not a contiguous sequence of free
bytes is called **fragmentation**. You don't need to do anything about it in
this assignment, but you might want to think about how you would solve this
problem.

## Requirements

- **You must use the `mem` array for memory**. While it is 100 bytes for this
  assignment, the code for `allocate_first_fit` and `deallocate` should work for
  any bigger size of memory.

- **DO NOT use `new`/`delete`/`malloc`/`free` in this assignment**. The purpose
  this assignment is to implemented simplified versions of such functions to see
  how they work.

- **DO NOT use `vector` or any other container classes in this assignment**.
  Since memory is fixed at 100 bytes, there is no need to use dynamic memory or
  other complex data structures.

- **DO NOT use any other `#include`s in this assignment**. Use only the ones
  given in [a4.cpp](a4.cpp).

## Hints

- You'll need to keep track of the blocks in memory. An array of block structs
  is a good idea, where the struct contains the start index and the number of
  bytes of the block.

- You should probably write some helper functions to help with memory management
  and other tasks. Look at the test functions in [a4.cpp](a4.cpp) for some
  ideas.

- It's easy to make off-by-one errors when working with indices. So check and
  test your code carefully. To help trace errors, you can, for instance, use
  `cout` statements or `assert` statements to help you find errors. It's also
  helpful to compile your code with the `-fsanitize=address` option to help
  catch some kinds of address errors.

## Submit Your Work

Please put all your code into [a4.cpp](a4.cpp). Use the `mem` array defined in
[Memory.h](Memory.h) to manage memory, and don't change that file in any way.

You must implement `print_memory`, `allocate_first_fit`, and `deallocate` using
exactly the given function headers. 

Include a `main()` function that tests the `MemoryAllocator` class. The marker
will test your code by running your `main()` function, and also using their own
test functions and tools (e.g. `valgrind` or `leaks` to check for memory
errors).

The marker will compile your file with [assignment 4 makefile](makefile), and a
copy of [Memory.h](Memory.h) and [cmpt_error.h](cmpt_error.h) will be in the
same folder.

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

## Checking for Memory Errors

Memory-related errors are common in C++ programming, and so here are some tools
to help you find them.

### Valgrind (Linux)

`valgrind` helps find memory leaks and other memory errors. After you install
it, you can run it like this:

```bash
$ valgrind ./a4
  
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
$ leaks -atExit -- ./a4
  
// ... lots of output ...

leaks Report Version: 4.0, multi-line stacks
Process 52960: 187 nodes malloced for 15 KB
Process 52960: 0 leaks for 0 total leaked bytes.
```

### Compiler Sanitizers

The compiler has some built-in tools to help find memory errors. You can use
them like this:

```bash
$ g++ -fsanitize=address -fsanitize=leak -g a4.cpp -o a4
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

### 4 marks: `print_memory`
- **1 mark** correctly prints the memory as a grid of `#` (used bytes) and `.`
  (free byte) as shown in the examples
- **1 mark** correctly prints the legend on the right side of the grid as shown
  in the examples
- **1 mark** correctly prints the row of numbers at the top, and the column of
  numbers on the left
- **1 mark** correctly prints the blocks of memory that are currently allocated;
  the order of the blocks does not matter, and if no blocks are allocated
  then "Blocks: none" is printed

### 4 marks: `allocate_first_fit`
- if there is a contiguous sequence of `num_bytes` bytes of free memory:
  - **1 mark** correctly marks the bytes in `mem` as used
  - **1 mark** returns the index of the first byte of the block
- **1 mark**: if there is no contiguous sequence of `num_bytes` bytes of free
  memory, returns `-1` (and does not change memory)
- **1 mark** correctly implements the "first fit" strategy

## 4 marks: `deallocate`
- if `block_index` is the index of the first byte of a block allocated by
  `allocate_first_fit`:
  - **1 mark** marks the bytes in `mem` as free
  - **1 mark** returns `true`
- if `block_index` is not the index of the first byte of a block allocated by
  `allocate_first_fit`:
  - **1 mark** does not change memory
  - **1 mark** returns `false`

## 2 marks: allocated block management

- **1 mark** for correctness
- **1 mark** for efficiency, linear time or better

## Deductions
- up to **-5 marks** in total if you make any changes to [Memory.h](Memory.h),
  the required functions, or add any `#include`s other than the ones provided.
- up to **-2 mark** if your program does not compile using the [assignment
  makefile](makefile). Depends on the severity of the error.
- **-5 marks** if your program has any memory leaks or other memory errors (e.g.
  found using `valgrind` or `leaks`).
- **-1 mark** if your file does not have the correct name, or you submit it in
  an incorrect format.
- up to **-3 marks** if you do not include your full name, email, and SFU ID in
  the header of your file.
- **a score of 0** if you submit a "wrong" non-working file, and then *after the
  due date* submit the "right" file. If you can provide evidence that you
  finished the assignment on time, then it may be marked (probably with a late
  penalty).
