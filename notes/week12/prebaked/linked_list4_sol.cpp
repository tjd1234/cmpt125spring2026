// linked_list4_sol.cpp

#include <cassert>
#include <iostream>

using namespace std;

/*

This shows how to write functions to add and remove elements from the front of a
list.

*/

// A Node stores a int, a pointer to the next Node.
struct Node
{
    int data;
    Node* next;
};

// TODO 2: Write a void function called add_front(Node*& head, int value) that
// adds a new node with the given value to the front of the list. Question: why
// is head passed as Node*& instead of just Node*? 
void add_front(Node*& head, int value)
{
    head = new Node{value, head};
}

// TODO 4: Write a void function called print_list(Node* p) that print the
// values of the list start at the node p point to. Then use this to print the
// values of the list in main.
void print_list(Node* p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// TODO 5: Write a void function called remove_front(Node*& head) that removes
// the first node from the list. Then use this to remove the first node from the
// list in main.
void remove_front(Node*& head)
{
    Node* temp = head->next;
    delete head;
    head = temp;
}

// TODO 6: Write a void function called clear_list(Node*& head) that deletes all
// the nodes in the list. Then use this to clear the list in main.
void clear_list(Node*& head)
{
    while (head != nullptr)
    {
        remove_front(head);
    }
}

int main()
{
    // TODO 1: Make an empty list with no values.
    Node* head = nullptr;

    // TODO 3: Add the values 1, 2, 3, 4 to the list so they are in the order
    // 1, 2, 3, 4.
    add_front(head, 4);
    add_front(head, 3);
    add_front(head, 2);
    add_front(head, 1);
    print_list(head); // 1 2 3 4
    
    remove_front(head);
    print_list(head); // 2 3 4

    clear_list(head);
    assert(head == nullptr);
    cout << " (list is empty, clear function)" << endl;
}
