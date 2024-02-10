//����� ����������� �������

#include <iostream> 
#include <cmath>

using namespace std;
const double eps = 1e-5;

double f(double x) {
	return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c;
	cout << "������� ������� ������ ������� a, ����� ����� ������� b" << endl;
	cin >> a >> b;
	while ((b - a) > eps) {
		c = (a + b) / 2;
		if (f(b) * f(c) < 0)
			a = c;
		else
			b = c;
	}
	cout << "���������� ��������: " << (a + b) / 2 << endl;

	return 0;

}