// int_vec4.cpp

//
// Same as int_vec3.cpp, but with a name member variable and getter.
// Constructors with initialization lists are used to call the constructor for
// the base class.
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
    string name;

  public:
    // TODO: Write a constructor that takes a name, and initialize the vector to
    // the empty vector. Hint: Use an initialization list to call the
    // vector<int>() constructor.

    //
    // constructor with a name
    //
    // We want to require a name for an int_vec, so we use a constructor that
    // gets the name. But we have a problem: how do we call the constructor for
    // vector<int>? We must call the vector<int> constructor to ensure that its
    // variables are properly initialized.
    //
    // In C++, the solution is to call the vector<int> constructor in the
    // initialization list of the int_vec constructor. In an initialization
    // list, we can initialize any of the class variables by calling their
    // constructors.
    //
    // In this case, the initialization list does everything we need, i.e. it
    // initializes the vector<int> and the name. So the body of the constructor
    // is empty.
    //
    int_vec(const string& s) : vector<int>(), name(s) // initialization list
    {
    }

    // TODO: Write a default constructor that calls the constructor above it
    // with the name "<no name>". Hint: Use constructor delegation to call the
    // constructor above it.

    //
    // default constructor
    //
    // This constructor uses constructor delegation to call the constructor
    // above it.
    //
    int_vec() : int_vec("<no name>") {}

    // TODO: Write a name getter that returns the name of the vector.
    //
    // name getter
    //
    string get_name() const { return name; }

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

    //
    // reverse the order of the elements of the vector
    //
    void reverse()
    {
        int a = 0;
        int b = size() - 1;
        while (a < b)
        {
            // swap the elements at indices a and b
            int temp   = (*this)[a];
            (*this)[a] = (*this)[b];
            (*this)[b] = temp;

            // move the indices towards the middle of the vector
            a++;
            b--;
        }
    }

    //
    // An alternative implementation of reverse using the standard library.
    //
    // std::reverse is a standard C++ function for reversing vectors and arrays.
    // std::reverse(begin(), end()) reverses the order of the elements from the
    // start of the vector to the end.
    //
    // No explicit use of the this pointer is needed.
    //
    void reverse2() { std::reverse(begin(), end()); }

    //
    // sort the elements of the vector in increasing order, i.e smallest to largest
    //
    void sort_increasing() { std::sort(begin(), end()); }

    //
    // sort the elements of the vector in decreasing order, i.e largest to smallest
    //
    void sort_decreasing()
    {
        sort_increasing();
        reverse();
    }

}; // class int_vec

int main()
{
    // int_vec v;

    int_vec v("Table 1");
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);

    cout << "\n";
    cout << "sum  = " << v.sum() << "\n";
    cout << "sum2 = " << v.sum2() << "\n";
    cout << "sum3 = " << v.sum3() << "\n";

    cout << "original " << v.get_name() << ":\n";
    for (int n : v)
        cout << n << " ";
    cout << "\n";

    cout << "after reversing " << v.get_name() << ":\n";
    v.reverse();
    for (int n : v)
        cout << n << " ";
    cout << "\n";

    cout << "after sorting increasing " << v.get_name() << ":\n";
    v.sort_increasing();
    for (int n : v)
        cout << n << " ";
    cout << "\n";

    cout << "after sorting decreasing " << v.get_name() << ":\n";
    v.sort_decreasing();
    for (int n : v)
        cout << n << " ";
    cout << "\n";
} // main
