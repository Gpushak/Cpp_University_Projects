#pragma once
#include <iostream>
using namespace std;
class Vector
{
public:
    //конструктор с параметрами: выделяет память под s элементов и заполняет их
    //значением k
    Vector(int s, int k = 0);
    //конструктор с параметрами
    Vector(const Vector& a);
    //деструктор
    ~Vector();
    //оператор присваивания
    Vector& operator=(const Vector& a);
    //операция доступа по индексу
    int& operator[](int index);
    //операция для добавление константы
    Vector operator+(const int k);
    //операция, возвращающая длину вектора
    int operator()();
    //перегруженные операции ввода-вывода
    friend ostream& operator<<(ostream& out, const Vector& a);
    friend istream& operator>>(istream& in, Vector& a);
private:
    int size;//размер вектора
    int* data;//укзатель на динамический массив значений вектора
};
