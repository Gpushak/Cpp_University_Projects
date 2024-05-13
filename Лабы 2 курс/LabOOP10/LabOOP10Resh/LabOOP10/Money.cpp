#include "Money.h"
#include <iostream>
using namespace std;
//���������� �������� ������������
Money& Money::operator=(const Money& t)
{
    //�������� �� ����������������

    rub = t.rub;
    kop = t.kop;
    return *this;
}
bool Money::operator>(const Money& t)
{
    if (rub > t.rub) {
        return 1;
    }
    return 0;
}

bool Money::operator<(const Money& t)
{
    if (rub < t.rub) {
        return 1;
    }
    return 0;
}
//���������� ���������� �������� ���������
Money& Money::operator++()
{
    int temp = rub * 100 + kop;
    temp++;
    rub = temp / 100;
    kop = temp % 100;
    return *this;
}
//���������� ����������� �������� ���������
Money Money::operator ++(int)
{
    int temp = rub * 100 + kop;
    temp++;
    Money t(rub, kop);
    rub = temp / 100;
    kop = temp % 100;
    return t;
}
Money Money::operator--(int) {
    Money t(rub/2, kop/2);
    return t;
}
//���������� �������� �������� ��������
Money Money::operator+(const Money& t)
{
    int temp1 = rub * 100 + kop;
    int temp2 = t.rub * 100 + t.kop;
    Money p;
    p.rub = (temp1 + temp2) / 100;
    p.kop = (temp1 + temp2) % 100;
    return p;
}
//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Money& t)
{
    cout << "rubles? "; in >> t.rub;
    cout << "kopecks? "; in >> t.kop;
    return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Money& t)
{

   out << t.rub << "," << t.kop;
   return out;
}

fstream& operator>>(fstream& fin, Money& p)
{
    fin >> p.rub;
    fin >> p.kop;
    return fin;
}
fstream& operator<<(fstream& fout, const Money& p)
{
    fout << p.rub << "\n" << p.kop << "\n";
    return fout;
}

