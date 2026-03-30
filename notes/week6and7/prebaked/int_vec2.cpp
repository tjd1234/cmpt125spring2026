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

    //
    // The begin() and end() methods are inherited from vector<int>, and so we
    // are free to use them in int_vec methods. begin() and end() return
    // iterators to the begin and end of the vector, where iterators
    // pointer-like objects that refer to the first element of the vector and
    // one past the last element of the vector, respectively.
    //
    // accumulate is a standard C++ function for summing vectors and arrays.
    // std::accumulate(begin(), end(), 0) sums the values from the start of the
    // vector to the end, starting with an initial value of 0.
    //
    // No explicit use of the this pointer is needed.
    //
    int sum() const { return std::accumulate(begin(), end(), 0); }

    //
    // An alternative implementation of sum using a C-style for-loop.
    //
    // Notice how (*this)[i]is used to access element i of the vector.
    // []-brackets haven been defined in vector<int> and so can be used here.
    //
    int sum2() const
    {
        int result = 0;
        for (int i = 0; i < size(); i++)
        {
            result += (*this)[i];
        }
        return result;
    }

    //
    // An alternative implementation of sum using a for-each loop.
    //
    // Notice how *this is used to access the vector elements.
    //
    int sum3() const
    {
        int result = 0;
        for (int n : *this)
        {
            result += n;
        }
        return result;
    }

}; // class int_vec

int main()
{
    int_vec v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);

    for (int n : v)
        cout << n << "\n";

    cout << "sum  = " << v.sum() << "\n";
    cout << "sum2 = " << v.sum2() << "\n";
    cout << "sum3 = " << v.sum3() << "\n";
} // main
