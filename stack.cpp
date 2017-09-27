#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

class stackArray
{
private:
	int top;

public:
	static const int size = 1000;
	int arr[size];
	stackArray()
	{
		top = -1;
	};

	bool push(int value)
	{
		if(top >= size)
		{
			cout << "Stack Overflow" << endl;
			return false;
		}
		arr[++top] = value;
		return true;
	}
	
	int pop()
	{
		if(top < 0)
		{
			cout << "Stack underflow" << endl;
			return 0;
		}

		return arr[top--];
	}
	
	bool isEmpty()
	{
		return top > 0;
	}
};

class stackLinkedList
{
private:
	Node *head;
public:
	stackLinkedList()
	{
		head = NULL;
	}

	bool push(int value)
	{
		Node *temp = new Node();
		temp->data = value;
		if(head == NULL)
		{
			temp->next = NULL;
			head = temp;
			return true;
		}
		temp->next = head;
		head = temp;
		return true;
	}

	int pop()
	{
		if(head == NULL)
		{
			cout << "Stack is empty" << endl;
			return -1;
		}

		Node *temp = head;
		int res = head->data;
		head = head->next;
		delete temp;
		return res;
	}
	
	bool isEmpty()
	{
		return head == NULL;
	}
	
};

int main()
{
	/*
	stackArray *s1 = new stackArray();
	s1->push(10);
	s1->push(20);
	s1->push(30);
	cout << s1->pop() << endl;
	cout << s1->isEmpty() << endl;
	*/

	stackLinkedList *s2 = new stackLinkedList();
	s2->push(19);
	s2->push(82);
	//s2->push(22);
	//s2->push(662);
	cout << s2->pop() << endl;
	cout << s2->pop() << endl;
	cout << s2->isEmpty() << endl;

	return 0;
}




