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
        cout << "������� ����� �������:\n1. ������� ����\n2. ������ �����\n3. ������� ��� ������ ������ ��������� ��������\n4. ��������� ��� ������ � �������� ��������� � ��� ����\n5. �������� K ������� ����� �������� � �������� �������\n6. �����\n";
        cin >> choose;
        system("cls");
    } while (choose != 6);
    
}
