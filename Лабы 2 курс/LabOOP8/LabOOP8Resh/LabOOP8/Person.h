#pragma once
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Person :
    public Object
{
public:
    Person(void);//конструктор без параметров
    virtual ~Person(void);//деструктор
    void Show();//функция для просмотра атрибутов класса с помощью указателя
    void Input();//функция для ввода значений атрибутов
    Person(string, int);//конструктор с параметрами
    Person(const Person&);//конструктор копирования
    //селекторы
    string Get_name() { return name; }
    int Get_age() { return age; }
    //модификаторы
    void Set_name(string);
    void Set_age(int);
    Person& operator=(const Person&);//перегрузка операции присваивания
protected:
    string name;
    int age;
};

