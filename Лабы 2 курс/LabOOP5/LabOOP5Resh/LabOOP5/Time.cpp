#include "Time.h"
//конструктор без параметров
Time::Time(void)
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}
//деструктор
Time::~Time(void)
{
}
//конструктор с параметрами
Time::Time(int M, int C, int P)
{
    hours = M;
    minutes = C;
    seconds = P;
}
//конструктор копирования
Time::Time(const Time& car)
{
    hours = car.hours;
    minutes = car.minutes;
    seconds = car.seconds;
}
//модификаторы

void Time::Set_hours(int M)
{
    hours = M;
}
void Time::Set_minutes(int C)
{
    minutes = C;
}
void Time::Set_seconds(int P)
{
    seconds = P;
}
void Time::Plus_hours()
{
    hours = hours + 1;
}
void Time::Plus_minutes()
{
    minutes = minutes + 1;
}
void Time::Plus_seconds()
{
    seconds = seconds + 1;
}
void Time::Increas_Time(int Min, int Sec) {
    minutes = minutes + Min;
    seconds = seconds + Sec;
}

//перегрузка операции присваивания
Time& Time::operator=(const Time& c)
{
    if (&c == this)return *this;
    hours = c.hours;
    minutes = c.minutes;
    seconds = c.seconds;

    return *this;
}
//глобальная функция для ввода
istream& operator>>(istream& in, Time& c)
{
    cout << "\nhours:"; in >> c.hours;
    cout << "\nminutes:";in >> c.minutes;
    cout << "\nseconds:";in >> c.seconds;

    return in;
}
//глобальная функция для вывода
ostream& operator<<(ostream& out, const Time& c)
{
    out << "\nHOURS : " << c.hours;
    out << "\nMINUTES : " << c.minutes;
    out << "\nSECONDS : " << c.seconds;
    out << "\n";
    return out;
}
void Time::Show()
{
    cout << "\nHOURS : " << hours;
    cout << "\nMINUTES : " << minutes;
    cout << "\nSECONDS : " << seconds;
    cout << "\n";
}


