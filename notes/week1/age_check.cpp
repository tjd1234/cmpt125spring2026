// age_check.cpp

#include <iostream>

using namespace std;

int main()
{
    int age;
    cout << "Please enter your age: ";
    cin >> age;

    if (age < 0)
    {
        cout << "Invalid age entered.\n";
    }
    else if (age == 0 || age == 1) // || is logical or
    {
        cout << "You are an infant.\n";
    }
    else if (age < 18)
    {
        cout << "You are a minor.\n";
    }
    else if (18 <= age && age < 65) // && is logical and
    {
        cout << "You are an adult.\n";
    }
    else
    {
        cout << "You are a senior citizen.\n";
    }
}
