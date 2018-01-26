#include <iostream>
#include <vector>


using namespace std;

double medianoftwoarrays(vector<int>& arr1, vector<int>& arr2) {
	int N1 = arr1.size();
	int N2 = arr2.size();

	if (N1 < N2) return medianoftwoarrays(arr2, arr1);
	int locutindex = 0; int hicutindex = N2 * 2;

	while(locutindex <= hicutindex) {
		int cutindex2 = (locutindex + hicutindex) / 2;
		int cutindex1 = N1 + N2 - cutindex2;

		int L1 = (cutindex1 == 0)? INT_MIN : arr1[(cutindex1-1)/2]; 
		int R1 = (cutindex1 == N1 * 2)? INT_MAX : arr1[(cutindex1)/2];
		int L2 = (cutindex2 == 0)? INT_MIN : arr2[(cutindex2-1)/2]; 
		int R2 = (cutindex2 == N2 * 2)? INT_MAX : arr2[(cutindex2)/2];
		cout << L1 << ' ' << R1 << ' ' << L2 << ' ' << R2 << ' ' << endl;

		if (L2 > R1) hicutindex = cutindex2 - 1;
		else if (L1 > R2) locutindex = cutindex2 + 1;
		else return (max(L1, L2) + min(R1, R2)) / 2.0;
	}
	return -1;
}

int main() {

	vector<int> a = {1, 2};
	vector<int> b = {3, 4};

	double median = medianoftwoarrays(a, b);
	cout << median << endl;
	return 0;
}