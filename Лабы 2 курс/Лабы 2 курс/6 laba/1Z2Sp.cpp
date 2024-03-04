#include <iostream>
using namespace std;

//Функция вычисления факториала
double fac(int n) {
	return (n == 1 || n == 0) ? 1 :
		fac(n - 1) * n;
}

int main() {
	int n, x;
	double s = 1;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		s = s + ((2 * i + 1) / fac(i)) * (pow(x, 2 * i));
	}
	cout << s;
}
