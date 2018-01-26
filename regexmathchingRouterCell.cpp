#include <iostream>

using namespace std;

#define SIZE (128)


struct Router
{
	Cell *next[SIZE];
};

struct Cell
{
	char data;
	Router * next;
};

class Network
{
private:
	Router* root;
	string str;
public:
	Network(string s) {
		str = s;
		root = new Router;
		for (int i = 0; i < SIZE; ++i)
		{
			root->next[i] = NULL;
		}
	}

	void createCell(char p) {
		Cell* temp = new Cell;
		temp->data = p;
		temp->next = NULL;
		if(root)
	}
	
};


int main() {
	string s = "ab";
	string p = "a*";
	Solution *sol;
	cout << sol->isMatch(s, p) << endl;
	return 0;
}