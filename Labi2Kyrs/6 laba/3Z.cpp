#include <iostream >
using namespace std;

int Han(int n, int ���������_���������, int ���������������_��������, int ��������_��������) {
	if (n > 0) {
		Han(n - 1, ���������_���������, ��������_��������, ���������������_��������);
		cout << ���������_��������� << "=>" << ���������������_�������� << endl;
		Han(n - 1, ��������_��������, ���������������_��������, ���������_���������);
	}
	return 0;
}
int main() {
	setlocale(0, "rus");
	int n;
	cout << "������� ���-�� ������ ";
	cin >> n;
	Han(n, 1, 2, 3);
	return 0;
}