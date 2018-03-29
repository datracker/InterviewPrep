#include<iostream>
#include <vector>
#include <unordered_map>

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
    /*
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
    */
    string s = "barfoofoobarthefoobarman";
    vector<string> l = {"bar", "foo", "the"};
    std::unordered_map <string, int> dict;
    for(int i=0; i < l.size(); ++i) dict[l[i]]++;
    for( const auto& n : dict ) std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    cout << dict.count("has") << endl;

    //for(int i=0; i < dict.size(); ++i) cout << dict[i] << endl;
    return 0;
}