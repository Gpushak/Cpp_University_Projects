#include <iostream>
#include "Triad.h"
#include "Time.h"
#include "Object.h"
#include "Vector.h"
using namespace std;
// ���������� �������
void main()
{
    Vector v(5);//������ �� 5 ���������
    Triad a;//������ ������ Car
    cin >> a;
    Time b;// ������ ������ Lorry
    cin >> b;
    Object* p = &a;//������ ��������� �� ������ ������ Car
    v.Add(p);//��������� ������ � ������
    p = &b;//������ ��������� �� ������ ������ Lorry
    v.Add(p); //��������� ������ � ������
    cout << v;//����� �������
}
