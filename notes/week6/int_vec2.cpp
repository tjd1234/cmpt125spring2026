// int_vec2.cpp

//
// Same as int_vec1.cpp, but with a sum method. A few different ways of summing
// are given.
//

#include <iostream>
#include <numeric> // for accumulate
#include <vector>

using namespace std;

//
// int_vec inherits from vector<int>
//
// This means that int_vec has all the methods and member variables of
// vector<int>.
//
// The public keyword means that public methods and member variables of
// vector<int> are public in int_vec.
//
class int_vec : public vector<int>
{
  public:
    // TODO: Write a methods called sum() that returns the sum of the elements
    // in the vector.


}; // class int_vec

int main()
{
    int_vec v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);

    for (int n : v)
        cout << n << "\n";

    // cout << "sum  = " << v.sum() << "\n";
} // main
