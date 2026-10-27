#include "LinkedList.h"             // 1) your own header first
#include <iostream>                 // 2) then what THIS file needs
using namespace std;

LinkedList::LinkedList()            // LinkedList:: = member of LinkedList
{
    head = nullptr;
}
LinkedList::~LinkedList()
{
    while (head != nullptr) {       // delete the nodes one by one
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtFront(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void LinkedList::display() const
{
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " -> ";
    cout << "NULL" << endl;
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}
// =============================== Week 3 ===============================
// Fill in these bodies question by question. The stubs compile and link,
// so the whole project builds from the start.

void LinkedList::insertAtEnd(int value)                     // Q2
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;        // son düğüm olacak, devamı yok

    if (head == nullptr) {          // liste boşsa
        head = newNode;             // yeni düğüm ilk düğüm olur
        return;
    }

    Node* cur;
    for (cur = head; cur->next != nullptr; cur = cur->next);
    cur->next = newNode;
}

int LinkedList::length() const                              // Q2
{
    int count = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        count++;
    return count;                                               // TODO
}

void LinkedList::createFromArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        insertAtEnd(arr[i]);
    }
}

int LinkedList::search(int value) const
{
    int index = 0;

    for (Node* cur = head; cur != nullptr; cur = cur->next)
    {
        if (cur->data == value)
            return index;

        index++;
    }

    return -1;
}

int LinkedList::update(int oldValue, int newValue)
{
    int count = 0;

    for (Node* cur = head; cur != nullptr; cur = cur->next)
    {
        if (cur->data == oldValue)
        {
            cur->data = newValue;
            count++;
        }
    }

    return count;
}

bool LinkedList::insertAt(int index, int value)
{
    if (index < 0)
        return false;

    if (index == 0)
    {
        insertAtFront(value);
        return true;
    }

    Node* cur = head;

    for (int i = 0; cur != nullptr && i < index - 1; i++)
        cur = cur->next;

    if (cur == nullptr)
        return false;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = cur->next;
    cur->next = newNode;

    return true;
}

bool LinkedList::deleteValue(int value)
{
    if (head == nullptr)
        return false;

    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* cur = head;

    while (cur->next != nullptr && cur->next->data != value)
        cur = cur->next;

    if (cur->next == nullptr)
        return false;

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;

    return true;
}

void LinkedList::merge(LinkedList& other)
{
    if (other.head == nullptr)
        return;

    if (head == nullptr)
    {
        head = other.head;
    }
    else
    {
        Node* cur = head;

        while (cur->next != nullptr)
            cur = cur->next;

        cur->next = other.head;
    }

    other.head = nullptr;
}

// =============================== Week 5 ===============================
void LinkedList::displayBackward() const
{
    printBackward(head);
    cout << endl;
}
void LinkedList::printBackward(const Node* node)
{
    // TODO: base case; recursive call on node->next; then print node->data
}
void LinkedList::reverse()
{
    head = reverseFrom(head);
}
Node* LinkedList::reverseFrom(Node* node)
{
    return node; // TODO
}