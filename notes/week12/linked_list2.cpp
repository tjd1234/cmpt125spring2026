// linked_list2.cpp

#include <cassert>
#include <iostream>

using namespace std;

/*

This shows how to use a loop print and sum the values of a singly-linked list.

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
    Node* head = nullptr; // empty list

    // TODO 2: Add the numbers 1, 2, 3, 4 to the list so they are in the order
    // 1, 2, 3, 4.
    head = new Node{4, head};
    head = new Node{3, head};
    head = new Node{2, head};
    head = new Node{1, head};
        
    // TODO 3: Print the values of the list without using a loop.
    cout << head->data << " ";
    cout << head->next->data << " ";
    cout << head->next->next->data << " ";
    cout << head->next->next->next->data << endl;;

    // TODO 4: Print the values of the list using a while-loop.
    // start at first node
    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next; // go to the next node
    }
    cout << endl;

    // TODO 5: Print the values of the list using a for-loop.
    for(Node* p = head; p != nullptr; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    // TODO 6: Calculate the sum of the values in the list without using a loop
    // and print the result.
    
    // you do!

    // TODO 7: Calculate the sum of the values in the list using a while-loop
    // and print the result.
    p = head;
    int total = 0;
    while (p != nullptr) {
        total += p->data;
        p = p->next; // go to the next node
    }
    cout << "sum: " << total << endl; // 10

    // TODO 8: Calculate the sum of the values in the list using a for-loop
    // and print the result.
    total = 0;
    for(Node* p = head; p != nullptr; p = p->next) {
        total += p->data;
    }
    cout << "sum: " << total << endl; // 10

    // TODO 9: Remove each element of the list one at a time, until it is empty,
    // without using a loop.

    
    // TODO 10: Recreate the list so it has the values 1, 2, 3, 4 (in that order).
    
    // TODO 11: Using a while-loop, remove all the values of the list, one
    // removal per iteration. Hint: think of it as repeatedly removing the first
    // value of the list until the list is empty.
    
    // for(int i = 0; i < 4; ++i) {
    //     p = head->next; // temp pointer
    //     delete head;
    //     head = p;
    // }
    p = head;
    while (p != nullptr) {
        p = head->next; // temp pointer
        delete head;
        head = p;     
    }
    assert(p == nullptr);
}
