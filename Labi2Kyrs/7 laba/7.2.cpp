#include <iostream>
#include <cstdarg>
#include <utility>
using namespace std;
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

pair<int, int> reduceFraction(int num, int den) {
	int div = gcd(num, den);
	return make_pair(num / div, den / div);
}

pair<int, int> sum(int count, ...) {
	va_list args;
	va_start(args, count);

	int num = 0;
	int den = 1;

	for (int i = 0; i < count; ++i) {
		int chis = va_arg(args, int);
		int znam = va_arg(args, int);

		num += chis * (lcm(den, znam) / znam);
		den = lcm(den, znam);
	}

	va_end(args);

	return reduceFraction(num, den);
}

int main() {
	setlocale(LC_ALL, "rus");
	// Вызов функции sum с разным количеством параметров
	pair<int, int> result1 = sum(5, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6);
	pair<int, int> result2 = sum(10, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11);
	pair<int, int> result3 = sum(12, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13);

	// Вывод результатов
	cout << "Сумма дробей 1: " << result1.first << "/" << result1.second << endl;
	cout << "Сумма дробей 2: " << result2.first << "/" << result2.second << endl;
	cout << "Сумма дробей 3: " << result3.first << "/" << result3.second << endl;

	return 0;
}