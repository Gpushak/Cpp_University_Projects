#include <iostream>
#include <cstdarg>
using namespace std;
const int N = 30;

//Функция НОД
int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int sum(int n, ...) {
    va_list n1;

    //Переменные для итоговых числителя/знаменателя
    unsigned int reschis = 0; 
    unsigned int resznam = 1;

    va_start(n1, n);

    //Массив для чисел в дробях
    int drobi[N];
    for (int i = 0; i < n * 2; i++) {
        drobi[i] = va_arg(n1, int);
    }
    va_end(n1);

    //Приведение к общему знаменателю
    for (int i = 0; i < n * 2; i = i + 1) {
        if (i % 2 != 0) {
            resznam = resznam * drobi[i];
        }
    }

    //Преобразование числителя
    for (int i = 0; i < n * 2 - 1; i++) {
        if (i % 2 == 0) {
            drobi[i] = resznam / drobi[i + 1];
            reschis = reschis + drobi[i];
        }
    }

    //Преобразование всей дроби использую НОД
    int nod1 = nod(reschis, resznam);
    reschis = reschis / nod1;
    resznam = resznam / nod1;

    cout << "Результат суммы " << n << " дробей: " << reschis << "/" << resznam << endl;
    return 0;
}

int main() {
    setlocale(LC_ALL, "rus");

    sum(5, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6);
    sum(10, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11);
    sum(12, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13);

    return 0;
}