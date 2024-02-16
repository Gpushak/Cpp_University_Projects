#include <iostream>
#include <string>
using namespace std;

int sortSlov(string s) {
    string digits; // Слова, содержащие только цифры
    string letters; // Слова, содержащие только буквы
    string mixed; // Слова, содержащие и буквы и цифры

    int dig = 0;
    int lat = 0;

    int end = 0;
    int bigend = 0;

    int n = size(s);

    if (n > 255) {
        cout << "Слово слишком большое" << endl;
        return 0;
    }

    while (bigend != 1) {
        dig = 0;
        lat = 0;

        end = s.find(" "); //Находим конец слова, если кончается точкой, то эта итерация будет последней.
        if (end == string::npos) {
            end = s.find(".");
            bigend = 1;
            s.erase(end, 1);
            s.insert(end, " ");
        }

        //Определяем содержит ли слово цифры, буквы
        for (int i = 0; i < end; i++) {
            if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0') {
                dig = 1;
            }
            else lat = 1;
        }

        //Вписываем слово в нужный блок
        for (int i = 0; i < end; i++) {
            if (dig == 1 && lat == 0) digits = digits + s[i];
            else if (dig == 0 && lat == 1) letters = letters + s[i];
            else if (dig == 1 && lat == 1) mixed = mixed + s[i];
        }
        if (dig == 1 && lat == 0) digits = digits + ' ';
        else if (dig == 0 && lat == 1) letters = letters + ' ';
        else if (dig == 1 && lat == 1) mixed = mixed + ' ';
        s.erase(0, end + 1);
    }

    // Выводим слова в заданном порядке
    cout << digits << letters << mixed << "." << s << endl;
    return 1;
}

int main() {
    setlocale(LC_ALL, "rus");
    string s;
    cout << "Введите строку: ";
    getline(cin, s);

    //Пример показательной строки:  Life01 01011010 SetUrMind.
    sortSlov(s);

    return 0;
}