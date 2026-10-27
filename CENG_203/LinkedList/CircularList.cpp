
#include "CircularList.h"
#include <iostream>
using namespace std;

// Constructor
CircularList::CircularList()
{
    head = nullptr;
}

// Destructor
CircularList::~CircularList()
{
    if (head == nullptr)
        return;

    Node* cur = head->next;

    while (cur != head)
    {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    delete head;
    head = nullptr;
}

// Append
void CircularList::append(int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* cur = head;

    while (cur->next != head)
    {
        cur = cur->next;
    }

    cur->next = newNode;
    newNode->next = head;
}

// Display
void CircularList::display() const
{
    if (head == nullptr)
    {
        cout << "(empty)" << endl;
        return;
    }

    Node* cur = head;

    do
    {
        cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != head);

    cout << "(back to " << head->data << ")" << endl;
}

// Length
int CircularList::length() const
{
    if (head == nullptr)
        return 0;

    int count = 0;
    Node* cur = head;

    do
    {
        count++;
        cur = cur->next;
    } while (cur != head);

    return count;
}