#include <iostream>
using namespace std;

//Функция вычисления факториала
double fac(int n) {
	return (n == 1 || n == 0) ? 1 :
		fac(n - 1) * n;
}

//Рекурсивная функция
double rek(double n, double x) {
	if (n == 0) {
		return 1;
	}
	else {
		return ((2 * n + 1) / fac(n)) * (pow(x, 2 * n)) + rek(n - 1, x);
	}
}


int main() {
	int n, x;
	cin >> n >> x;
	cout << rek(n, x);
}