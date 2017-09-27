#include <iostream>

using namespace std;

class ExprTerm
{
public:
	double coeff;
	double exp;
	
};

int main()
{
	ExprTerm[] sum(ExprTerm[] expr1 + ExprTerm[] expr2)
	{
		if(expr1.length == expr2.length)
		{
			ExprTerm[expr1.length] result;

			for(int i = 0; i < expr1.length; ++i)
			{
				ExprTerm temp;
				temp.coeff = expr1[i].coeff + expr2[i].coeff;
				temp.exp = expr1[i].exp + expr2[i].exp;
				result[i] = temp;
			}
		}
		return result;
	}
}