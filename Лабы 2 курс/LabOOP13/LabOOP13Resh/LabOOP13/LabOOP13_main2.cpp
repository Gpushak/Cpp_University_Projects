#include "C:\Users\igleb\OneDrive\Documents\GitHub\Cpp_University_Projects\Лабы 2 курс\LabOOP13\LabOOP13Resh\LabOOP13\Money.h"
#include <queue>
#include <algorithm>
#include <iostream>

typedef std::queue<Money> TQueue;

Money s;
//формирование очереди
TQueue make_queue(int n)
{
    Money a;
    TQueue q;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        q.push(a);
    }
    return q;
}

//печать очереди
void print_queue(TQueue q)
{
    while (!q.empty())
    {
        std::cout << q.front() << std::endl;
        q.pop();
    }
    std::cout << std::endl;
}

Money srednee(TQueue q)
{
    Money s = q.front();
    int n = 1;
    q.pop();
    while (!q.empty())
    {
        s = s + q.front();
        q.pop();
        n++;
    }
    return s / n;
}



struct Equal_s
{
    bool operator()(Money t)
    {
        return t == s;
    }
};

int main()
{
    int n;
    Money s;
    TQueue q;
    std::cout << "N?";
    std::cin >> n;

    q = make_queue(n);
    print_queue(q);

    //1.3 -----------Найти сред. ар. и добавить в начало------------

    s = srednee(q);
    std::cout << "sred=" << s << std::endl;
    q.push(s);
    print_queue(q);

    //1.4 -----------Найти элемент с заданным ключом и удалить------------

    std::cout << "POISK" << std::endl;
    std::cin >> s;

    bool found = false;
    while (!q.empty())
    {
        if (q.front() == s)
        {
            q.pop();
            found = true;
            break;
        }
        q.push(q.front());
        q.pop();
    }
    if (!found)
        std::cout << "Not such element!" << std::endl;
    print_queue(q);

    //1.5 -----------Из каждого элемента вычесть минимальный элемент контейнера------------
    TQueue t;
    Money minVal = q.front();
    q.pop();
    
    for (int i = 0; i < q.size()+1; i++)
    {
        if (q.front() < minVal)
            minVal = q.front();
    }

    
    cout << "min= "<<minVal<< endl;
    for(int i = 0; i < q.size()+1; i++)
    {
        q.front() = q.front() - minVal;
    }
    print_queue(q);
    print_queue(t);
    return 0;
}
