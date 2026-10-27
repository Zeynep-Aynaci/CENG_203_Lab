#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

// Constructor
DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

// Destructor
DoublyLinkedList::~DoublyLinkedList()
{
    DNode* cur = head;

    while (cur != nullptr)
    {
        DNode* temp = cur;
        cur = cur->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
}

// Insert at front
void DoublyLinkedList::insertAtFront(int value)
{
    DNode* newNode = new DNode(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void DoublyLinkedList::insertAtEnd(int value)
{
    DNode* newNode = new DNode(value);

    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Display forward
void DoublyLinkedList::displayForward() const
{
    DNode* cur = head;

    while (cur != nullptr)
    {
        cout << cur->data << " <-> ";
        cur = cur->next;
    }

    cout << "NULL" << endl;
}

// Display backward
void DoublyLinkedList::displayBackward() const
{
    DNode* cur = tail;

    while (cur != nullptr)
    {
        cout << cur->data << " <-> ";
        cur = cur->prev;
    }

    cout << "NULL" << endl;
}

// Delete first matching value
bool DoublyLinkedList::deleteValue(int value)
{
    DNode* cur = head;

    while (cur != nullptr && cur->data != value)
    {
        cur = cur->next;
    }

    if (cur == nullptr)
        return false;

    if (cur == head)
        head = cur->next;
    else
        cur->prev->next = cur->next;

    if (cur == tail)
        tail = cur->prev;
    else
        cur->next->prev = cur->prev;

    delete cur;
    return true;
}