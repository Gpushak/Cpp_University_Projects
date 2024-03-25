#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор без параметров
car::car()
{
    brand = "";
    name = "";
    price = 0;
    cout << "Конструктор без параметров для объекта " << this << endl;
}
//конструктор с параметрами
car::car(string N, string B, int S)
{
    brand = N;
    name = B;
    price = S;
    cout << "Конструктор с параметрами для объекта " << this << endl;
}
//конструктор копирования
car::car(const car& t)
{
    brand = t.brand;
    name = t.name;
    price = t.price;
    cout << "Конструктор копирования для объекта " << this << endl;
}
//деструктор
car::~car()
{
    cout << "Деструктор для объектам " << this << endl;
}
//селекторы
string car::get_brand()
{
    return brand;
}
string car::get_name()
{
    return name;
}
int car::get_price()
{
    return price;
}
//модификаторы
void car::set_brand(string N)
{
    brand = N;
}
void car::set_name(string B)
{
    name = B;
}
void car::set_price(int S)
{
    price = S;
}
//метод для просмотра атрибутов
void car::show()
{
    cout << "Марка :" << brand << endl;
    cout << "Модель :" << name << endl;
    cout << "Цена :" << price << endl;
}
