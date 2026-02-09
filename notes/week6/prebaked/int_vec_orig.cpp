// int_vec_orig.cpp

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class int_vec : public vector<int> {
public:
    // The begin() and end() methods are inherited from
    // vector<int>, and so we are free to use them in 
    // int_vec methods.
    int sum() const {
        return std::accumulate(begin(), end(), 0);
    }

    // An alternative implementation of sum using a C-style 
    // for-loop.
    int sum2() const {
        int result = 0;
        for(int i = 0; i < size(); i++) {
            result += (*this)[i];
        }
        return result;
    }

    // An alternative implementation of sum using a for-each loop.
    int sum3() const {
        int result = 0;
        for(int n : *this) {
            result += n;
        }
        return result;
    }

    // The begin() and end() methods are inherited from
    // vector<int>, and so we are free to use them in 
    // int_vec methods.
    void sort_increasing() {
        std::sort(begin(), end());
    }

}; // class int_vec

int main() {
    int_vec v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    
    v.sort_increasing();
    for(int n : v) cout << n << "\n";
    cout << " sum = " << v.sum()  << "\n";
    cout << "sum2 = " << v.sum2() << "\n";
    cout << "sum3 = " << v.sum3() << "\n";
}
