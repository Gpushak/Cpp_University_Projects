#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Tree.h"
using namespace std;
class Student :
    public Person
{
public:
    Student(void);
public:
    ~Student(void);
    void Show();
    void Input();
    Student(string, int, float, Tree);
    Student(const Student&);
    float Get_rating() { return rating; }
    Tree Get_group() { return group; }
    void Set_rating(float);
    Student& operator=(const Student&);
protected:
    float rating;
    Tree group;
};
