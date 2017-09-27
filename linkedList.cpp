#include <iostream>


using namespace std;

struct Node
{
	int data;
	Node* next;
};

class linkedList
{
private:
	Node *head, *tail;
public:
	linkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void createNode(int value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if(head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL; //there's no more temp node, it is replaced my head and tail
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		//delete temp; //wrong, this will deallocate the memory created for temp
	}
	void print()
	{
		Node *temp = new Node;
		temp = head;
		while(temp != NULL)
		{
			std::cout << temp->data << ' ';
			temp = temp->next;
		}
		cout << '\n';
		delete temp;
	}
	void push(int value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void append(int value)
	{
		createNode(value);
	}
	void insert(int value, int position)
	{
		Node *temp = new Node;
		temp->data = value;
		Node *prev = head;
		for(int i = 0; i < position-1; ++i) //careful here
		{
			prev = prev->next;
		}
		temp->next = prev->next;
		prev->next = temp;
		//std::cout <<'\n'<< head->data << ' ' << tail->data; //okay
	}
	void remove_first()
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	void remove_last()
	{
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		while(current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		delete current;
		tail = previous;
	}
	void remove(int value)
	{
		//Node *current = new Node;
		Node *current = head;
		//Node *previous = new Node;
		Node *previous;
		current = head;
		while(current->data != value && current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		if(current->data == value)
		{
			previous->next = current->next;
			delete current;
		}
		if(current->next == NULL)
		{
			std::cout << "Couldn't find value" << std::endl;
		}
	}
	int length()
	{
		int count = 1;
		Node *current = head;
		if(current == NULL)
		{
			return 0;
		}
		
		while(current->next != NULL)
		{
			count += 1;
			current = current->next;
		}
		return count;
	}
};

int main()
{
	linkedList *l = new linkedList();
	l->createNode(5);
	l->createNode(10);
	l->createNode(15);
	l->print();
	l->remove_first();
	l->print();
	l->push(7);
	l->print();
	l->remove(10);
	l->append(20);
	l->print();
	l->insert(4, 2);
	l->print();
	cout << l->length() << endl;
	return 0;
}



