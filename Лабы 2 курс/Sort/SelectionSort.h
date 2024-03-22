#pragma once
#include <vector>

void SelectionSort(vector<int>& vect) {
	if (vect.size() < 2) {
		return;
	}

	for (int i = 0; i < vect.size(); i++) {
		int LocalMinIndex = i;
		for (int j = i + 1; j < vect.size(); j++) {
			if (vect[LocalMinIndex] > vect[j]) {
				LocalMinIndex = j;
			}
		}
		swap(vect[i], vect[LocalMinIndex]);
	}
}