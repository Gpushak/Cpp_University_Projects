#include <iostream>
#include "Triad.h"
#include "Time.h"
#include "Object.h"
#include "Vector.h"
using namespace std;
// глобальные функции
void main()
{
    Vector v(5);//вектор из 5 элементов
    Triad a;//объект класса Car
    cin >> a;
    Time b;// объект класса Lorry
    cin >> b;
    Object* p = &a;//ставим указатель на объект класса Car
    v.Add(p);//добавляем объект в вектор
    p = &b;//ставим указатель на объект класса Lorry
    v.Add(p); //добавляем объект в вектор
    cout << v;//вывод вектора
}
