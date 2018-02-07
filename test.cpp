#include<iostream>
#include <vector>
using namespace std;
 
class Base {
public:
    virtual void show() { cout<<" In Base \n"; }
};
 
class Derived: public Base {
public:
    void show() { cout<<"In Derived \n"; } 
};
 
int main(void) {   
    Base *bp = new Derived;     
    bp->show();  // RUN-TIME POLYMORPHISM
    vector<int> v;
    for (int i = 1; i <= 10; i++) v.push_back(i);
    for (int i = 0; i < v.size(); ++i) cout << v[i] << endl;
    cout << '\n';
	//cout << v.back() << endl;
    vector<int> v1(v.begin() + 4, v.end() - 2);
	for (int i = 0; i < v1.size(); ++i) cout << v1[i] << endl;
    return 0;
}