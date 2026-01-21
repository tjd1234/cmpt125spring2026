// structs.cpp

#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    Person dad{"John", 30};
    Person mom{"Jane", 28};
    Person child{"Jim", 5};

    cout << "Dad: " << dad.name << " " << dad.age << "\n";
    cout << "Mom: " << mom.name << " " << mom.age << "\n";
    cout << "Child: " << child.name << " " << child.age << "\n";
}
