#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Vector
{
public:
    Vector(int);//����������� � �����������
public:
    ~Vector(void);//����������
    void Add();//���������� �������� � ������
    void Del();
    void Show();
    int operator()();//������ �������

protected:
    Object** beg;//��������� �� ������ ������� �������
    int size;//������
    int cur;//������� �������
};
