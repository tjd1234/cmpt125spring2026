// linked_list3_sol.cpp

#include <cassert>
#include <iostream>

using namespace std;

/*

This shows how to write functions to print a list, sum a list, and clearing a
list (using loops).

*/

// A Node stores a int, a pointer to the next Node.
struct Node
{
    int data;
    Node* next;
};

// TODO 2: Write a void function print_list(Node* p) that prints the values of
// the list starting at the node pointed to by p. Use a loop to print the
// values. Then call it in main to test it.
void print_list(Node* p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// TODO 3: Write a function int sum_list(Node* p) that returns the sum of the
// values of the list starting at the node pointed to by p. Use a loop, and call
// it in main to test it.
int sum_list(Node* p)
{
    int sum = 0;
    while (p != nullptr)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// TODO 4: Write a function called clear_list(Node* p) that deletes all the
// nodes in the list starting at the node pointed to by p. Use a loop, and call
// it in main to test it. Hint: think of it as repeatedly removing the first
// value of the list until the list is empty.
void clear_list(Node* p)
{
    while (p != nullptr)
    {
        Node* temp = p->next;
        delete p;
        p = temp;
    }
}

int main()
{
    // TODO 1: Make a list with the values 1, 2, 3, 4 (in that order).
    Node* head = nullptr;
    head       = new Node{4, head};
    head       = new Node{3, head};
    head       = new Node{2, head};
    head       = new Node{1, head};

    print_list(head);
    cout << sum_list(head) << " (sum with loop)" << endl;
    clear_list(head);
    assert(head == nullptr);
    cout << " (list is empty, clear loop)" << endl;
}
