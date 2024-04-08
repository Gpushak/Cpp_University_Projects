#include "Person.h"
#include <string>
#include <iostream>
using namespace std;
//����������� ��� ����������
Person::Person(void)
{
    name = "";
    age = 0;
}
//����������
Person::~Person(void)
{
}
//���������� � �����������
Person::Person(string M, int C)
{
    name = M;
    age = C;
}
//����������� �����������
Person::Person(const Person& car)
{
    name = car.name;
    age = car.age;
}
//���������
void Person::Set_age(int C)
{
    age = C;
}
void Person::Set_name(string M)
{
    name = M;
}
//�������� ������������
Person& Person::operator=(const Person& c)
{
    if (&c == this)return *this;
    name = c.name;
    age = c.age;
    return *this;
}
//����� ��� ��������� ���������
void Person::Show()
{
    cout << "\nNAME : " << name;
    cout << "\nAGE : " << age;
    cout << "\n";
}
//����� ��� ����� �������� ���������
void Person::Input()
{
    cout << "\nname:"; cin >> name;
    cout << "\nage:";cin >> age;
}
