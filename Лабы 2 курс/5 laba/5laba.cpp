#include <iostream> 
#include <stdlib.h>

using namespace std;
const int n = 100;
const int m = 100;

//�������� �� ����������� ������
bool isIncreasing(int* matr, int size) {
	for (int i = 1; i < size; ++i) {
		if (matr[i - 1] > matr[i]) {
			return false;
		}
	}
	return true;
}

//�������� �� �������� ������
bool isDecreasing(int* matr, int size) {
	for (int i = 1; i < size; ++i) {
		if (matr[i - 1] < matr[i]) {
			return false;
		}
	}
	return true;
}

//���������� �� ����������� �������� ������� ������������ ������
void increasing(int* matr, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; (j > 0) && (matr[j] < matr[j - 1]);j--) {
			int t = matr[j];
			matr[j] = matr[j - 1];
			matr[j - 1] = t;
		}
	}
}


int main() {
	setlocale(LC_ALL, "rus");
	cout << "������ ����� ������� ";
	int str, sto;
	cin >> str >> sto;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 100 - 50;
		}
	}
	for (int i = 0; i < str; ++i) {
		for (int j = 0; j < sto; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	//���������� � ��������� ��������
	for (int i = 0; i < str; i++) {
		if (isDecreasing(a[i], sto) == false) {
			increasing(a[i], sto);
		}
	}
	cout << endl;
	for (int i = 0; i < str; ++i) {
		for (int j = 0; j < sto; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
