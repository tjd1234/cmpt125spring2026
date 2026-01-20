// a2.cpp

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
// These are the only permitted includes: don't include anything else.
//

#include "a2.h"
#include "cmpt_error.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Assignment 2 ...\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
// Below is test code you can use to check your str_vec implementation. You //
// don't need to use it, and you can change it in any way you like.
//
// As always: just because your code passes all these tests doesn't mean it's //
// correct! Bugs can still sneak in. No doubt many of the tests can be improved.
//
/////////////////////////////////////////////////////////////////////////////////

/*

//
// Test functions for the str_vec implementation.
//
// These are provided for you to use to test your str_vec implementation. You
// don't need to use them, and you can change them in any way you like.
//
// As always: just because your code passes all these tests doesn't mean it's
// correct! Bugs can still sneak in. No doubt many of the tests can be improved.
//

void test_make_str_vec_1()
{
    cout << "Testing make_str_vec() ... ";
    str_vec a = make_str_vec();
    assert(a.sz == 0);
    assert(a.cap == 10);
    deallocate(a);
    cout << "PASSED\n";
}

void test_make_str_vec_2()
{
    cout << "Testing make_str_vec(n, s) ... ";
    str_vec a = make_str_vec(10, "hello");
    assert(a.sz == 10);
    assert(a.cap == 20);
    for (int i = 0; i < 10; i++)
    {
        assert(a.arr[i] == "hello");
    }
    deallocate(a);
    cout << "PASSED\n";
}

void test_make_str_vec_3()
{
    cout << "Testing make_str_vec(arr, n) ... ";
    string arr[] = {"hello", "world", "foo", "bar"};
    str_vec a    = make_str_vec(arr, 4);
    assert(a.sz == 4);
    assert(a.cap == a.sz + 10);
    for (int i = 0; i < 4; i++)
    {
        assert(a.arr[i] == arr[i]);
    }
    deallocate(a);
    cout << "PASSED\n";
}

void test_make_str_vec_4()
{
    cout << "Testing make_str_vec(other) ... ";
    str_vec a = make_str_vec(10, "hello");
    str_vec b = make_str_vec(a);
    assert(b.sz == 10);
    assert(b.cap == 20);
    for (int i = 0; i < 10; i++)
    {
        assert(b.arr[i] == "hello");
    }
    deallocate(a);
    deallocate(b);
    cout << "PASSED\n";
}

void test_to_str()
{
    cout << "Testing to_str() ... ";
    string arr[] = {"apple", "cat", "mouse"};
    str_vec a    = make_str_vec(arr, 3);
    assert(a.sz == 3);
    assert(a.cap == a.sz + 10);
    for (int i = 0; i < 3; i++)
    {
        assert(a.arr[i] == arr[i]);
    }
    assert(to_str(a) == "{\"apple\", \"cat\", \"mouse\"}");

    str_vec b = make_str_vec();
    assert(to_str(b) == "{}");

    str_vec c = make_str_vec(1, "hello");
    assert(to_str(c) == "{\"hello\"}");

    deallocate(a);
    deallocate(b);
    deallocate(c);

    cout << "PASSED\n";
}

void test_equals()
{
    cout << "Testing equals() ... ";
    string arr[] = {"apple", "cat", "mouse"};
    str_vec a    = make_str_vec(arr, 3);
    str_vec b    = make_str_vec(arr, 3);

    assert(equals(a, a));
    assert(equals(a, b));
    assert(equals(b, a));

    str_vec c = make_str_vec();
    assert(equals(c, c));
    assert(!equals(a, c));
    assert(!equals(c, a));

    str_vec d = make_str_vec(1, "hello");
    assert(equals(d, d));
    assert(!equals(a, d));
    assert(!equals(d, a));

    deallocate(a);
    deallocate(b);
    deallocate(c);
    deallocate(d);
    cout << "PASSED\n";
}

void test_double_capacity()
{
    cout << "Testing double_capacity() ... ";
    str_vec a = make_str_vec(10, "hello");
    assert(a.cap == 20);
    assert(a.sz == 10);

    double_capacity(a);
    assert(a.cap == 40);
    assert(a.sz == 10);

    double_capacity(a);
    assert(a.cap == 80);
    assert(a.sz == 10);

    deallocate(a);
    cout << "PASSED\n";
}

void test_free_space()
{
    cout << "Testing free_space() ... ";
    str_vec a = make_str_vec();
    assert(free_space(a) == 10);

    str_vec b = make_str_vec(10, "hello");
    assert(free_space(b) == 10);

    deallocate(a);
    deallocate(b);
    cout << "PASSED\n";
}

void test_squish()
{
    cout << "Testing squish() ... ";
    str_vec a = make_str_vec(10, "hello");
    assert(free_space(a) == 10);
    squish(a);
    assert(free_space(a) == 0);

    str_vec b = make_str_vec();
    squish(b);
    assert(free_space(b) == 0);

    deallocate(a);
    deallocate(b);
    cout << "PASSED\n";
}

void test_append1()
{
    cout << "Testing append(v, s) ... ";
    str_vec a = make_str_vec();
    append(a, "hello");
    assert(a.sz == 1);
    assert(a.cap == 10);
    assert(a.arr[0] == "hello");

    append(a, "world");
    assert(a.sz == 2);
    assert(a.cap == 10);
    assert(a.arr[0] == "hello");
    assert(a.arr[1] == "world");

    int f = free_space(a);
    for (int i = 0; i < f; i++)
    {
        append(a, to_string(i));
    }
    assert(a.sz == 10);
    assert(a.cap == 10);

    append(a, "end");
    assert(a.sz == 11);
    assert(a.cap == 20);

    deallocate(a);
    cout << "PASSED\n";
}

void test_append2()
{
    cout << "Testing append(v, w) ... ";
    str_vec a = make_str_vec();
    append(a, a);
    assert(a.sz == 0);
    assert(a.cap == 10);

    str_vec b = make_str_vec(1, "hello");
    append(b, a);
    assert(b.sz == 1);
    assert(b.cap == 10);
    assert(b.arr[0] == "hello");

    append(a, b);
    assert(a.sz == 1);
    assert(a.cap == 10);
    assert(a.arr[0] == "hello");

    assert(b.sz == 1);
    assert(b.cap == 10);
    assert(b.arr[0] == "hello");

    deallocate(a);
    deallocate(b);
    cout << "PASSED\n";
}

void test_count()
{
    cout << "Testing count(v, s) ... ";
    str_vec a = make_str_vec();
    assert(count(a, "hello") == 0);

    str_vec b = make_str_vec(1, "world");
    assert(count(b, "world") == 1);
    assert(count(b, "hello") == 0);

    str_vec c = make_str_vec(10, "hello");
    assert(count(c, "hello") == 10);
    assert(count(c, "world") == 0);

    deallocate(a);
    deallocate(b);
    deallocate(c);

    cout << "PASSED\n";
}

void test_contains()
{
    cout << "Testing contains(v, s) ... ";
    str_vec a = make_str_vec();
    assert(!contains(a, "hello"));

    str_vec b = make_str_vec(1, "world");
    assert(contains(b, "world"));
    assert(!contains(b, "hello"));

    string arr[] = {"hello", "cat", "world"};
    str_vec c    = make_str_vec(arr, 3);
    assert(contains(c, "hello"));
    assert(contains(c, "cat"));
    assert(contains(c, "world"));
    assert(!contains(c, "dog"));

    deallocate(a);
    deallocate(b);
    deallocate(c);

    cout << "PASSED\n";
}

void test_append_new_1()
{
    cout << "Testing append_new(v, s) ... ";
    str_vec a = make_str_vec();
    append_new(a, "hello");
    assert(a.sz == 1);
    assert(contains(a, "hello"));

    append_new(a, "hello");
    assert(a.sz == 1);
    assert(contains(a, "hello"));

    append_new(a, "world");
    assert(a.sz == 2);
    assert(contains(a, "hello"));
    assert(contains(a, "world"));

    append_new(a, "world");
    assert(a.sz == 2);
    assert(contains(a, "hello"));
    assert(contains(a, "world"));

    deallocate(a);

    cout << "PASSED\n";
}

void test_append_new_2()
{
    cout << "Testing append_new(v, other) ... ";

    str_vec a = make_str_vec();
    append_new(a, a);
    assert(a.sz == 0);

    append(a, "hello");
    assert(a.sz == 1);
    assert(a.arr[0] == "hello");

    append_new(a, a);
    assert(a.sz == 1);
    assert(a.arr[0] == "hello");

    append(a, "world");
    assert(a.sz == 2);
    assert(a.arr[0] == "hello");
    assert(a.arr[1] == "world");

    append_new(a, a);
    assert(a.sz == 2);
    assert(a.arr[0] == "hello");
    assert(a.arr[1] == "world");

    string arr[] = {"hello", "dog", "world"};
    str_vec b    = make_str_vec(arr, 3);
    append_new(b, b);
    assert(b.sz == 3);

    append_new(b, b);
    assert(b.sz == 3);
    assert(b.arr[0] == "hello");
    assert(b.arr[1] == "dog");
    assert(b.arr[2] == "world");

    // a == {hello, world}
    // b == {hello, dog, world}
    assert(a.sz == 2);
    assert(a.arr[0] == "hello");
    assert(a.arr[1] == "world");
    append_new(a, b);
    assert(a.sz == 3);
    assert(a.arr[0] == "hello");
    assert(a.arr[1] == "world");
    assert(a.arr[2] == "dog");

    deallocate(a);
    deallocate(b);
    cout << "PASSED\n";
}

void test_remove()
{
    cout << "Testing remove(v, loc) ... ";
    str_vec a = make_str_vec();
    try
    {
        remove(a, 0);
        assert(false);
    }
    catch (const std::runtime_error& e)
    {
        // good, show throw!
    }
    catch (...)
    {
        assert(false);
    }
    assert(a.sz == 0);

    str_vec b = make_str_vec(1, "hello");
    remove(b, 0);
    assert(b.sz == 0);

    str_vec c = make_str_vec(10, "hello");
    while (c.sz > 0)
    {
        remove(c, 0);
    }
    assert(c.sz == 0);

    string arr[] = {"hello", "world", "cat", "dog"};
    str_vec d    = make_str_vec(arr, 4);
    remove(d, 2);
    assert(d.sz == 3);
    assert(d.arr[0] == "hello");
    assert(d.arr[1] == "world");
    assert(d.arr[2] == "dog");

    remove(d, 2);
    assert(d.sz == 2);
    assert(d.arr[0] == "hello");
    assert(d.arr[1] == "world");

    remove(d, 0);
    assert(d.sz == 1);
    assert(d.arr[0] == "world");

    deallocate(a);
    deallocate(b);
    deallocate(c);
    deallocate(d);
    cout << "PASSED\n";
}

void test_remove_first()
{
    cout << "Testing remove_first(v, s) ... ";
    str_vec a = make_str_vec();
    remove_first(a, "hello");
    assert(a.sz == 0);

    append(a, "hello");
    remove_first(a, "cat");
    assert(a.sz == 1);
    assert(a.arr[0] == "hello");

    remove_first(a, "hello");
    assert(a.sz == 0);

    string arr[] = {"hello", "world", "one", "world", "hello"};
    str_vec b    = make_str_vec(arr, 5);

    remove_first(b, "world");
    assert(b.sz == 4);
    assert(b.arr[0] == "hello");
    assert(b.arr[1] == "one");
    assert(b.arr[2] == "world");
    assert(b.arr[3] == "hello");

    remove_first(b, "world");
    assert(b.sz == 3);
    assert(b.arr[0] == "hello");
    assert(b.arr[1] == "one");
    assert(b.arr[2] == "hello");

    remove_first(b, "hello");
    assert(b.sz == 2);
    assert(b.arr[0] == "one");
    assert(b.arr[1] == "hello");

    remove_first(b, "hello");
    assert(b.sz == 1);
    assert(b.arr[0] == "one");

    remove_first(b, "one");
    assert(b.sz == 0);

    deallocate(a);
    deallocate(b);
    cout << "PASSED\n";
}

void test_reverse()
{
    cout << "Testing reverse(v) ... ";
    str_vec a = make_str_vec();
    reverse(a);
    assert(a.sz == 0);

    append(a, "hello");
    reverse(a);
    assert(a.sz == 1);
    assert(a.arr[0] == "hello");

    append(a, "world");
    reverse(a);
    assert(a.sz == 2);
    assert(a.arr[0] == "world");
    assert(a.arr[1] == "hello");

    append(a, "cat");
    reverse(a);
    assert(a.sz == 3);
    assert(a.arr[0] == "cat");
    assert(a.arr[1] == "hello");
    assert(a.arr[2] == "world");

    deallocate(a);
    cout << "PASSED\n";
}

void test_sort()
{
    cout << "Testing sort(v) ... ";
    str_vec a = make_str_vec();
    sort(a);
    assert(a.sz == 0);

    append(a, "hello");
    sort(a);
    assert(a.sz == 1);
    assert(a.arr[0] == "hello");

    append(a, "world");
    sort(a);
    assert(a.sz == 2);
    assert(a.arr[0] == "hello");
    assert(a.arr[1] == "world");

    append(a, "cat");
    sort(a);
    assert(a.sz == 3);
    assert(a.arr[0] == "cat");
    assert(a.arr[1] == "hello");
    assert(a.arr[2] == "world");

    deallocate(a);
    cout << "PASSED\n";
}

void test_austen()
{
    cout << "Testing austen_test() ... ";
    str_vec a = make_str_vec();

    ifstream infile("austenPride.txt");
    string word;
    while (infile >> word)
    {
        append(a, word);
    }

    sort(a);

    const string correct_first_word = "\"'After";

    assert(a.arr[0] == correct_first_word);

    const int correct_word_count = 124580;
    assert(a.sz == correct_word_count);

    deallocate(a);
    cout << "PASSED\n";
}

int main()
{
    test_make_str_vec_1();
    test_make_str_vec_2();
    test_make_str_vec_3();
    test_make_str_vec_4();
    test_to_str();
    test_equals();
    test_double_capacity();
    test_free_space();
    test_squish();
    test_append1();
    test_count();
    test_contains();
    test_append_new_1();
    test_append_new_2();
    test_remove();
    test_remove_first();
    test_reverse();
    test_sort();
    test_austen();
    cout << "\nAll tests PASSED\n";
}
*/
