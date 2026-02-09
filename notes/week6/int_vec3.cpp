// int_vec3.cpp

//
// Same as int_vec2.cpp, but with sorting methods.
//

#include <algorithm> // for sort and reverse
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

    // TODO: Write a method called reverse() that reverses the order of the
    // elements in the vector.

    // TODO: Write a method called sort_increasing() that sorts the elements of
    // the vector in increasing order. Hint: Use std::sort from the standard
    // library to help.

    // TODO: Write a method called sort_decreasing() that sorts the elements of
    // the vector in decreasing order. Hint: Use methods you've already written
    // to help.

}; // class int_vec

int main()
{
    int_vec v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);

    cout << "sum  = " << v.sum() << "\n";

    cout << "original:\n";
    for (int n : v)
        cout << n << " ";
    cout << "\n";

    // cout << "after reversing:\n";
    // v.reverse();
    // for (int n : v)
    //     cout << n << " ";
    // cout << "\n";

    // cout << "after sorting increasing:\n";
    // v.sort_increasing();
    // for (int n : v)
    //     cout << n << " ";
    // cout << "\n";

    // cout << "after sorting decreasing:\n";
    // v.sort_decreasing();
    // for (int n : v)
    //     cout << n << " ";
    // cout << "\n";
} // main
