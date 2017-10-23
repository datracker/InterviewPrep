#include <iostream>

using namespace std;

void heapifyDown(int index, int* arr, int length);

void swap(int *x, int *y)
{
	//&x is the address of x, *x is the value of the variable whose address is in x
	int temp = *x;
	*x = *y;
	*y = temp;
}

class MinHeap
{
private:
	int *harr; //pointer to the heap array containing the elements of the heap
	int capacity; //the capacity of the heap
	int heap_size; //current number of elements in the heap

public:
	MinHeap(int size)
	{
		heap_size = 0;
		capacity = size;
		harr = new int[size];
	}

	int parent(int index) {return (index-1)/2;}
	int leftChild(int index) {return (2*index)+1;}
	int rightChild(int index) {return (2*index)+2;}

	void insertKey(int value)
	{
		if(heap_size >= capacity)
		{
			cout << "Overflow: Could not insert key. \n" ;
			return;
		}

		//first insert the new key at the end
		harr[heap_size] = value;
		heap_size++; //increasing the heap size for the next key to enter
		//int i = heap_size - 1; //we need i to track from inserted position of the new key to the root

		//making sure the MinHeap property is maintained
		heapifyUp(heap_size-1);
	}

	//decreaseKey will decrease the value of a key on given index. the new key will be smaller than
	//the previous value. So, there should be an heapifyUP to maintain the minHeap property.
	void decreaseKey(int index, int new_val)
	{
		if(index >= heap_size) 
		{
			cout << "Index out of heap size" <<endl;
			return;
		}
		harr[index] = new_val;	
		heapifyUp(index);
		
	}
	//This function deletes the key at given index
	void deleteKey(int index)
	{
		decreaseKey(index, INT_MIN);
		extractMin();
	}

	//To heapifyUp a subtree given the index
	void heapifyUp(int index)
	{
		while(index > 0 && harr[index] < harr[parent(index)])
		{
			swap(&harr[index], &harr[parent(index)]);
			index = parent(index);	
		}
	}

	//To heapifyDown a subtree with root at given index
	void heapifyDown(int index)
	{
		int l = leftChild(index);
		int r = rightChild(index);
		int smallest = index;

		if(harr[l] < harr[r] && l <= heap_size)
		{
			smallest = l;
		}
		if(harr[r] < harr[index] && r <= heap_size)
		{
			smallest = r;
		}
		if(smallest != index)
		{
			swap(&harr[index], &harr[smallest]);
			heapifyDown(smallest); 
		}
	}

	//Extracts the root or the minimum value of the heap
	int extractMin()
	{
		if (heap_size == 0) { return INT_MAX; }
		if (heap_size == 1)
		{
			heap_size--;
			return harr[0];
		}
		int res = harr[0];
		harr[0] = harr[heap_size - 1];
		heap_size--;
		heapifyDown(0);
		return res;
	}

	void printHeap()
	{
		for (int i = 0; i < heap_size; ++i)
		{
			cout << harr[i] << ' ';
		}
		cout << '\n';
	}

	void makeHeap(int *arr, int length)
	{
		for (int i = length/2; i < 0; --i)
		{
			
		}
	}

};

int leftChild(int index) {return (2*index)+1;}
int rightChild(int index) {return (2*index)+2;}

void heapifyDown(int index, int* arr, int length)
{
	int l = leftChild(index);
	int r = rightChild(index);
	int smallest = index;

	if(arr[l] < arr[r] && l <= length)
	{
		smallest = l;
	}
	if(arr[r] < arr[index] && r <= length)
	{
		smallest = r;
	}
	if(smallest != index)
	{
		swap(&arr[index], &arr[smallest]);
		heapifyDown(smallest, arr, length); 
	}
}

void makeHeap(int *arr, int length)
{	
	for (int i = 0; i < length/2-1; ++i)
	{
		heapifyDown(i, arr, length);
		//cout << "Here" << endl;
	}
}

int main()
{
	//MinHeap *h = new MinHeap(11);
	//cout << h->parent(5) << ' ' << h->leftChild(4) << ' ' << h->rightChild(3) << endl;
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.insertKey(7);
	h.insertKey(1);
	h.insertKey(17);
	h.printHeap();
	//h.decreaseKey(4, 4);
	//cout << h.extractMin() << endl;
	//h.printHeap();
	//h.deleteKey(2);
	//h.printHeap();
	int arr[] = {17, 1, 3, 2, 7};//, 12, 23, 67, 8};
	makeHeap(arr, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}


























