#include "Money.h"
#include <map>
#include <algorithm>
#include <iostream>

typedef std::map<int, Money> TMap;
Money s;
//формирование словаря
TMap make_map(int n)
{
    Money a;
    TMap m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        m[i] = a;
    }
    return m;
}

//печать словаря
void print_map(TMap m)
{
    for (auto& pair : m)
        std::cout << pair.second << std::endl;
    std::cout << std::endl;
}

Money srednee(TMap m)
{
    Money s = m.begin()->second;
    int n = 1;
    for (auto it = ++m.begin(); it != m.end(); ++it)
    {
        s = s + it->second;
        n++;
    }
    return s / n;
}

struct Equal_s
{
    bool operator()(const std::pair<int, Money>& pair)
    {
        return pair.second == s;
    }
};

int main()
{
    int n;
    TMap::iterator i;
    std::cout << "N?";
    std::cin >> n;

    TMap m;
    m = make_map(n);
    print_map(m);

    //1.3 -----------Найти сред. ар. и добавить в начало------------

    s = srednee(m);
    std::cout << "sred=" << s << std::endl;
    m.insert(m.begin(), std::make_pair(-1, s));
    print_map(m);

    //1.4 -----------Найти элемент с заданным ключом и удалить------------

    std::cout << "POISK" << std::endl;
    std::cin >> s;

    i = std::find_if(m.begin(), m.end(), Equal_s());
    if (i != m.end())
        m.erase(i);
    else
        std::cout << "Not such element!" << std::endl;
    print_map(m);

    //1.5 -----------Из каждого элемента вычесть минимальный элемент контейнера------------
    i = std::min_element(m.begin(), m.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
    std::cout << "min= " << i->second << std::endl;

    for (auto& pair : m)
        pair.second = pair.second - i->second;
    print_map(m);

    return 0;
}
