// recursion.cpp

#include <iostream>

using namespace std;

void f(int n)
{
    cout << n << ": hello!" << endl;
    f(n + 1);
}

void demo1()
{
    f(1);
}

void say_hello(int n)
{
    if (n > 0)
    {
        cout << n << ": hello!\n";
        say_hello(n - 1);
    }
}

void demo2()
{
    say_hello(5);
}

void count_down(int n)
{
    if (n > 0)
    {
        cout << n << "\n";
        count_down(n - 1); // recursive call comes after printing
    }
}

void demo3()
{
    count_down(5);
}

void count_up(int n)
{
    if (n > 0)
    {
        count_up(n - 1); // recursive calls comes before printing
        cout << n << "\n";
    }
}

void demo4()
{
    count_up(5);
}

int sum(const vector<int>& v, int begin)
{
    if (begin >= v.size())
    {
        return 0;
    }
    else
    {
        return v[begin] + sum(v, begin + 1);
    }
}

int sum(const vector<int>& v)
{
    return sum(v, 0);
}

void demo5()
{
    vector<int> v = {4, 2, 3, 5};
    cout << sum(v) << "\n";
}

// bool all_even(const vector<int>& v, int begin)
// {
//     if (begin >= v.size())
//     {
//         return true;
//     }
//     return (v[begin] % 2 == 0) && all_even(v, begin + 1);
// }

bool all_even(const vector<int>& v, int begin)
{
    if (begin >= v.size())
    {
        return true;
    }
    else if (v[begin] % 2 == 0)
    {
        return all_even(v, begin + 1);
    }
    else
    {
        return false;
    }
}

int all_even(const vector<int>& v)
{
    return all_even(v, 0);
}

void demo6()
{
    vector<int> v = {6, 8, 0, 2};
    cout << all_even(v) << "\n";
}

int main()
{
    demo1();
    // demo2();
    // demo3();
    // demo4();
    // demo5();
    // demo6();
}
