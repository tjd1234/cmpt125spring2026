// linked_list1.cpp

#include <cassert>
#include <iostream>

using namespace std;

/*

This shows the basics of create and deleting nodes in a singly-linked list of
ints.

*/

// A Node stores a int, a pointer to the next Node.
struct Node
{
    int data;
    Node* next;
};

int main()
{
    // TODO 1: Make an empty list with no values.
    Node* head = nullptr;    

    // TODO 2: Make a list with one node with data 25.
    head = new Node{25, nullptr};

    // TODO 3: Print the value of the first node.
    // cout << (*head).data << endl;
    cout << head->data << endl;

    // TODO 4: Add a new value at the front of the list so that it has two
    // values, 10 and then 25.
    head = new Node{10, head};

    // TODO 5: Print the value of the first node.
    cout << head->data << endl; // 10

    // TODO 6: Print the value of the second node.
    cout << head->next->data << endl; // 25

    // TODO 7: Add a new value at the front of the list so that it has three
    // values. 20, 10, and 25
    head = new Node{20, head};

    // TODO 8: Print the first value, second value, and third value of the list.
    cout << head->data << " "; // 20
    cout << head->next->data << " "; // 10
    cout << head->next->next->data << endl; // 25

    // TODO 9: Calculate the sum of the values in the list.
    int a = head->data; // 20
    int b = head->next->data; // 10
    int c = head->next->next->data; // 25
    cout << a + b + c << endl;

    // TODO 10: Remove the first value from the list so that the remaining list
    // has two values, 10 and 25. Hint: use a temporary pointer to store the
    // rest of the list.
    // 20 10 25
    Node* p = head->next; // temp pointer
    delete head;
    head = p;
    
    // TODO 11: Print the first value and second value of the list.
    cout << head->data << " "; // 10
    cout << head->next->data << endl; // 25
    
    // TODO 12: Remove the first value of the list so that the main list has
    // just the value 25. Print the resulting list.
    // 10 25
    p = head->next; // temp pointer
    delete head;
    head = p;
    cout << head->data << endl; // 25

    // TODO 13: Remove the final value of the list. Make sure the list is empty
    // (and there are no memory leaks).
    // 25
    p = head->next; // temp pointer
    delete head;
    head = p;
    assert(head == nullptr);
}
