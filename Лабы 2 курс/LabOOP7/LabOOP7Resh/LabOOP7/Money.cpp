#include "Money.h"
Money::Money(void)
{
    rub = kop = 0;
}


Money::Money(long M, int S)
{
    rub = M;kop = S;
}
Money::Money(const Money& t)
{
    rub = t.rub;
    kop = t.kop;
}
Money& Money::operator =(const Money& t)
{
    rub = t.rub;
    kop = t.kop;
    return*this;
}
Money Money::operator+(Money k)
{
    int t = rub * 100 + kop;
    int kt = k.rub * 100 + k.kop;
    t += kt;
    Money temp(t / 100, t % 100);
    return temp;
}
ostream& operator<<(ostream& out, const Money& t)
{
    out << t.rub << " : " << t.kop;
    return out;
}
istream& operator>>(istream& in, Money& t)
{
    cout << "\nrub?"; in >> t.rub;
    cout << "\nkop?";in >> t.kop;
    return in;
}