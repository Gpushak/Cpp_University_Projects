#include <iostream>
#pragma once
#include "C:\Users\igleb\OneDrive\Documents\GitHub\Cpp_University_Projects\Лабы 2 курс\LabOOP1\LabOOP1\LabOOP1\fraction.h"
using namespace std;

void fraction::Init(double F, int S) {
	salary = F;
	days = S;
}

void fraction::Read() {
	cout << "salary? ";
	cin >> salary;

	cout << "days worcked? ";
	cin >> days;

	cout << endl;
}

void fraction::Show() {
	cout << "Salary = " << salary << endl;
	cout << "Days worcked = " << days << endl;
	cout << endl;
}

double fraction::Summa() {
	return (salary / 31) * days;
}


