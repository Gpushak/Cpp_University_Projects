#include "Money.h"
#include <iostream>
using namespace std;
//перегрузка операции присваивания
Money Money::operator/(const Money& t)
{
    int temp1 = rub * 60 + kop;
    int temp2 = t.rub * 60 + t.kop;
    Money p;
    p.rub = (temp1 / temp2) / 60;
    p.kop = (temp1 / temp2) % 60;
    return p;
}
Money Money::operator/(const int& t)
{
    int temp1 = rub * 60 + kop;

    Money p;
    p.rub = (temp1 / t) / 60;
    p.kop = (temp1 / t) % 60;
    return p;
}

Money& Money::operator=(const Money& t)
{
    //проверка на самоприсваивание

    rub = t.rub;
    kop = t.kop;
    return *this;
}
bool Money::operator==(const Money& t)
{
    if ((rub == t.rub) and (kop == t.kop)) {
        return 1;
    }
    return 0;
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
//перегрузка префиксной операции инкремент
Money& Money::operator++()
{
    int temp = rub * 100 + kop;
    temp++;
    rub = temp / 100;
    kop = temp % 100;
    return *this;
}
//перегрузка постфиксной операции инкремент
Money Money::operator ++(int)
{
    int temp = rub * 100 + kop;
    temp++;
    Money t(rub, kop);
    rub = temp / 100;
    kop = temp % 100;
    return t;
}
//перегрузка бинарной операции сложения
Money Money::operator+(const Money& t)
{
    int temp1 = rub * 100 + kop;
    int temp2 = t.rub * 100 + t.kop;
    Money p;
    p.rub = (temp1 + temp2) / 100;
    p.kop = (temp1 + temp2) % 100;
    return p;
}
Money Money::operator-(const Money& t)
{
    Money p;
    p.rub = rub - t.rub;
    p.kop = kop - t.kop;
    return p;
}
//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
    cout << "rubles? "; in >> t.rub;
    cout << "kopecks? "; in >> t.kop;
    return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{

    return (out << t.rub << "," << t.kop);
}
