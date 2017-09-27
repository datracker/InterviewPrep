#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *prev, *next;
};

class doublyLinkedList
{
private:
	Node *head, *tail;

public:
	doublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void push(int value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = head;
		temp->prev = NULL;
		if(head != NULL)
		{
			head->prev = temp; //change the prev pointer only if there's a head node
		}
		if(head == NULL && tail == NULL)
		{
			tail = temp;
		}
		head = temp; //update the address of head
		cout <<"Pushed "<< value << endl;
		this->insert_after(67, head);
		this->print();
	}

	void append(int value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (tail != NULL)
		{
			tail->next = temp;
		}
		temp->prev = tail;
		tail = temp;
		cout << "Appended: " << value << endl;
		this->print();
	}

	void insert_after(int value, Node *prev_node)
	{
		if (prev_node == NULL)
		{
			cout << "Previous node cannot be NULL" <<endl;
		}
		if(prev_node->next == NULL)
		{
			append(value);
		}
		Node *temp = new Node;
		temp->data = value;
		temp->prev = prev_node;
		temp->next = prev_node->next;
		prev_node->next = temp;
		if(temp->next != NULL)
		{
			temp->next->prev = temp;
		}
	}

	void print()
	{
		if(head == NULL)
		{
			return;
		}
		Node *temp = new Node;
		temp = head;
		cout << "head: " << head->data << " tail: " << tail->data << endl;
		while (temp != NULL)
		{
			cout << temp->data << ' ';
			temp = temp->next;
		}
		cout << '\n';
		delete temp;
	}

	void print_reverse()
	{
		Node *temp = new Node;
		temp = tail;
		while(temp != NULL)
		{
			cout << temp->data << ' ';
			temp = temp->prev;
		}
		cout << '\n';
		delete temp;
	}
	bool detect_cycle()
	{
		Node *fast, *slow;
		fast = head;
		slow = head;

		while(fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast)
			{
				return true;
			}
		}
		return false;
	}
	void create_cycle()
	{
		tail->next = head->next->next;
	}
	
};

int main()
{
	doublyLinkedList *dl = new doublyLinkedList();
	dl->push(10);
	dl->append(8);
	dl->push(2);
	dl->append(19);
	dl->print_reverse();
	cout << dl->detect_cycle() << endl;
	dl->create_cycle();
	cout << dl->detect_cycle() << endl;
	return 0;
}