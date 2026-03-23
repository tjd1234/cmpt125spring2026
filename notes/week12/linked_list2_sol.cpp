// linked_list2_sol.cpp

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
    Node* head = nullptr;

    // TODO 2: Add the numbers 1, 2, 3, 4 to the list so they are in the order
    // 1, 2, 3, 4.
    head = new Node{4, head};
    head = new Node{3, head};
    head = new Node{2, head};
    head = new Node{1, head};

    // TODO 3: Print the values of the list without using a loop.
    cout << head->data << " ";                   // 1
    cout << head->next->data << " ";             // 2
    cout << head->next->next->data << " ";       // 3
    cout << head->next->next->next->data << " "; // 4
    cout << " (no loop)" << endl;

    // TODO 4: Print the values of the list using a while-loop.
    Node* p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << " (while loop)" << endl;

    // TODO 5: Print the values of the list using a for-loop.
    for (Node* p = head; p != nullptr; p = p->next)
    {
        cout << p->data << " ";
    }
    cout << " (for loop)" << endl;

    // TODO 6: Calculate the sum of the values in the list without using a loop
    // and print the result.
    int sum = head->data + head->next->data + head->next->next->data + head->next->next->next->data;
    cout << sum << " (sum with no loop)" << endl;

    // TODO 7: Calculate the sum of the values in the list using a while-loop
    // and print the result.
    sum = 0;
    p   = head;
    while (p != nullptr)
    {
        sum += p->data;
        p = p->next;
    }
    cout << sum << " (sum with while loop)" << endl;

    // TODO 8: Calculate the sum of the values in the list using a for-loop
    // and print the result.
    sum = 0;
    for (Node* p = head; p != nullptr; p = p->next)
    {
        sum += p->data;
    }
    cout << sum << " (sum with for loop)" << endl;

    // TODO 9: Remove each element of the list one at a time, until it is empty,
    // without using a loop.
    Node* temp = head->next;
    delete head;
    head = temp; // list is now 2, 3, 4

    temp = head->next;
    delete head;
    head = temp; // list is now 3, 4

    temp = head->next;
    delete head;
    head = temp; // list is now 4

    temp = head->next;
    delete head;
    head = temp; // list is now empty
    cout << " (list is empty, no loop)" << endl;

    // TODO 10: Recreate the list so it has the values 1, 2, 3, 4 (in that order).
    head = new Node{4, head};
    head = new Node{3, head};
    head = new Node{2, head};
    head = new Node{1, head};

    // TODO 11: Using a while-loop, remove all the values of the list, one
    // removal per iteration. Hint: think of it as repeatedly removing the first
    // value of the list until the list is empty.
    while (head != nullptr)
    {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
    assert(head == nullptr);
    cout << " (list is empty, while loop)" << endl;
}
