#include <iostream>
#include <string>
#include "Student.h"
using namespace std;
Student::Student(void) :Person()
{
    rating = 0;
}
Student::~Student(void)
{
}
Student::Student(string M, int C, float R, Tree G) :Person(M, C)
{
    rating = R;
    group = G;
}
Student::Student(const Student& L)
{
    name = L.name;
    age = L.age;
    rating = L.rating;
    group = L.group;
}
void Student::Set_rating(float G)
{
    rating = G;
}
Student& Student::operator=(const Student& l)
{
    if (&l == this)return *this;
    name = l.name;
    age = l.age;
    return *this;
}
void Student::Show()
{
    cout << "\nNAME : " << name;
    cout << "\nAGE : " << age;
    cout << "\nRATING : " << rating;
    cout << "\nGROUP : " << group;
    cout << "\n";
}
void Student::Input()
{
    cout << "\nname:"; cin >> name;
    cout << "\nage:";cin >> age;
    cout << "\nrating : ";cin >> rating;
    cout << "\ngroup : ";
    int a;
    cin >> a;
    group.insert(a);
}

