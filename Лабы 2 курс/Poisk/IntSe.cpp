#include <iostream>

using namespace std;

int IntSe(int arr[], const int n, int key) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (((key - arr[left]) * (right - left)) / (arr[right] - arr[left]));
		if (arr[mid] == key) {
			return mid;
		}
		else {
			if (arr[mid] < key) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
	return -1;
}

int main() {
	setlocale(LC_ALL, "rus");
	const int n = 9;
	int mas[n] = { 2, 4, 5, 7, 8, 11, 13, 31, 54 };
	int key;
	cout << "MASS: ";
	for (int i = 0; i < n; i++) {
		cout << mas[i] << ' ';
	}
	cout << endl << "Enter key: ";
	cin >> key;
	cout << "So: " << IntSe(mas, n, key) + 1;
}