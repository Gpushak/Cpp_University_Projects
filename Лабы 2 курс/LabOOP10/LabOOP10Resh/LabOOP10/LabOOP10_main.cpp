#include "Money.h"
#include "file_work.h"
#include <fstream> 
#include <iostream>
#include <functional>
using namespace std;

void main()
{

    system("chcp 1251 > NULL");
    int choose = 6;
    function<int()> f[5] = { make_file, print_file, del_file, change_file, add_file };
    do {
        if (choose != 6) {
            check_k(f[choose - 1]());
        }
        cout << "Введите номер команды:\n1. Создать файл\n2. Печать файла\n3. Удалить все записи больше заданного значения\n4. Уменьшить все записи с заданным значением в два раза\n5. Добавить K записей после элимента с заданным номером\n6. Выход\n";
        cin >> choose;
        system("cls");
    } while (choose != 6);
    
}
