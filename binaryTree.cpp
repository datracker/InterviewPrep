#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;


struct Node
{
	int data;
	Node *left, *right;
};

class binaryTree
{
private:
	Node *root;
public:
	binaryTree()
	{
		root = newNode(1);
		root->left = newNode(2);
    	root->right = newNode(3);
    	//root->right->right = newNode(6);
    	root->left->left = newNode(4);
    	root->left->right= newNode(5);
    	//cout << root->data << root->left->data 
    	//<< root->right->data << root->left->left->data << root->left->right->data <<endl;
	}
	Node *newNode(int value)
	{
    	Node* temp = new Node();
    	temp->data = value;
		temp->left = NULL;
    	temp->right = NULL;
	    return(temp);
	}
	bool push(int value, int side)
	{
		Node *temp = new Node();
		temp->data = value;
		if(side == 0)
		{
			temp->left = root;
			temp->right = NULL;
		}
		else
		{
			temp->right = root;
			temp->left = NULL;	
		}
		root = temp;	
		return true;
	}

	void bfs()
	{
		int h = height(root);
		cout << h << endl;
    	for (int i=1; i<=h; ++i)
    	{
        	printGivenlevel(root, i);
    	}
    	cout << '\n';
	}
	int height(Node *root)
	{
		if(root == NULL)
		{
			return 0;
		}
		int lheight = height(root->left);
		int rhright = height(root->right);

		if(lheight > rhright)
		{
			return ++lheight;
		}
		else return ++rhright;
	}
	void printGivenlevel(Node *root, int level)
	{
		if(root == NULL)
		{
			return;
		}
		if(level == 1)
		{
			cout << root->data << ' ';
		}
		else if(level > 1)
		{
			printGivenlevel(root->left, level-1);
			printGivenlevel(root->right, level-1);
		}
	}
	void printGivenlevelusingQueue()
	{
		if (root == NULL) return;

		queue <Node *> q;
		q.push(root);

		while(!q.empty())
		{
			Node *temp = q.front();
			cout << temp->data << ' ';
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
			q.pop();
		}
		cout << '\n';
	}

	void printDFS()
	{
		cout << "Pre-Order Traversal:" << endl;
		printPreOrderRecursion(root);
		cout << endl;
		printPreOrderStack();

		cout << "In-Order Traversal:" << endl;
		printInOrderRecursion(root);
		cout << endl;
		printInorderStack();
		
		cout << "Post-Order Traversal:" << endl;
		printPostOrderRecursion(root);
		cout << endl;
		printPostOrderStack();
	}
	void printInorderStack()
	{
		if (root == NULL) return;

		stack <Node *> s;
		Node *temp = root;
		s.push(temp);

		while(temp->left)
		{
			s.push(temp->left);
			temp = temp->left;
		}

		while(!s.empty())
		{
			Node *temp = s.top();
			cout << temp->data << ' ';
			if(temp->right)
			{
				cout << temp->right->data << ' ';
			}
			s.pop();
		}
		cout << '\n';
	}
	void printPreOrderStack()
	{
		stack <Node *> s;
		s.push(root);

		while(!s.empty())
		{
			Node *temp = s.top();
			cout << temp->data << ' ';
			s.pop();
			if(temp->right) s.push(temp->right);
			if(temp->left) s.push(temp->left);
		}
		cout << '\n';
	}
	void printPostOrderStack()
	{
		if (root == NULL) return;

		stack <Node *> s;
		map <Node *, bool> m;
		s.push(root);

		while(!s.empty())
		{
			Node *curr = s.top();

			if(!m[curr])
			{
				if(curr->right) s.push(curr->right);
				if(curr->left) s.push(curr->left);
				m[curr] = 1;
			}
			else
			{
				cout << curr->data << ' ';
				s.pop();
			}
		}
		cout << '\n';
	}
	void printInOrderRecursion(Node *root)
	{
		if(root == NULL) return;
		printInOrderRecursion(root->left);
		cout << root->data << ' ';
		printInOrderRecursion(root->right);
	}
	void printPreOrderRecursion(Node *root)
	{
		if(root == NULL) return;

		cout << root->data << ' ';
		printPreOrderRecursion(root->left);
		printPreOrderRecursion(root->right);
	}
	void printPostOrderRecursion(Node *root)
	{
		if(root == NULL) return;
		printPostOrderRecursion(root->left);
		printPostOrderRecursion(root->right);
		cout << root->data << ' ';
	}
	void countLeafNode()
	{
		cout << "Number of leaf nodes: " << countLeafNode(root) << endl;
	}
	int countLeafNode(Node *root)
	{
		//using recursion. Time: O(n), space: O(n)
		if (root == NULL) return 0;
		else if(root->left == NULL and root->right == NULL) return 1;
		else return countLeafNode(root->left)+countLeafNode(root->right);
	}
	
};

int main()
{
	binaryTree *b = new binaryTree();
	//cout << b->push(1, 0) << endl;
	//cout << b->push(2, 1) << endl;
	//cout << b->push(5, 1) << endl;
	//cout << b->push(8, 0) << endl;
	//b->bfs();
	//b->printGivenlevelusingQueue();
	//b->printInorder();
	b->printDFS();
	b->countLeafNode();

	return 0;
}