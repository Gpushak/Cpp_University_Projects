#pragma once
#include <iostream>
#include <string>
using namespace std;
class car
{
    //��������
    string brand;
    string name;
    int price;
public:
    car();//����������� ��� ����������
    car(string, string, int);//����������� � �����������
    car(const car&);//����������� �����������
    ~car();//����������
    string get_brand();//��������
    void set_brand(string);//�����������
    string get_name();//��������
    void set_name(string); //�����������
    int get_price();//��������
    void set_price(int); //�����������
    void show();//�������� ���������
};
