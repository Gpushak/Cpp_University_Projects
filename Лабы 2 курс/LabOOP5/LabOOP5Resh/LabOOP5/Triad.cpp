#include "Triad.h"
//����������� ��� ����������
Triad::Triad(void)
{
    first = 0;
    second = 0;
    third = 0;
}
//����������
Triad::~Triad(void)
{
}
//����������� � �����������
Triad::Triad(int M, int C, int P)
{
    first = M;
    second = C;
    third = P;
}
//����������� �����������
Triad::Triad(const Triad& car)
{
    first = car.first;
    second = car.second;
    third = car.third;
}
//������������
void Triad::Set_second(int C)
{
    second = C;
}
void Triad::Set_first(int M)
{
    first = M;
}

void Triad::Set_third(int P)
{
    third = P;
}
void Triad::Plus_first()
{
    first = first + 1;
}
void Triad::Plus_second()
{
    second = second + 1;
}
void Triad::Plus_third()
{
    third = third + 1;
}
//���������� �������� ������������
Triad& Triad::operator=(const Triad& c)
{
    if (&c == this)return *this;
    first = c.first;
    third = c.third;
    second = c.second;
    return *this;
}
//���������� ������� ��� �����
istream& operator>>(istream& in, Triad& c)
{
    cout << "\nfirst:"; in >> c.first;
    cout << "\nsecond:";in >> c.second;
    cout << "\nthird:";in >> c.third;
    return in;
}
//���������� ������� ��� ������
ostream& operator<<(ostream& out, const Triad& c)
{
    out << "\nFIRST : " << c.first;
    out << "\nSECOND : " << c.second;
    out << "\nTHIRD : " << c.third;
    out << "\n";
    return out;
}
void Triad::Show()
{
    cout << "\nFIRST : " << first;
    cout << "\nSECOND : " << second;
    cout << "\nTHIRD : " << third;
    cout << "\n";
}


