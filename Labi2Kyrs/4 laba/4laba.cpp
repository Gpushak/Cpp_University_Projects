#include <iostream> 
#include <stdlib.h>

using namespace std;
const int N = 100;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите размер массива не больше 100" << endl;
	cin >> n;
	while (n > 100) {
		cout << "Ошибка! Введите массив не больше 100 элементов!" << endl;
		cin >> n;
	}
	int a[N];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 - 50;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << endl;
	n = n - 2;
	for (int i = 0;i < 3; i++) {
		for (int j = n - 1; j > i - 1; j -= 1) {
			a[j] = a[j - 1];
		}
	}
	for (int i = 2; i > -1; i--) {
		a[i] = a[i + 1] + 2;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}