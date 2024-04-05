#pragma once
#include "Triad.h"

//класс Lorry наследуется от класса Car
class Time :
    public Triad
{
public:
    Time(void);//конструктор без параметров
public:
    ~Time(void);//деструктор
    Time(int, int, int);//конструктор с параметрами
    Time(const Time&);//конструктор копирования

    int Get_hours() { return hours; }
    int Get_minutes() { return minutes; }
    int Get_seconds() { return seconds; }
    //модификаторы
    void Set_hours(int);
    void Set_minutes(int);
    void Set_seconds(int);
    void Plus_hours();
    void Plus_minutes();
    void Plus_seconds();
    void Increas_Time(int, int);

    Time& operator=(const Time&);//операция присваивания
    friend istream& operator>>(istream& in, Time& l);//операция ввода
    friend ostream& operator<<(ostream& out, const Time& l); //операция вывода
protected:
    int hours;
    int minutes;
    int seconds;

};
