#include <iostream>
#include "Triad.h"
#include "Time.h"
using namespace std;
// глобальные функции
void main()
{
    //работа с классом Car
    Triad a;
    cin >> a;
    cout << a;
    Triad b(3, 4, 115);
    b.Plus_second();
    cout << b;
    a = b;
    cout << a;
    //работа с классом Lorry
    Time c;
    cin >> c;
    c.Increas_Time(23, 12);
    cout << c;
}
