//Метод Ньютона

#include <iostream> 
#include <cmath>

using namespace std;
const double epsi = 0.000001;

double f(double x) {
	return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

double dif(double x) {
	return (-2 * sqrt(100 - 30 * pow(x, 3)) + 9 * pow(x, 2) * sqrt(1 - pow(x, 2))) / (2 * sqrt(30 * pow(x, 5) - 30 * pow(x, 3) - 100 * pow(x, 2) + 100));
}

double secdif(double x) {
	return (-sqrt(100 - (30 * pow(x, 2))) * (40000 - (24000 * pow(x, 3)) + (3600 * pow(x, 6))) * x + sqrt(1 - pow(x, 2)) * (360000 * x - 135000 * pow(x, 4) + 8100 * pow(x, 7) - 360000 * pow(x, 3) + 135000 * pow(x, 6) - 8100 * pow(x, 9))) / (sqrt(100 - 30 * pow(x, 3) - 100 * pow(x, 2) + 30 * pow(x, 5)) * (1 - pow(x, 2)) * (40000 - 24000 * pow(x, 3) + 3600 * pow(x, 6)));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double x1, x2, a = 0, b = 1;
	bool solution = true;

	if ((f(a) * secdif(a) > 0)) {
		x2 = b;
	}
	else if ((f(b) * secdif(b) > 0)) {
		x2 = a;
	}
	else {
		cout << "Точки не подходят для решения данным способом";
		solution = false;
	}
	if (solution) {
		int cnt = 0;
		do {
			cnt++;
			x1 = x2;
			x2 = x1 - f(x1) / dif(x1);
			if (x2 > b)
			{
				solution = false;
			}
			else if (x2 < a)
			{
				solution = false;
			}
		} while (abs(x2 - x1) > epsi && solution);
		if (solution) {
			cout << "Полученное значение: " << x2 << endl << "Найдено за " << cnt << " итераций цикла" << endl;
		}
		else {
			cout << "Решения нет";
		}
	}

}