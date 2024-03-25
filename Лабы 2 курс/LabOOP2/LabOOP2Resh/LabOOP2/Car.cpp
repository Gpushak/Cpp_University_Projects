#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//����������� ��� ����������
car::car()
{
    brand = "";
    name = "";
    price = 0;
    cout << "����������� ��� ���������� ��� ������� " << this << endl;
}
//����������� � �����������
car::car(string N, string B, int S)
{
    brand = N;
    name = B;
    price = S;
    cout << "����������� � ����������� ��� ������� " << this << endl;
}
//����������� �����������
car::car(const car& t)
{
    brand = t.brand;
    name = t.name;
    price = t.price;
    cout << "����������� ����������� ��� ������� " << this << endl;
}
//����������
car::~car()
{
    cout << "���������� ��� �������� " << this << endl;
}
//���������
string car::get_brand()
{
    return brand;
}
string car::get_name()
{
    return name;
}
int car::get_price()
{
    return price;
}
//������������
void car::set_brand(string N)
{
    brand = N;
}
void car::set_name(string B)
{
    name = B;
}
void car::set_price(int S)
{
    price = S;
}
//����� ��� ��������� ���������
void car::show()
{
    cout << "����� :" << brand << endl;
    cout << "������ :" << name << endl;
    cout << "���� :" << price << endl;
}
