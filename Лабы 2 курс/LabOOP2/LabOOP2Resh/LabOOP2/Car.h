#pragma once
#include <iostream>
#include <string>
using namespace std;
class car
{
    //атрибуты
    string brand;
    string name;
    int price;
public:
    car();//конструктор без параметров
    car(string, string, int);//конструктор с параметрами
    car(const car&);//конструктор копирования
    ~car();//деструктор
    string get_brand();//селектор
    void set_brand(string);//модификатор
    string get_name();//селектор
    void set_name(string); //модификатор
    int get_price();//селектор
    void set_price(int); //модификатор
    void show();//просмотр атрибутов
};
