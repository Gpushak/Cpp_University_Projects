#include <iostream>
#include "List.h"
using namespace std;

//операция присваивания
List& List::operator=(const List& a)
{
    if (this == &a)return *this;
    size = a.size;
    if (data != 0) delete[]data;
    data = new int[size];
    for (int i = 0;i < size;i++)
        data[i] = a.data[i];
    beg = a.beg;
    end = a.end;
    return *this;

}

//операции для ввода-выода
ostream& operator<<(ostream& out, const List& a)
{
    for (int i = 0;i < a.size;++i)
        out << a.data[i] << " ";
    return out;
}

istream& operator>>(istream& in, List& a)
{
    for (int i = 0;i < a.size;++i)
        in >> a.data[i];
    return in;
}
