#include <iostream>
#include <string>
#include "Student.h"
#include "Person.h"
#include "Object.h"
#include "Vector.h"
using namespace std;

int main()
{
    Person* a = new Person;//создаем объект класса Car
    a->Input();
    Student* b = new Student; //создаем объект класса Lorry
    b->Input();

    Vector v(10);//Создаем вектор
    v.Add();//добавляем объект в вектор
    v.Add(); //добавляем объект в вектор
    v.Add();
    v.Show();//вывод вектора
    v.Del();//удаление элемента
    cout << "\nVector size=" << v();
    return 0;
}
