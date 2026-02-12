// int_vec1.cpp

#include <iostream>
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

}; // class int_vec

int main()
{
    int_vec v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);

    for (int n : v)
        cout << n << "\n";
}
