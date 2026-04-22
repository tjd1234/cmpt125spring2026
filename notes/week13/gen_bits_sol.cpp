// my_gen_bits_sol.cpp

/* TODO 1

To generate all bits strings of length 1, return: {{0}, {1}}.

To generate all bit strings of length 2, first generate all bit strings of
length 1. Then make two copies of each of those bit strings. Append a 0 to the
first copy, and 1 to the second copy. Then add both copies to the result.

For example:

    {{0}, {1}}      // all bit strings of length 1

    {0} {0}         // make two copies of {0}
    {0, 0} {0, 1}   // append 0 to the first copy, 1 to the second copy
                    // these are the first half of the new length-2 bit strings

    {1} {1}         // make two copies of {1}
    {1, 0} {1, 1}   // append 0 to the first copy, 1 to the second copy
                    // these are the other half of the new length-2 bit strings

    {0, 0}, {0, 1}, {1, 0}, {1, 1}  // the new length-2 bit strings

Now lets generate all bit strings of length 3 in the same way. First generate
all bit strings of length 2:

    {{0, 0}, {1, 0}, {0, 1}, {1, 1}}  // all bit strings of length 2

Then make two copies of each of those bit strings, and append a 0 to the first copy,
and 1 to the second copy:

    {0, 0}    {0, 0}     // make two copies of {0, 0}
    {0, 0, 0} {0, 0, 1}  // append 0 to the first copy, 1 to the second copy

    {1, 0}    {1, 0}     // make two copies of {1, 0}
    {1, 0, 0} {1, 0, 1}  // append 0 to the first copy, 1 to the second copy

    {0, 1}    {0, 1}     // make two copies of {0, 1}
    {0, 1, 0} {0, 1, 1}  // append 0 to the first copy, 1 to the second copy

    {1, 1}    {1, 1}     // make two copies of {1, 1}
    {1, 1, 0} {1, 1, 1}  // append 0 to the first copy, 1 to the second copy

This suggests a general recursive strategy for generating all bit strings of
length n:

1. If n == 1, return {{0}, {1}}.
2. Otherwise, generate all bit strings of length n-1.
3. For each bit string of length n-1:
   - make two copies
   - append 0 to the first copy
   - append 1 to the second copy
   - Add both copies to a result vector.
4. Return the result.

*/

#include <iostream>
#include <vector>
using namespace std;

// Use a type name for readability.
using bitseq = vector<int>;

vector<bitseq> gen_bits(int n)
{
    if (n == 1) // base case
    {
        return {{0}, {1}};
    }
    else
    {
        vector<bitseq> prev = gen_bits(n - 1); // recursive call

        // the new n-length bit strings will go in result
        vector<bitseq> result;

        for (bitseq b : prev)
        {
            // make two copies of b: one we will append 0 to, the other we will
            // append 1 to
            bitseq b0 = b;
            bitseq b1 = b;
            b0.push_back(0);
            b1.push_back(1);

            // add the new bit strings to the result vector
            result.push_back(b0);
            result.push_back(b1);
        }

        return result;
    }
} // gen_bits

void test_gen_bits()
{
    const int N             = 5;
    vector<bitseq> all_bits = gen_bits(N);
    int count               = 0;
    for (bitseq seq : all_bits)
    {
        cout << count << ": ";
        count++;
        for (int b : seq)
            cout << b;
        cout << "\n";
    }
}

/*
TODO 2 Look at the results of the above code, and conjecture and answer to this
question: how many bit strings of length n are there?

Answer: There are 2^n bit strings of length n. This means that gen_bits(n)
returns a vector with 2^n elements.
*/

/*
TODO 3 What are the values of 2^1 through 2^20?

2^1 = 2
2^2 = 4
2^3 = 8
2^4 = 16
2^5 = 32
2^6 = 64
2^7 = 128
2^8 = 256
2^9 = 512
2^10 = 1024
2^11 = 2048
2^12 = 4096
2^13 = 8192
2^14 = 16384
2^15 = 32768
2^16 = 65536
2^17 = 131072
2^18 = 262144
2^19 = 524288
2^20 = 1048576

2^n gets big quickly! It grows exponentially.
*/

/*
TODO 3 What is 2^100 ?

Answer:
2^100 = 1 267 650 600 228 229 401 496 703 205 376   // spaces added for readability

This is over 10^30 (in comparison, the age of the universe in seconds is
"only" about 10^18 seconds). If we compute 1 trillion (10^12) bit strings per
second, it would take about 10^30 / 10^12 = 10^18 seconds to finish. i.e.
about 30 billion years.

*/

// TODO 4 Write a function print(v) that prints the elements of v without a \n
// at the end.
void print(const vector<int>& v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
}

// TODO 5 Write a function sum(v) that returns the sum of the elements in v.
int sum(const vector<int>& v)
{
    int total = 0;
    for (int x : v)
    {
        total += x;
    }
    return total;
}

/*
TODO 6 Consider this list of numbers: 7, 4, 1, 3, 5, 1, 2, 9

Can you partition them into two sets such that each number is in one set, and
the sum of the sets is the same (or as close as possible to the same)?

Answer: Yes, you could arrange them like this: 2 3 4 7  | 1 1 5 9
*/

/*
TODO 7 How can you use bit patterns to answer questions like the previous one?
Try to find a way using the numbers 2, 6, 4.

Answer: Imagine a bit above each number. If the bit is 0, the number is in the
first set, and if the bit is 1, the number is in the second set. If you do this
for all n-bit patterns you will get all possible partitions of the numbers. For
example:

    0 0 0 
    2 6 4   {2, 6, 4} | {0}  sum diff = 12

    0 0 1
    2 6 4   {2, 6}    | {4}  sum diff = 4

    0 1 0
    2 6 4   {2, 4}    | {6}  sum diff = 0

    0 1 1
    2 6 4   {2}       | {6, 4}  sum diff = 8

    1 0 0
    2 6 4   {6, 4}    | {2}  sum diff = 8

    1 0 1
    2 6 4   {6}       | {2, 4}  sum diff = 0

    1 1 0
    2 6 4   {4}       | {2, 6}  sum diff = 4

    1 1 1
    2 6 4   {}        | {2, 6, 4}  sum diff = 12

Now we can find the minimum sum difference, and that gives us the best partition
*/

// Uses gen_bits to find a partition of nums into two disjoint subsets with the
// same sum (or sum as close as possible to the same).
void find_partition(const vector<int>& nums)
{
    const int N             = nums.size();
    vector<bitseq> all_bits = gen_bits(N);
    int best_diff           = INT_MAX;
    vector<int> best_a;
    vector<int> best_b;
    for (bitseq seq : all_bits)
    {
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < N; i++)
        {
            if (seq[i] == 0)
            {
                a.push_back(nums[i]);
            }
            else
            {
                b.push_back(nums[i]);
            }
        }
        int diff = abs(sum(a) - sum(b));
        if (diff < best_diff)
        {
            best_diff = diff;
            best_a    = a;
            best_b    = b;
        }
    } // for
    cout << "Best partition: ";
    print(best_a);
    cout << " | ";
    print(best_b);
    cout << " diff=" << best_diff << "\n";
}

void test_find_partition()
{
    vector<int> nums = {7, 4, 1, 3, 5, 1, 2, 9};
    cout << "Numbers: ";
    print(nums);
    cout << "\n";
    find_partition(nums);
}

/*
TODO 8 In O-notation, what is the running time of find_partition?

Answer: The running time of find_partition is at least O(2^n), because it
generates all 2^n bit patterns.
*/

/*
TODO 9 How long would it take to find the best partition of 100 numbers using
find_partition?

Answer: find_partition would check 2^100 partitions, which we saw above would
take a few billion years assuming we could calculate 1 trillion bit strings per
second.
*/

/*
TODO 10 Suppose you wanted to know if there were any values for a, b, and c that
made the logical expression a && (b or !c) true. How could you do these using
bit patterns?

Answer: There are 3 variables, and so if you generate all 3-bit bit patterns,
you can generate all possible true/false values for a, b, and c. You can then
check if any of the bit patterns make the expression a && (b or !c) true. 

For example, if 0 means false and 1 means true, then:

    0     0     0  
    a && (b or !c) = false

    0     0     1
    a && (b or !c) = false

    0     1     0
    a && (b or !c) = false

    0     1     1
    a && (b or !c) = false

    1     0     0
    a && (b or !c) = true

    1     0     1
    a && (b or !c) = false

    1     1     0
    a && (b or !c) = true

    1     1     1
    a && (b or !c) = true

You can see that, yes, if you set a = true, b = false, and c = false, then the
entire expression is true.

This is known as the **boolean satisfiability problem** (or **SAT** for short).
It is one of the most well-studied problems in computer science, and even has
many practical applications in things like scheduling and circuit design. 
*/

/*
TODO 11 If you use gen_bits to generate all n-bit patterns to solve SAT, what is
the running time in O-notation?

Answer: The running time of this approach is O(2^n), because it generates all
2^n bit patterns.
*/

/*
TODO 12 Surprising fact: for both the number partition problem and the SAT
problem, the best known algorithms for solving them have a worst-case running
time of O(2^n). No one currently knows if there is a faster algorithm for either
of them.
*/

/*
TODO 13 Even more surprising fact: number partition and SAT are both
**NP-complete problems**. Among other things, this means that if there is a
polynomial time algorithm (i.e. O(n^k) for some fixed k) for either of them,
then there must be a polynomial time algorithm for the other.

It turns out that many important and useful problems are NP-complete, and all
NP-complete problems have that property that if you can find a polynomial time
algorithm for *one* of them, then there must be a polynomial time algorithm for
the others.

Currently, no one knows if there is a polynomial time algorithm any NP-complete
problem. Most computer scientists doubt that there is, but no one has been able
to prove it.
*/

/*
TODO 14 Is every problem solvable by an algorithm?

Answer: No! For example, imagine a boolean function called check(P) that takes
the source code of a C++ program P as input. The check function returns true if
P has an infinite loop (i.e. there is some input to P that causes it to go into
an infinite loop), and false if it always stops. A function like check(P) might
be useful in debugging.

But in the 1930s computer scientist Alan Turing proved that there the check
function cannot be written. Not just that it would be difficult to write, but
that there does not exist an algorithm that can solve that problem.

This is an example of an **undecidable problem**. To help solve this problem
Alan Turing created the idea of a **Turing machine**, which is a mathematical
model of a computer. Turing machines are still used today to study the theory of
computation.

*/

int main()
{
    test_gen_bits();
    // test_find_partition();
}
