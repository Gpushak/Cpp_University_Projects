#include <iostream>
#pragma once
#include "fraction.h"
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


