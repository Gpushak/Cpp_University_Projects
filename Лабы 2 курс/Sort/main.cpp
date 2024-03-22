#include <iostream>
#include <vector>
using namespace std;

#include "BubbleSort.h"
#include "CountingSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "BucketSort.h"
#include "QuickSort.h"
#include "HoareSort.h"

void WriteVector(vector<int>& vect) {
	if (vect.size() > 0) {
		cout << vect[0];
	}
	for (int i = 1; i < vect.size(); i++) {
		cout << ' ' << vect[i];
	}
	cout << '\n';
}

bool IsEqualVectors(vector<int>& firstVect, vector<int>& secondVect) {
	bool isEqual = firstVect.size() == secondVect.size();
	for (int i = 0; i < firstVect.size() && isEqual; i++) {
		isEqual = firstVect[i] == secondVect[i];
	}
	return isEqual;
}

bool IsSortAscendingVector(vector<int>& vect) {
	if (vect.size() < 2) {
		return true;
	}

	bool isSort = true;
	for (int i = 1; i < vect.size() && isSort; i++) {
		isSort = vect[i - 1] <= vect[i];
	}
	return isSort;
}

typedef void(*ptr)(vector<int>&);

int main() {
	ptr functionPointers[] = {
		&BubbleSort, &CountingSort, &SelectionSort,
		&InsertionSort, &ShellSort, &MergeSort,
		&BucketSort, &QuickSort, &HoareSort }; 

	for (ptr i : functionPointers) {
		vector<int> vect = { 45, 96, 73, 43, 64, 12, 90, 88, 23, 45 };
		i(vect);
		if (IsSortAscendingVector(vect)) {
			cout << "True\n";
		}
		else {
			WriteVector(vect);
		}
	}
}