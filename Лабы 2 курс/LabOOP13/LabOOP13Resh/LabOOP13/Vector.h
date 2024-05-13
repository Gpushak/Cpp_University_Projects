#pragma once
#include <iostream>
using namespace std;
class Vector
{
public:
    //����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
    //��������� k
    Vector(int s, int k = 0);
    //����������� � �����������
    Vector(const Vector& a);
    //����������
    ~Vector();
    //�������� ������������
    Vector& operator=(const Vector& a);
    //�������� ������� �� �������
    int& operator[](int index);
    //�������� ��� ���������� ���������
    Vector operator+(const int k);
    //��������, ������������ ����� �������
    int operator()();
    //������������� �������� �����-������
    friend ostream& operator<<(ostream& out, const Vector& a);
    friend istream& operator>>(istream& in, Vector& a);
private:
    int size;//������ �������
    int* data;//�������� �� ������������ ������ �������� �������
};
