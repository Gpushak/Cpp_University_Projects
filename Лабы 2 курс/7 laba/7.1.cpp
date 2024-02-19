#include <iostream>
#include <string>
using namespace std;


double mult(double dro1, double dro2) {
	return dro1 * dro2;
}

string mult(int chis1, int znam1, int chis2, int znam2) {
	string res1 = to_string(chis1 * chis2);
	string res2 = to_string(znam1 * znam2);
	return res1 + "/" + res2;
}

int main() {
	cout << mult(1.5, 0.75) << endl;
	cout << mult(1, 2, 3, 7) << endl;
	return 0;
}