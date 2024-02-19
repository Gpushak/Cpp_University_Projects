//Метод итераций

#include <iostream> 
#include <cmath>

using namespace std;
const double epsi = 1e-3;

double fi(double x) {
	return x + x * acos(x) - x * sqrt(1 - 0.3 * pow(x, 3));
}

double difi(double x) {
	return 1 - acos(x) + x / (sqrt(1 - pow(x, 2))) + 0.1 * sqrt(100 - 30 * pow(x, 3)) - (9 * pow(x, 3)) / (2 * sqrt(100 - 30 * pow(x, 3)));
}

int main() {
	setlocale(LC_ALL, "Russian");
	double subst = 1;
	double a = 0, b = 1, e = 0.000001, x0, x1;

	bool solution = true;
	cin >> x0;
	if (x0 > 0 || x0 < 1) {
		if (abs(difi(x0)) > 1 || x0 == 0) {
			solution = false;
			cout << "x0 не подходит";
		}
	}
	else {
		solution = false;
		cout << "x0 вне диапозона" << endl;
	}
	if (solution) {
		bool flag = true;
		int cnt = 0;
		do {
			cnt++;
			x1 = fi(x0);
			subst = abs(x1 - x0);
			x0 = x1;
		} while (subst > e && flag);
		cout << "Решение: " << x1 << endl << "Найдено за " << cnt << " итераций цикла" << endl;
	}
	return 0;
}
