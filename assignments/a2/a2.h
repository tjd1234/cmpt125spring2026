// a2.h

#include <string>

using namespace std;

//
// You're str_vec struct must be exactly this: don't change it!
//
struct str_vec
{
    string* arr; // pointer to the underlying array
    int sz;      // # of elements from user's perspective
    int cap;     // capacity, i.e. length of underlying array
};

/////////////////////////////////////////////////////////////////////////////////
//
// These are the declarations and specifications for all the str_vec functions.
//
// Don't change them! Leave them as is, and copy them to make the headers for
// your implementation functions.
//
// You don't need to implement them in the order given. Start with a few "make"
// functions and to_str (so you can make and see the str_vecs), and then
// implement and test them as you go.
//
// You can add helper functions if you need them.
//
/////////////////////////////////////////////////////////////////////////////////

//
// De-allocates the underlying array that v points to and sets v.arr to nullptr.
// Does not change v.sz or v.cap. v is passed by reference so that v.arr can be
// set to nullptr.
//
// Example: if v = {"up", "red"}, then after deallocate(v), v.arr is deleted and
// is set to nullptr.
//
void deallocate(str_vec& v);

//
// Returns a new str_vec of size 0 and capacity 10.
//
// Example: if make_str_vec() is called, then it returns a new str_vec with size
// 0 and capacity 10.
//
str_vec make_str_vec();

//
// Returns a new str_vec consisting of n copies of string s; the capacity of the
// new str_vec is n + 10. Throws an error if n is less than 0.
//
// Example: if n = 3 and s = "hello", then make_str_vec(n, s) returns a new
// str_vec with size 3 and capacity 13, and with strings {"hello", "hello",
// "hello"}.
//
str_vec make_str_vec(int n, const string& s);

//
// Returns a new str_vec that is a copy of the array of strings named arr, with
// size n. The capacity should be n + 10. Throws an error if n is less than 0.
//
// Example: if arr = {"up", "red"} and n = 2, then make_str_vec(arr, n) returns
// a new str_vec with size 2 and capacity 12, and with strings {"up", "red"}.
//
str_vec make_str_vec(const string arr[], int n);

//
// Returns a new str_vec that is a copy of other. They each have their own
// underlying array. The capacity of the new str_vec is other.sz + 10.
//
// Example: if other = {"up", "red"}, then make_str_vec(other) returns a new
// str_vec with size 2 and capacity 12, and with strings {"up", "red"}.
//
str_vec make_str_vec(const str_vec& other);

//
// Returns a string representation of v that begins with "{", ends with "}", and
// the elements are separated by commas. Each string is in double-quotes. Iv is
// empty, returns "{}".
//
// Example: if v = {"apple", "cat", "mouse"}, then to_str(v) returns
// "{\"apple\", \"cat\", \"mouse\"}".
//
string to_str(const str_vec& v);

//
// Test if the two str_vecs are equal, i.e. returns true if they have the same
// elements in the same order, and false otherwise; sizes must be the same but
// capacities may be different.
//
// Example: if a = {"up", "red"} and b = {"up", "red"}, then equals(a, b)
// returns true, and equals(b, a) returns true. If a = {"up", "red"} and b =
// {"red", "up"}, then equals(a, b) returns false.
//
bool equals(const str_vec& a, const str_vec& b);

//
// Doubles the capacity of the underlying array of v, keeping the same strings
// in the same order. If v.cap == 0, then it remains 0 (since doubling 0 is 0).
//
// Example: if v.sz = 10 and v.cap = 20, then after double_capacity(v), v.sz =
// 10 and v.cap = 40. The strings in the array are the same (and in the same
// order) after doubling the capacity as before.
//
void double_capacity(str_vec& v);

//
// Returns the number of unused elements in the underlying array of v, i.e. the
// capacity minus the size.
//
// Example: if v.sz = 10 and v.cap = 20, then free_space(v) returns 10, i.e. v
// has 10 free spaces.
//
int free_space(const str_vec& v);

//
// If v has any free space, shrink the underlying array to be the same as v.sz.
// If v has no free space, does nothing.
//
// Example: if v.sz = 10 and v.cap = 20, then after squish(v), v.sz = 10 and
// v.cap = 10. The strings in the array are unchanged.
void squish(str_vec& v);

//
// Adds s to the right end (back) of v, increasing its size by 1. The capacity
// of the underlying array is doubled if there is no free space.
//
// Example: if v = {"up", "red"}, then after append(v, "cow"), v = {"up", "red", "cow"}.
//
void append(str_vec& v, const string& s);

//
// Appends all the strings in other to the right end (back) of v, increasing its
// capacity if necessary.
//
// Example: if v = {"up", "red"} and other = {"red", "cow", "bat"}, then after
// append(v, other), v = {"up", "red", "red", "cow", "bat"}.
//
void append(str_vec& v, const str_vec& other);

//
// Returns the number of occurrences of s in v.
//
// Example: if v = {"up", "red", "up"}, then count(v, "red") returns 1,
// count(v, "up") returns 2, and count(v, "cow") returns 0.
//
int count(const str_vec& v, const string& s);

//
// Returns true if s is an element of v, and false otherwise.
//
// Example: if v = {"up", "red", "bat"}, then contains(v, "red") returns true,
// and contains(v, "cow") returns false.
//
bool contains(const str_vec& v, const string& s);

//
// Appends s to the right end (back) of v just when s is not already an element
// of v. If s is already in v, then does nothing.
//
// Example: if v = {"up", "red"}, then after append_new(v, "red"), v is
// unchanged. After append_new(v, "cow"), v = {"up", "red", "cow"}.
//
void append_new(str_vec& v, const string& s);

//
// Appends all the elements of other that do not occur in v to the right end
// (back) of v.
//
// Example: if v = {"up", "red"} and other = {"red", "cow", "bat"}, then after
// append_new(v, other), v = {"up", "red", "cow", "bat"}.
//
void append_new(str_vec& v, const str_vec& other);

//
// Removes the element at index loc, shifting to the left all the elements after
// loc. Throws an error if loc < 0 or loc >= v.sz.
//
// Example: if v = {"up", "red", "up"}, then after remove(v, 0), v = {"red", "up"}.
//
void remove(str_vec& v, int loc);

//
// Removes the first occurrence of s in v. If s is not found, then the str_vec
// is unchanged.
//
// Example: if v = {"up", "red", "up"}, then after remove_first(v, "up"), v = {"red", "up"}.
//
void remove_first(str_vec& v, const string& s);

//
// Reverses the order of the elements in v.
//
// Example: if v = {"up", "red", "bat"}, then after reverse(v), v = {"bat", "red", "up"}.
//
void reverse(str_vec& v);

//
// Sorts the elements of v into lexicographic (alphabetical) order.
//
// Example: if v = {"up", "red", "bat"}, then after sort(v), v = {"bat", "red", "up"}.
//
void sort(str_vec& v);
