#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Шаг 1: Ввод размеров массива
    int rows, cols;
    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;

    // Шаг 2: Создание двумерного массива с помощью операции new
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    // Шаг 3: Заполнение массива случайными числами
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100; // Пример заполнения случайными числами от 0 до 99
        }
    }

    // Шаг 4: Добавление строки и столбца с заданными номерами
    int newRow = 2; // Пример номера строки для добавления
    int newCol = 3; // Пример номера столбца для добавления

    // Создание нового массива-результата с дополнительной строкой
    int** newArray = new int* [rows + 1];
    for (int i = 0; i < rows + 1; ++i) {
        newArray[i] = new int[cols];
    }

    // Копирование старых строк до добавляемой строки
    for (int i = 0; i < newRow; ++i) {
        for (int j = 0; j < cols; ++j) {
            newArray[i][j] = array[i][j];
        }
    }

    // Добавление новой строки
    for (int j = 0; j < cols; ++j) {
        newArray[newRow][j] = rand() % 100; // Пример заполнения случайным числом
    }

    // Копирование оставшихся строк
    for (int i = newRow; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newArray[i + 1][j] = array[i][j];
        }
    }

    // Добавление нового столбца
    for (int i = 0; i < rows + 1; ++i) {
        newArray[i][newCol] = rand() % 100; // Пример заполнения случайным числом
    }

    // Шаг 5: Вывод массива-результата
    cout << "Массив-результат:" << endl;
    for (int i = 0; i < rows + 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << newArray[i][j] << " ";
        }
        cout << endl;
    }

    // Шаг 6: Освобождение динамической памяти
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    for (int i = 0; i < rows + 1; ++i) {
        delete[] newArray[i];
    }
    delete[] newArray;

    return 0;
}
