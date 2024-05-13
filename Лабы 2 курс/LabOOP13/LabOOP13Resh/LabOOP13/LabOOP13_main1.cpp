#include "Money.h"
#include "vector"
#include <algorithm>
#include <iostream>
using namespace std;

typedef vector<Money> TVector;
//������������ �������
TVector make_vector(int n)
{
    Money a;
    TVector v;
    for (int i = 0;i < n;i++)
    {
        cin >> a;
        v.push_back(a);
    }
    return v;
}
//������ �������
void print_vector(TVector v)
{
    for (int i = 0;i < v.size();i++)
        cout << v[i] << endl;
    cout << endl;
}

typedef vector<Money> TVector;
Money s;

Money srednee(TVector v)
{
    Money s = v[0];
    //������� �������
    for (int i = 1;i < v.size();i++)
        s = s + v[i];
    int n = v.size();//���������� ��������� � �������
    return s / n;
}

struct Equal_s
{
    bool operator()(Money t)
    {
        return t == s;
    }
};

void main()
{
    int n;
    TVector::iterator i;
    cout << "N?";
    cin >> n;
    TVector v;
    v = make_vector(n);
    print_vector(v);

    //1.3 -----------����� ����. ��. � �������� � ������------------

    s = srednee(v);
    cout << "sred=" << s << endl;
    v.insert(v.begin(), s);
    print_vector(v);

    //1.4 -----------����� ������� � �������� ������ � �������------------

    cout << "POISK" << endl;
    cin >> s;
    i = find_if(v.begin(), v.end(), Equal_s());
    if (i != v.end())
        v.erase(i);
    else
        cout << "Not such element!" << endl;
    print_vector(v);

    //1.5 -----------�� ������� �������� ������� ����������� ������� ����������------------
    i = min_element(v.begin(), v.end());
    cout << "min= " << *i<< endl;
    for (int j = 0;j < v.size();j++)
        v[j] = v[j] - *(i);
    print_vector(v);
}
