#include "Stack.h"
#include <iostream>
using namespace std;

// Stubs: the project builds and links, you fill the bodies in Q2.

Stack::Stack()
{
    top = nullptr;
    count = 0;
}

Stack::~Stack()
{
    clear();
}

void Stack::push(int value)
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

bool Stack::pop(int& value)
{
    if (top == nullptr) {
        return false;
    }

    Node* temp = top;
    value = top->data;
    top = top->next;
    delete temp;
    return true;
}

bool Stack::peek(int& value) const
{
    if (top == nullptr) {
        return false;
    }
    value = top->data;
    return true;


}
bool Stack::isEmpty() const
{
    return top == nullptr;
}

int Stack::size() const
{
    int count = 0;
    Node* cur = top;
    while (cur != nullptr) {
        cur = cur->next;
        count++;
    }
    return count;
}

void Stack::clear()
{

    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;

    }
}

void Stack::display() const
{
    cout << "top ->";
    if (top == nullptr) {
        cout << "(Empty)";
    }

    Node* cur = top;
    while (cur != nullptr) {

        cout << "  " << cur->data;
        cur = cur->next;
    }
    cout << endl;
}