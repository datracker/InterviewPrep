#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> vec;

	for (int i = 0; i<5; ++i)
	{
		vec.push_back(i);
	}

	for (int i = 0; i < 5; ++i)
	{
		cout << i << " th element is the vector is: " << vec[i] << endl;
	}

	std::vector<int>::iterator v = vec.begin();
	while(v != vec.end())
	{
		cout << "value of v = " << *v << endl;
		v++;
	}



	cout << "vector size = " << vec.size() << endl;
}