#include <iostream>
#include <string>
#include "Student.h"
#include "Person.h"
#include "Object.h"
#include "Vector.h"
using namespace std;

int main()
{
    Person* a = new Person;//������� ������ ������ Car
    a->Input();
    Student* b = new Student; //������� ������ ������ Lorry
    b->Input();

    Vector v(10);//������� ������
    v.Add();//��������� ������ � ������
    v.Add(); //��������� ������ � ������
    v.Add();
    v.Show();//����� �������
    v.Del();//�������� ��������
    cout << "\nVector size=" << v();
    return 0;
}
