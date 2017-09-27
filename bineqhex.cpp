#include <iostream>

bool compareBinToHex(string binary, string hex)
{
	int i = convertFromBase(binary, 2);
	int j = convertFromBase(hex, 16);

	if(i < 0 || j < 0)
	{
		return false;
	}
	return i == j;
}

int convertFromBase(string number, int base)
{
	
}