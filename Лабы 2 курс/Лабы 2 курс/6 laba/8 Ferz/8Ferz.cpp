#include<iostream>
using namespace std;

const int N = 8; // Размер доски
extern int  cnt = 0;

// Функция для вывода шахматной доски
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cnt++;
}

// Функция для проверки, можно ли разместить ферзя на данной позиции
bool isSafe(int board[N][N], int row, int col) {
    // Проверка вертикали вверх
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Проверка левой диагонали вверх
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Проверка правой диагонали вверх
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Рекурсивная функция для решения задачи о восьми ферзях
bool solveNQueens(int board[N][N], int row) {
    if (row == N) {
        // Все ферзи размещены, печать доски
        printBoard(board);
        return true; // Можно возвращать false, чтобы найти все решения
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1; // Размещаем ферзя

            // Рекурсивный вызов для следующей строки
            if (solveNQueens(board, row + 1)) return true;

            board[row][i] = 0; // Возвращаемся и отменяем размещение, если не нашли решение
        }
    }

    return false;
}

int main() {
    setlocale(LC_ALL, "rus");

    int board[N][N] = { 0 }; // Инициализация доски

    if (!solveNQueens(board, 0)) {
        if (cnt != 0) cout << "Найденное кол-во решений: " << cnt << endl;
        else cout << "Решение не найдено." << endl;
    }
    return 0;
}
