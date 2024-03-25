#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//функция для возврата объекта как результата
car make_car()
{
    string s;
    string i;
    int d;
    cout << "Введите марку: ";
    cin >> s;
    cout << "Введите модель: ";
    cin >> i;
    cout << "Введите цену: ";
    cin >> d;
    car t(s, i, d);
    return t;
}
//функция для передачи объекта как параметра
void print_car(car t)
{
    t.show();
}
void main()
{
    setlocale(LC_ALL, "rus");
    //конструктор без параметров
    car t1;
    t1.show();
    //коструктор с параметрами
    car t2("Lada", "2101", 100000);
    t2.show();
    //конструктор копирования
    car t3 = t2;
    t3.set_brand("Dodge");
    t3.set_name("Charger");
    t3.set_price(4000000);
    //конструктор копирования
    print_car(t3);
    //конструктор копирования
    t1 = make_car();
    t1.show();
}
