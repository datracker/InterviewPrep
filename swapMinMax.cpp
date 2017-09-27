#include <iostream>

using namespace std;

void swapMinMax(int arr[], int len);
int* minmaxIndex(int arr[], int len);
void swapIndex(int arr[], int min, int max);
void printArr(int arr[], int len);


int main()
{
	int arr[] = {2,3,4,5,7,8,0,9,9,8,7};
	int length = sizeof(arr)/sizeof(arr[0]);
	printArr(arr, length);
	swapMinMax(arr, length);
	printArr(arr, length);
	return 0;
}

void swapMinMax(int arr[], int len)
{
	int* indexes;
	indexes = minmaxIndex(arr, len);
	swapIndex(arr, *indexes, *(indexes+1));
}

int* minmaxIndex(int arr[], int len)
{
	int tempMinIndex = 0;
	int tempMaxIndex = 0;
	int* res = new int[2];
	for(int i = 1; i < len; ++i)
	{
		if (arr[tempMinIndex] > arr[i])
		{
			tempMinIndex = i;
		}
		if (arr[tempMaxIndex] < arr[i])
		{
			tempMaxIndex = i;
		}
	}
	res[0] = tempMinIndex;
	res[1] = tempMaxIndex;
	delete [] res;
	return res;
}

void swapIndex(int arr[], int min, int max)
{
	int temp = arr[min];
	arr[min] = arr[max];
	arr[max] = temp;
}

void printArr(int arr[], int len)
{	
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}
