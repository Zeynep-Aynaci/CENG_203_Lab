#include"Queue.h"
#include<iostream>
using namespace std;


Queue::Queue()
{
	Node* front = nullptr;
	Node* rear = nullptr;
	count = 0;
}

Queue::~Queue()
{
	while (front != nullptr) {
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	rear = nullptr;
	count = 0;
}
void Queue::enqueue(int value)
{
	Node* newNode = new Node(value);
	if (front == nullptr) {
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	count++;
}

bool Queue::dequeue(int& value)
{
	if (front == nullptr) {
		return false;
	}
	Node* temp = front;
	value = temp->data;
	front = front->next;
	delete temp;
	count--;

	if (front == nullptr) {
		rear = nullptr;
	}

	return true;
}

bool Queue::peek(int& value) const
{
	if (front == nullptr) {
		return false;
	}
	value = front->data;
	return true;
}

bool Queue::isEmpty() const
{
	return front == nullptr;
}

int Queue::size() const
{
	return count;
}

void Queue::display() const
{
	cout << " front-> ";

	if (front == nullptr) {
		cout << "(Empty)";
	}
	else {
		Node* cur = front;
		while (cur != nullptr) {
			cout << "  " << cur->data;
			cur = cur->next;
		}
		cout << " <- rear";
	}
	cout << endl;
}