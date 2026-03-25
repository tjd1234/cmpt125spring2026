// linked_list3.cpp

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

Node* head;

// TODO 2: Write a void function print_list(Node* p) that prints the values of
// the list starting at the node pointed to by p. Use a loop to print the
// values. Then call it in main to test it.

// Node* p = head;
// while (p != nullptr) {
//     cout << p->data << " ";
//     p = p->next; // go to the next node
// }
// cout << endl;

void print_list(Node* p) {
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// TODO 3: Write a function int sum_list(Node* p) that returns the sum of the
// values of the list starting at the node pointed to by p. Use a loop, and call
// it in main to test it.

// p = head;
// int total = 0;
// while (p != nullptr) {
//     total += p->data;
//     p = p->next; // go to the next node
// }
// cout << "sum: " << total << endl; // 10

int sum_list(Node* p) {
    int total = 0;
    while (p != nullptr) {
        total += p->data;
        p = p->next;
    }
    return total;
}

// TODO 4: Write a function called clear_list() that deletes all the nodes in
// the list. Use a loop, and call it in main to test it. Hint: think of it as
// repeatedly removing the first value of the list until the list is empty.

// p = head;
// while (p != nullptr) {
//     p = head->next; // temp pointer
//     delete head;
//     head = p;     
// }
// assert(p == nullptr);

void clear() {
    Node* p = head;
    while (p != nullptr) {
        p = p->next;
        delete head;
        // head is a dangling pointer
        head = p;
    }
}

int main()
{
    // TODO 1: Make a list with the values 1, 2, 3, 4 (in that order).
    // head = nullptr;
    head = new Node{4, head};
    head = new Node{3, head};
    head = new Node{2, head};
    head = new Node{1, head};
    print_list(head->next);

    cout << "sum: " << sum_list(head) << endl; // 10
    clear();
}
