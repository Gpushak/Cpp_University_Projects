#include <iostream>
using namespace std;

//������� ���������� ����������
double fac(int n) {
	return (n == 1 || n == 0) ? 1 :
		fac(n - 1) * n;
}

//����������� �������
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