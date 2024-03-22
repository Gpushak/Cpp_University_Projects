#pragma once
#include <vector>

void InsertionSort(vector<int>& vect) {
	if (vect.size() < 2) {
		return;
	}

	for (int i = 1; i < vect.size(); i++) {
		int currentIndex = i;
		int current = vect[currentIndex];
		for (; currentIndex >= 1 && vect[currentIndex - 1] > current; currentIndex--) {
			vect[currentIndex] = vect[currentIndex - 1];
		}
		vect[currentIndex] = current;
	}
}