#include "Money.h"
#include <iostream>
using namespace std;

void main()
{
    Money a;//����������� ��� ����������
    Money b; //����������� ��� ����������
    cin >> a;//���� ����������
    cin >> b;//���� ����������
    ++a;//���������� �������� ���������
    cout << a << endl;//����� ����������
    cout << "a=" << a << endl; //����� ����������
    cout << "b=" << b << endl; //����� ����������
    if (a > b) {
        cout << "a > b";
    }
    else if (a < b) {
        cout << "a < b";
    }
    else {
        cout << "a = b";
    }
}
