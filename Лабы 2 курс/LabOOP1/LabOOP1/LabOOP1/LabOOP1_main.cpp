#include <iostream>
#pragma once
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, int S)
{
    fraction t;//создали временную переменную
    t.Init(F, S);//инициализировали поля переменной t с помощью параметров функции
    return t;//вернули значение переменной t
}

int main()
{
    setlocale(LC_ALL, "rus");
    //определение переменных А и В
    fraction A;
    fraction B;
    A.Init(45000, 28);//инициализация переменной А
    A.Show();//вывод значений полей переменной А
    cout << "A.accrued(" << A.salary << "," << A.days << ")=" << A.Summa() << endl << endl;
    B.Read();//ввод полей переменных В

    B.Show();//вывод значений полей переменной В
 
    cout << "B.accrued(" << B.salary << "," << B.days << ")=" << B.Summa() << endl << endl;
    //указатели
    cout << "Результат с использованием указателей" << endl;
    fraction* X = new fraction;//выделение памяти под динамическую переменную
    X->Init(22800, 13);//инициализация
    X->Show();//вывод значений полей
    X->Summa();
    cout << "X.accrued(" << X->salary << "," << X->days << ")=" << X->Summa() << endl << endl;
    //массивы
    cout << "3 Пары значений для стандартных массивов" << endl;
    fraction mas[3];//определение массива
    for (int i = 0;i < 3; i++)
        mas[i].Read();//чтение значений полей
    for (int i = 0;i < 3; i++)
        mas[i].Show(); //вывод значений полей
    for (int i = 0;i < 3; i++)
    {
        mas[i].Summa(); 
        cout << "mas[" << i << "].summa(" << mas[i].salary << "," << mas[i].days << ")=";
        cout << mas[i].Summa() << endl;
    }
    //динамические масивы
    cout << "3 Пары значений для динамических массивов" << endl;
    fraction* p_mas = new fraction[3];//выделение памяти
    for (int i = 0;i < 3; i++)
        p_mas[i].Read();//чтение значений полей
    for (int i = 0;i < 3; i++)
        p_mas[i].Show();//вывод значений полей

    for (int i = 0;i < 3; i++)
    {
        p_mas[i].Summa();
        cout << "p_mas[" << i << "].summa(" << p_mas[i].salary << "," << p_mas[i].days;
        cout << ")=" << p_mas[i].Summa() << endl;
    }
    //вызов функции make_fraction()
    double y; int z;
    cout << "salary? ";
    cin >> y;

    cout << "days worcked? ";
    cin >> z;
    //переменная F формируется с помощью функции make_fraction()
    fraction F = make_fraction(y, z);
    F.Show();

    return 0;
}
