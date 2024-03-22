#pragma once
#include <vector>

void ShellSort(vector<int>& vect) {
    if (vect.size() < 2) {
        return;
    }

	for (int step = vect.size() / 2; step > 0; step /= 2) {
        for (int i = step; i < vect.size(); ++i) {
            for (int j = i - step; j >= 0 && vect[j] > vect[j + step]; j -= step) {
                swap(vect[j], vect[j + step]);
            }
        }
	}
}