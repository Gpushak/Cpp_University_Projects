#pragma once
#include "Triad.h"

//����� Lorry ����������� �� ������ Car
class Time :
    public Triad
{
public:
    Time(void);//����������� ��� ����������
public:
    ~Time(void);//����������
    Time(int, int, int);//����������� � �����������
    Time(const Time&);//����������� �����������

    int Get_hours() { return hours; }
    int Get_minutes() { return minutes; }
    int Get_seconds() { return seconds; }
    //������������
    void Set_hours(int);
    void Set_minutes(int);
    void Set_seconds(int);
    void Plus_hours();
    void Plus_minutes();
    void Plus_seconds();
    void Increas_Time(int, int);

    Time& operator=(const Time&);//�������� ������������
    friend istream& operator>>(istream& in, Time& l);//�������� �����
    friend ostream& operator<<(ostream& out, const Time& l); //�������� ������
protected:
    int hours;
    int minutes;
    int seconds;

};
