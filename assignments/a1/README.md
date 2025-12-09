# Assignment 1: A Postfix Calculator

Your task is to to implement a a desktop calculator that evaluates postfix
expressions. A postfix expression is an expression where the operator appears
*after* the operands. For example, `2 3 *` is a postfix expression that
evaluates to `6`, and `4 1 - 2 +` evaluates to `5`. Compared to our usual infix
expressions (e.g. `(2 + 3) * 4`), postfix is interesting because it doesn't
require parentheses or precedence rules (like "do multiplication before
addition"), and it can be evaluated using a **stack**. So it is much easier to
evaluate than our usual infix expressions.

For the calculator, a **token** is either a number (like `2` or `-3.14`) or an
operator (like `+`, `dup`, or `help`). The user types in tokens separated by
space characters, e.g. `2 3 *` is a valid expression, but `2 3*` is a error.

Sequences of tokens are evaluated from left to right. There is a stack that is
used to store the numbers and the results of the operators, and it is initially
empty. For each token, the following actions are taken:

- If the token is a number, it is pushed onto the top of the stack.
- If the token is not a number, it is:
  - A **binary** operator (like `+`, `-`, `*`, or `/`), the top two elements of
    the stack are popped off, the operator is applied to them, and the result is
    pushed back onto the stack. It's an error if the stack has less than two
    elements.
  - A **unary** operator (like `abs`, `dup`, or `drop`), the top element of the
    stack is popped off, the operator is applied to it, and the result is pushed
    back onto the stack. It's an error if the stack is empty.
  - A **command** (like `clear`, `print`, or `help`), then
    the corresponding action is taken

For example:

```
--> 2 3 * 
6
```

`-->` is the calculator prompt, indicating it's waiting for the to type some
tokens. The user types in `2 3 *` and presses enter. The expressing is evaluated
like this:

- `2` is a number, so it is pushed onto the stack. The stack is now `[2]`.
- `3` is a number, so it is pushed onto the stack. The stack is now `[2, 3]`.
- `*` is a binary operator, so the top two elements of the stack are popped off,
  the operator is applied to them, and the result is pushed back onto the stack.
  The stack is now `[6]`.

The final result, `6`, is printed to the console.

Here we calculate `1/2 + 1/3`:

```
--> 1 2 / 1 3 / +
0.833333
```

Brackets are never needed in postfix expressions. So, for example, `2 + 3 * 4` is:

```
--> 2 3 4 * +
14
```

And `(2 + 3) * 4` is:

```
--> 2 3 + 4 *
20
```

You can square numbers like this:

```
--> 5 dup *
25
```

In the expression `5 dup *`, 5 is pushed onto the stack, and then `dup` pushes a
copy of 5 onto the stack, so that stack is now `[5, 5]`. Then `*` pops the top
two elements, multiplies them, and pushes the result back onto the stack,
leaving `[25]`.


## Getting Started

Put all your code for this assignment into [a1.cpp](a1.cpp). Implement all the
requested methods and functions using the *exact* name and parameters. You can
add other helper functions/methods if you need them.

## Supported Tokens

Implement all the following tokens.

### Binary Tokens

Binary tokens pop the *top two* elements off the stack and push the result back
onto the stack. If the stack has less than two elements, it's an error.

- `+` is addition. It pops the top two elements of the stack, adds them, and
  pushes the result back onto the stack.
- `-` is subtraction. It pops the top two elements of the stack, subtracts the
  second element from the first, and pushes the result back onto the stack. The
  order is the top element minus the second element.
- `*` is multiplication. It pops the top two elements of the stack, multiplies
  them, and pushes the result back onto the stack.
- `/` is division. It pops the top two elements of the stack, divides the first
  element by the second, and pushes the result back onto the stack. It's an
  error if the second element is 0.

If enter is pressed after any of these tokens, then the top element of the stack
is printed to the console.

### Unary Tokens

Unary tokens pop the *top* element off the stack and push the result back onto
the stack. If the stack is empty, it's an error.

- `abs` is absolute value. It pops the top element of the stack, takes the
  absolute value of it, and pushes the result back onto the stack.
- `sin` is sine. It pops the top element of the stack, takes the sine of it, and
  pushes the result back onto the stack.
- `cos` is cosine. It pops the top element of the stack, takes the cosine of it,
  and pushes the result back onto the stack.
- `sqrt` is square root. It pops the top element of the stack, takes the square
  root of it, and pushes the result back onto the stack. It's an error if the
  element is negative.

If enter is pressed after any of these tokens, then the top element of the stack
is printed to the console.

- `dup` duplicates the top element of the stack. It pushes a copy of the top
  element onto the stack.
- `drop` removes the top element of the stack. It pops the top element of the
  stack and discards it.

### Command Tokens

- `clear` or `c` clears the stack, i.e. removes all elements from the stack.
- `print` or `p` prints the stack, i.e. prints all elements of the stack to the
  console.
- `help` or `h` or `?` prints a help message to the console.
- `quit` or `q` or `exit` quits the program.

## Error Handling

When an error occurs, you should `throw` a `runtime_error` with a helpful error
message. This should never crash the program, and the user should only see the
error message. For example:

```
RPN Calculator (type 'h' for help, 'q' to quit)
--> 2 +
error: pop from empty list
--> c
--> 2 0 /
error: division by zero
--> c
--> p
stack is empty
--> sin
error: can't pop from empty list
```

Your program's internal representation of numbers should be a `double`. So it is
possible for overflow to occur if the user enters very large numbers, e.g.:

```
--> 1e100 1e100 1e100 1e100 * * *
inf
```

## Submit Your Work

Please put all your code into [a1.cpp](a1.cpp), and submit it on
[Canvas](canvas.sfu.ca). Implement **all** the methods and functions exactly as
described, otherwise the marking software will probably give you 0!

Submit only [a1.cpp](a1.cpp), and no other files. The marker will use the
standard [makefile](makefile) to compile it.


## Basic Requirements

- **Your programs must compile using the [assignment makefile](makefile)**. A
  standard Linux/Unix compiler will be used, e.g. g++ or c++. If your program
  doesn't compile, then the marker might spend a minute or two checking it to
  see if the problem is a simple mistake or typo. But if they can't quickly fix
  it, then they will give it 0. Ensuring your program compiles is your
  responsibility.

  Please note that if you choose to develop your programs without using the
  [assignment makefile](makefile), you are still responsible for ensuring it
  compiles and runs properly with it.

- **The student info and statement of originality is filled out in each file**.
  The program might not be marked if this missing or incomplete.

## Checking for Memory Errors

Memory-related errors are common in C++ programming, and so here aer some tools
to help you find them.

### Valgrind (Linux)

`valgrind` helps find memory leaks and other memory errors. After you install
it, you can run it like this:

```bash
$ valgrind ./a1
  
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
$ leaks -atExit -- ./a1
  
// ... lots of output ...

leaks Report Version: 4.0, multi-line stacks
Process 52960: 187 nodes malloced for 15 KB
Process 52960: 0 leaks for 0 total leaked bytes.
```

### Compiler Sanitizers

The compiler has some built-in tools to help find memory errors. You can use
them like this:

```bash
$ g++ -fsanitize=address -fsanitize=leak -g a1.cpp -o a1
```

On some systems `-fsanitize=leak` is not supported, so in that case use just
`-fsanitize=address`.

Also, tools like `leaks` might not work if you compile with
`-fsanitize=address`. So remove that option when you use `leaks`.

## Hints

- You can use `getline` to read in a line of input from the console.
- Use `try` and `catch` to handle errors.
- Test as you go. Whenever you add a new feature, test it to make sure it works
  before moving on to the next feature.

## Marking Scheme

### **5 marks: Overall source code readability**
- All code is sensibly and consistently indented, and all lines are 100
  characters in length, or less.
- Whitespace is used to group related pieces of a code to make it easier for
  humans to read. All whitespace has a discernible purpose.
- Variable and function names are self-descriptive.
- Appropriate features of C++ are used, as discussed in class and in the notes.
  **Note** If you use a feature that we haven't discussed in class, **you must
  explain it in a comment**, even if you think it's obvious.
- Comments are used when needed to explain code whose purpose is not obvious
  from the code itself. There should be *no* commented-out code from previous
  versions.

### **2 marks: Overall source code performance and memory usage**
- No unnecessary work is done.
- No unnecessary memory is used.

### **18 marks: Source code correctness**

- **1 mark**: printing a welcome message when the program starts, saying
  something like "RPN Calculator (type 'h' for help, 'q' to quit)"
- **1 mark**: correctly pushing numbers onto the stack.
- **4 marks**: 1 mark for correctly implementing each of the 4 binary tokens
- **6 marks**: 1 mark for correctly implementing each of the 6 unary tokens
- **4 marks**: 1 mark for correctly implementing each of the 4 command tokens.
  For tokens with more than one name (e.g. `clear` or `c`), you only get 1 mark
  if you implement all the names. If one, or more of the names missing, that's a
  0.5 deduction.
- **2 marks**: correctly throwing errors with `throw runtime_error`, and for
  printing helpful error messages to the console.

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
