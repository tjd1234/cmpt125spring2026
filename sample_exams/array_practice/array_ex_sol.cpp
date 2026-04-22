// array_ex_sol.cpp

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// TODO 1 Write a function called print_array(arr, size) that returns a string
// that neatly formats the contents of arr (and array of size ints). The values
// should be in {}-braces and separated by commas. For example, print_array({1,
// 2, 3}, 3) should return "{1, 2, 3}", and print_array({}, 0) should return
// "{}".
//
// Recall that to_string(n) returns a string representation of int n.
string print_array(int* arr, int size)
{
    string result = "{";
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
            result += ", ";
        result += to_string(arr[i]);
    }
    return result + "}";
}

void print_array_test()
{
    int arr1[] = {5};
    assert(print_array(arr1, 1) == "{5}");
    int arr2[] = {6, 2};
    assert(print_array(arr2, 2) == "{6, 2}");
    int arr3[] = {7, 2, 9};
    assert(print_array(arr3, 3) == "{7, 2, 9}");
    cout << "print_array_test: all tests passed\n";
}

// TODO 2 Write a function called make_array(n, val) that returns a pointer to a
// new array n ints on the free store, where each element is initialized to val.
// For example, make_array(3, 4) should return {4, 4, 4}.
int* make_array(int n, int val)
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = val;
    }
    return arr;
}

void make_array_test()
{
    int* arr = make_array(1, 5);
    assert(arr[0] == 5);
    delete[] arr;

    arr = make_array(2, 6);
    assert(arr[0] == 6);
    assert(arr[1] == 6);
    delete[] arr;

    arr = make_array(3, 7);
    assert(arr[0] == 7);
    assert(arr[1] == 7);
    assert(arr[2] == 7);
    delete[] arr;

    cout << "make_array_test: all tests passed\n";
}

// TODO 3 Write a function called scale_array(arr, factor) that returns a
// pointer to a new array on the free store that is the same as arr, except that
// each element is multiplied by factor. For example, scale_array({1, 2, 3}, 2)
// should return {2, 4, 6}. The original array is not modified.
int* scale_array(int* arr, int size, int factor)
{
    int* new_arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = arr[i] * factor;
    }
    return new_arr;
}

void scale_array_test()
{
    int arr1[]      = {2};
    int* scaled_arr = scale_array(arr1, 1, 2);
    assert(scaled_arr[0] == 4);
    delete[] scaled_arr;

    int arr2[] = {2, 4};
    scaled_arr = scale_array(arr2, 2, 2);
    assert(scaled_arr[0] == 4);
    assert(scaled_arr[1] == 8);
    delete[] scaled_arr;

    int* arr3  = make_array(3, 2); // {2, 2, 2}
    scaled_arr = scale_array(arr3, 3, 2);
    assert(scaled_arr[0] == 4);
    assert(scaled_arr[1] == 4);
    assert(scaled_arr[2] == 4);
    delete[] scaled_arr;

    cout << "scale_array_test: all tests passed\n";
}

// TODO 4 Write a function called add_arrays(arr1, arr2, size) that returns a
// new array on the free store that is the element-by-elementsum of arr1 and
// arr2. For example, add_arrays({1, 2, 3}, {4, 5, 6}, 3) should return {5, 7, 9}.
// The original arrays are not modified.
int* add_arrays(int* arr1, int* arr2, int size)
{
    int* new_arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = arr1[i] + arr2[i];
    }
    return new_arr;
}

void add_arrays_test()
{
    int a1[]       = {1};
    int b1[]       = {4};
    int* added_arr = add_arrays(a1, b1, 1); // {5}
    assert(added_arr[0] == 5);
    delete[] added_arr;

    int a2[]  = {1, 2};
    int b2[]  = {4, 5};
    added_arr = add_arrays(a2, b2, 2); // {5, 7}
    assert(added_arr[0] == 5);
    assert(added_arr[1] == 7);
    delete[] added_arr;

    int* a3   = make_array(3, 1);      // {1, 1, 1}
    int* b3   = make_array(3, 4);      // {4, 4, 4}
    added_arr = add_arrays(a3, b3, 3); // {5, 5, 5}
    assert(added_arr[0] == 5);
    assert(added_arr[1] == 5);
    assert(added_arr[2] == 5);
    delete[] added_arr;

    cout << "add_arrays_test: all tests passed\n";
}

int main()
{
    print_array_test();
    make_array_test();
    scale_array_test();
    add_arrays_test();
}
