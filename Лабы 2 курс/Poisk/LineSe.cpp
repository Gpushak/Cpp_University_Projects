#include <iostream>

using namespace std;

int LineSe(int mas[], int key, const int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] == key) {
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	setlocale(LC_ALL, "rus");
	const int n = 9;
	int mas[n] = { 8, 0, 12, -74, 85, 12, 4, 7, 12 };
	int key;
	cout << "MASS: ";
	for (int i = 0; i < n; i++) {
		cout << mas[i] << ' ';
	}
	cout << endl << "Enter key: ";
	cin >> key;
	cout << "So: " << LineSe(mas, key, n);
}