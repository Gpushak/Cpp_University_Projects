#include <iostream>
using namespace std;
class Money
{
    long rub;
    int kop;
public:
    Money() { rub = 0;kop = 0; };
    Money(long m, int s) { rub = m;kop = s; }
    Money(const Money& t) { rub = t.rub;kop = t.kop; }
    ~Money() {};
    int get_min() { return rub; }
    int get_sec() { return kop; }
    void set_min(long m) { rub = m; }
    void set_sec(int s) { kop = s; }
    //������������� ��������
    Money& operator=(const Money&);
    bool operator>(const Money&);
    bool operator<(const Money&);
    Money& operator++();
    Money operator++(int);//����������� ��������
    Money operator+(const Money&);
    //���������� ������� �����-������
    friend istream& operator>>(istream& in, Money& t);
    friend ostream& operator<<(ostream& out, const Money& t);
};
