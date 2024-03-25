#include <iostream>
#pragma once
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, int S)
{
    fraction t;//������� ��������� ����������
    t.Init(F, S);//���������������� ���� ���������� t � ������� ���������� �������
    return t;//������� �������� ���������� t
}

int main()
{
    setlocale(LC_ALL, "rus");
    //����������� ���������� � � �
    fraction A;
    fraction B;
    A.Init(45000, 28);//������������� ���������� �
    A.Show();//����� �������� ����� ���������� �
    cout << "A.accrued(" << A.salary << "," << A.days << ")=" << A.Summa() << endl << endl;
    B.Read();//���� ����� ���������� �

    B.Show();//����� �������� ����� ���������� �
 
    cout << "B.accrued(" << B.salary << "," << B.days << ")=" << B.Summa() << endl << endl;
    //���������
    cout << "��������� � �������������� ����������" << endl;
    fraction* X = new fraction;//��������� ������ ��� ������������ ����������
    X->Init(22800, 13);//�������������
    X->Show();//����� �������� �����
    X->Summa();
    cout << "X.accrued(" << X->salary << "," << X->days << ")=" << X->Summa() << endl << endl;
    //�������
    cout << "3 ���� �������� ��� ����������� ��������" << endl;
    fraction mas[3];//����������� �������
    for (int i = 0;i < 3; i++)
        mas[i].Read();//������ �������� �����
    for (int i = 0;i < 3; i++)
        mas[i].Show(); //����� �������� �����
    for (int i = 0;i < 3; i++)
    {
        mas[i].Summa(); 
        cout << "mas[" << i << "].summa(" << mas[i].salary << "," << mas[i].days << ")=";
        cout << mas[i].Summa() << endl;
    }
    //������������ ������
    cout << "3 ���� �������� ��� ������������ ��������" << endl;
    fraction* p_mas = new fraction[3];//��������� ������
    for (int i = 0;i < 3; i++)
        p_mas[i].Read();//������ �������� �����
    for (int i = 0;i < 3; i++)
        p_mas[i].Show();//����� �������� �����

    for (int i = 0;i < 3; i++)
    {
        p_mas[i].Summa();
        cout << "p_mas[" << i << "].summa(" << p_mas[i].salary << "," << p_mas[i].days;
        cout << ")=" << p_mas[i].Summa() << endl;
    }
    //����� ������� make_fraction()
    double y; int z;
    cout << "salary? ";
    cin >> y;

    cout << "days worcked? ";
    cin >> z;
    //���������� F ����������� � ������� ������� make_fraction()
    fraction F = make_fraction(y, z);
    F.Show();

    return 0;
}
