#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

int main() {
	int array[ROWS][COLS];

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			if (j > i) {
				array[i][j] = 0;
			}
			else {
				array[i][j] = i - j + 1;
			}
		}
	}

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			cout << array[i][j];
		}
		cout << endl;
	}

	return 0;
}