#include <iostream>
#include <string>
using namespace std;

void separateAndPrintWords(string s) {
    string digits; // Слова, содержащие только цифры
    string letters; // Слова, содержащие только буквы
    string mixed; // Слова, содержащие и буквы и цифры

    int start = 0;
    int end = 1;

    // Перебираем символы строки
    while (end != string::npos) {
        // Находим начало следующего слова
        start = s.find_first_not_of(" ", end);

        // Если достигнут конец строки, выходим из цикла
        if (start == string::npos)
            break;

        // Находим конец текущего слова
        end = s.find_first_of(".", start);

        // Извлекаем слово из строки
        string word = s.substr(start, end - start);

        // Проверяем, содержит ли слово только цифры
        bool hasDigit = true;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!isdigit(c)) {
                hasDigit = false;
                break;
            }
        }

        // Проверяем, содержит ли слово только буквы
        bool hasLetter = true;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!isalpha(c)) {
                hasLetter = false;
                break;
            }
        }

        // Определяем категорию слова и добавляем его в соответствующую строку
        if (hasDigit && !hasLetter) {
            digits += word + " ";
        }
        else if (!hasDigit && hasLetter) {
            letters += word + " ";
        }
        else {
            mixed += word + " ";
        }
    }

    // Выводим слова в заданном порядке
    cout << digits << letters << mixed << "." << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    string s;
    cout << "Введите строку: ";
    getline(cin, s); // Используем getline для ввода строки

    //Пример показательной строки:  Code Life01 01011010 SetUrMind

    separateAndPrintWords(s);

    return 0;
}
