#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//������� ��� �������� ������� ��� ����������
car make_car()
{
    string s;
    string i;
    int d;
    cout << "������� �����: ";
    cin >> s;
    cout << "������� ������: ";
    cin >> i;
    cout << "������� ����: ";
    cin >> d;
    car t(s, i, d);
    return t;
}
//������� ��� �������� ������� ��� ���������
void print_car(car t)
{
    t.show();
}
void main()
{
    setlocale(LC_ALL, "rus");
    //����������� ��� ����������
    car t1;
    t1.show();
    //���������� � �����������
    car t2("Lada", "2101", 100000);
    t2.show();
    //����������� �����������
    car t3 = t2;
    t3.set_brand("Dodge");
    t3.set_name("Charger");
    t3.set_price(4000000);
    //����������� �����������
    print_car(t3);
    //����������� �����������
    t1 = make_car();
    t1.show();
}
