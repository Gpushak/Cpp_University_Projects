#include <iostream >
using namespace std;

int fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int main() {
	setlocale(LC_ALL, "rus");
	int amount;
	cout << "¬ведите нужное кол-во чисел ";
	cin >> amount;

	while (amount < 1) {

		cout << "Error ";
		cin >> amount;
	}

	for (int num = 0; num < amount; num++) {
		cout << fib(num) << endl;
	}

}