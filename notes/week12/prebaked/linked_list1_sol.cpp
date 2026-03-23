// linked_list1_sol.cpp

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
    cout << head->data << "\n"; // 25

    // TODO 4: Add a new value at the front of the list so that it has two
    // values, 10 and then 25.
    head = new Node{10, head};

    // TODO 5: Print the value of the first node.
    cout << head->data << "\n"; // 10

    // TODO 6: Print the value of the second node.
    cout << head->next->data << "\n"; // 25

    // TODO 7: Add a new value at the front of the list so that it has three
    // values. 20, 10, and 25
    head = new Node{20, head};

    // TODO 8: Print the first value, second value, and third value of the list.
    cout << head->data << "\n"; // 20
    cout << head->next->data << "\n"; // 10
    cout << head->next->next->data << "\n"; // 25

    // TODO 9: Calculate the sum of the values in the list.
    int num = head->data + head->next->data + head->next->next->data;
    cout << "Sum: " << num << "\n";

    // TODO 10: Remove the first value from the list so that the remaining list
    // has two values, 10 and 25. Hint: use a temporary pointer to store the
    // rest of the list.
    Node* temp = head->next;
    delete head;
    head = temp;

    // TODO 11: Print the first value and second value of the list.
    cout << head->data << "\n"; // 10
    cout << head->next->data << "\n"; // 25

    // TODO 12: Remove the first value of the list so that the main list has
    // just the value 25. Print the resulting list.
    temp = head->next;
    delete head;
    head = temp;

    // TODO 13: Remove the final value of the list. Make sure the list is empty
    // (and there are no memory leaks).
    temp = head->next;
    delete head;
    head = temp;
}
