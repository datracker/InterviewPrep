#include <iostream>

using namespace std;

bool regex_matching(string str, string expr) {
	if (expr.empty()) return str.empty();

	if (expr[1] == '*') {
		return regex_matching(str, expr.substr(2)) || (!expr.empty() && (str[0]==expr[0] || '.'==expr[0]) && 
			regex_matching(str.substr(1), expr));
	}
	else {
		return (!expr.empty() && (str[0]==expr[0] || expr[0]=='.') && 
			regex_matching(str.substr(1), expr.substr(1)));
	}
}

int main() {

	string s = "cccaaaab";
	string p = "c*a*b";

	cout << regex_matching(s,p) << endl;
	return 0;
}