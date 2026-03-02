// oopstr1.cpp

#include <cstring>
#include <iostream>

using namespace std;

struct Oopstr
{
  private:
    char* str;
    int sz;

    void check_bounds(int index) const
    {
        if (index < 0 || index >= sz)
        {
            throw std::out_of_range("Index out of bounds");
        }
    }

  public:
    // default constructor
    Oopstr()
    {
        sz  = 0;
        str = nullptr;
    }

    // copy constructor
    Oopstr(const Oopstr& other)
    {
        sz  = other.sz;
        str = new char[sz];
        for (int i = 0; i < sz; i++)
        {
            str[i] = other.str[i];
        }
    }

    // constructor
    Oopstr(const char* text)
    {
        // get the length of text
        sz = strlen(text);

        // allocate a new array of characters
        str = new char[sz];

        // copy the characters from text to str
        for (int i = 0; i < sz; i++)
        {
            str[i] = text[i];
        }
    }

    // destructor
    // automatically called when the object is destroyed
    ~Oopstr()
    {
        cout << "Destructor called: ";
        println();
        delete[] str;
    }

    // get the size of the string
    int size() const { return sz; }

    void set_char(int index, char c)
    {
        check_bounds(index);
        str[index] = c;
    }

    // get the character at the given index
    char get_char(int index) const
    {
        check_bounds(index);
        return str[index];
    }

    void append(const Oopstr& other)
    {
        // make a new array of characters of the total size of
        // this and other
        char* new_str = new char[sz + other.sz];

        // copy characters from this to the new array
        for (int i = 0; i < sz; i++)
        {
            new_str[i] = str[i];
        }

        // copy the other characters to the new array
        for (int i = 0; i < other.sz; i++)
        {
            new_str[sz + i] = other.str[i];
        }

        // de-allocate the old array
        delete[] str;

        // make s point to the new array and update the size
        str = new_str;
        sz  = sz + other.sz;
    }

    void print() const
    {
        for (int i = 0; i < size(); i++)
        {
            cout << get_char(i);
        }
    }

    void println() const
    {
        print();
        cout << "\n";
    }

    bool operator!=(const Oopstr& other) const {
        return !(other == *this); 
    }

    bool operator==(const Oopstr& other) const
    {
        if (this->sz != other.sz)
        {
            return false;
        }
        for (int i = 0; i < this->sz; i++)
        {
            if (str[i] != other.str[i])
            {
                return false;
            }
        }
        return true;
    }
}; // struct Oopstr

void print(const Oopstr& s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s.get_char(i);
    }
}

void println(const Oopstr& s)
{
    print(s);
    cout << "\n";
}

int main()
{
    Oopstr a;
    a.append(Oopstr("Moon!"));
    println(a);

    Oopstr b(a);
    println(b);
    b.append("!");

    if (a == b)
    {
        cout << "a and b are equal\n";
    }
    else
    {
        cout << "a and b are not equal\n";
    }

    // // create s
    // Oopstr s("Hello");
    // s.set_char(0, 'h');

    // cout << s.size() << "\n";

    // // s.println();
    // println(s);

    // Oopstr t(" World");
    // s.append(t); // append(s, t)

    // print s
    // s.println();
    // println(s);
}
