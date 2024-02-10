#include <iostream>

using namespace std;
const int SIZE = 10;



int main() {
	int a[SIZE][SIZE];
	int count = 1;

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if ((i + j) % 2 != 0) {
				a[i][j] = 0;
			}
			else {
				a[i][j] = count;
				if (count == 9) {
					count = 1;
				}
				else {
					count++;
				}
			}
		}
	}
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}