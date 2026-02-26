// a4.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name         : <full name, exactly as it appears on your SFU id card>
// Student ID # : <full SFU student number>
// SFU Email    : <full SFU email address>
// Platform     : <operating system and compiler you used>
// Editor/IDE   : <editor/IDE you used to write the code>
// Known Bugs   : <describe any bugs or issues you're aware of>
// Missing      : <describe any missing features you're aware of>
// Challenges   : <describe any challenges you faced>
// Help         : <what people and AI tools helped you? If you used AI, please cite the source.>
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations above and in the comments with
// enough detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
/////////////////////////////////////////////////////////////////////////

//
// Do not use any other #includes!
//
#include "Memory.h"
#include <cassert>
#include <iostream>

using namespace std;

//
// ... write helper functions here ...
//

//
// The following are sample "stubs" for print_memory, allocate_first_fit, and
// deallocate. Replace them with your own implementations (make sure to match
// the function headers exactly as given in Memory.h).
//

void print_memory()
{
    for (int i = 0; i < MEM_SIZE; i++)
    {
        cout << mem[i] << " ";
    }
    cout << endl;
}

int allocate_first_fit(int num_bytes)
{
    cout << "allocate_first_fit(" << num_bytes << ") ..." << endl;
    return -1;
}

bool deallocate(int block_index)
{
    cout << "deallocate(" << block_index << ") ..." << endl;
    return false;
}

//
// main should contain your testing code
//
int main()
{
    cout << "Assignment 4: Simulating a Memory Allocator" << endl;
}

/*

Here are some test functions you can use to test your code. The
clear_mem_and_blocks function is not provided but it is not too hard to write:
it sets all memory to free and removes all items from the block list.

There's also the count_free_bytes function which is not required, but it is
useful to implement. As the name says, it returns the number of free bytes in
mem.

Remember, just because these tests pass doesn't mean your code is correct! There
can still be bugs, and so write your code carefully and add some other test
functions.

void test1()
{
    cout << "Test 1: allocate one 100-byte block at once ..." << endl;
    clear_mem_and_blocks();
    assert(count_free_bytes() == 100);
    int a = allocate_first_fit(100);
    assert(a == 0);
    assert(count_free_bytes() == 0);
    assert(allocate_first_fit(5) == -1);
    assert(count_free_bytes() == 0);

    cout << "Test 1: passed\n\n\n";
}

void test2()
{
    cout << "Test 2: allocate/deallocate one 100-byte block at once ..." << endl;
    clear_mem_and_blocks();
    assert(count_free_bytes() == 100);
    int a = allocate_first_fit(100);
    assert(a == 0);
    assert(count_free_bytes() == 0);
    assert(allocate_first_fit(5) == -1);
    assert(count_free_bytes() == 0);

    deallocate(a);
    assert(count_free_bytes() == 100);

    cout << "Test 2: passed\n\n\n";
}

void test3()
{
    cout << "Test 3: allocating 100 1-byte blocks ..." << endl;
    clear_mem_and_blocks();
    assert(count_free_bytes() == 100);
    for (int i = 0; i < 100; i++)
    {
        int a = allocate_first_fit(1);
        assert(a == i);
        assert(count_free_bytes() == 100 - i - 1);
    }
    assert(count_free_bytes() == 0);
    for (int i = 1; i <= 100; i++)
    {
        assert(allocate_first_fit(i) == -1);
    }

    cout << "Test 3: passed\n\n\n";
}

void test4()
{
    cout << "Test 4: allocating/deallocating 100 1-byte blocks ..." << endl;
    clear_mem_and_blocks();
    assert(count_free_bytes() == 100);

    // allocate 100 1-byte blocks
    for (int i = 0; i < 100; i++)
    {
        int a = allocate_first_fit(1);
        assert(a == i);
        assert(count_free_bytes() == 100 - i - 1);
    }
    assert(count_free_bytes() == 0);
    for (int i = 1; i <= 100; i++)
    {
        assert(allocate_first_fit(i) == -1);
    }

    // deallocate 100 1-byte blocks
    for (int i = 0; i < 100; i++)
    {
        bool result = deallocate(i);
        assert(result);
        assert(count_free_bytes() == i + 1);
    }
    assert(count_free_bytes() == 100);

    cout << "Test 4: passed\n\n\n";
}

void test5()
{
    cout << "Test 5: allocating/deallocating 10-byte blocks ..." << endl;
    clear_mem_and_blocks();
    assert(count_free_bytes() == 100);

    int a = allocate_first_fit(10);
    assert(a == 0);
    int b = allocate_first_fit(10);
    assert(b == 10);
    int c = allocate_first_fit(10);
    assert(c == 20);
    int d = allocate_first_fit(10);
    assert(d == 30);
    int e = allocate_first_fit(10);
    assert(e == 40);
    int f = allocate_first_fit(10);
    assert(f == 50);
    int g = allocate_first_fit(10);
    assert(g == 60);
    int h = allocate_first_fit(10);
    assert(h == 70);
    int i = allocate_first_fit(10);
    assert(i == 80);
    int j = allocate_first_fit(10);
    assert(j == 90);
    assert(count_free_bytes() == 0);
    assert(allocate_first_fit(1) == -1);

    assert(deallocate(b));
    assert(count_free_bytes() == 10);

    b = allocate_first_fit(10);
    assert(b == 10);
    assert(count_free_bytes() == 0);

    // remove two blocks in a row
    assert(deallocate(b));
    assert(count_free_bytes() == 10);
    assert(deallocate(c));
    assert(count_free_bytes() == 20);
    b = allocate_first_fit(15);
    assert(b == 10);
    assert(count_free_bytes() == 5);
    c = allocate_first_fit(5);
    assert(c == 25);
    assert(count_free_bytes() == 0);

    // remove two non-adjacent blocks
    assert(deallocate(a));
    assert(deallocate(j));
    assert(count_free_bytes() == 20);

    // even though 20 bytes free, can't allocate a contiguous 20-byte block
    j = allocate_first_fit(20);
    assert(j == -1);
    assert(count_free_bytes() == 20);

    cout << "Test 5: passed\n\n\n";
} // test5

*/
