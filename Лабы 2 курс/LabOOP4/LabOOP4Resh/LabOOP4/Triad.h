#pragma once
#include <iostream>
using namespace std;
class Triad
{
    //����������� ��� ����������
public:
    Triad(void);
public:
    //����������
    virtual ~Triad(void);
    //���������� � �����������
    Triad(int, int, int);
    //����������� �����������
    Triad(const Triad&);
    //���������
    int Get_first() { return first; }
    int Get_second() { return second; }
    int Get_third() { return third; }
    //������������
    void Set_first(int);
    void Set_second(int);
    void Set_third(int);
    void Plus_first();
    void Plus_second();
    void Plus_third();
    //���������� �������� ������������
    Triad& operator=(const Triad&);
    //���������� ���������-������� �����-������
    friend istream& operator>>(istream& in, Triad& c);
    friend ostream& operator<<(ostream& out, const Triad& c);
    //��������
protected:
    int first;
    int second;
    int third;
};