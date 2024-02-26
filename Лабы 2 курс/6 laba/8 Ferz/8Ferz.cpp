#include<iostream>
using namespace std;

const int N = 8; // ������ �����
extern int  cnt = 0;

// ������� ��� ������ ��������� �����
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

// ������� ��� ��������, ����� �� ���������� ����� �� ������ �������
bool isSafe(int board[N][N], int row, int col) {
    // �������� ��������� �����
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // �������� ����� ��������� �����
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // �������� ������ ��������� �����
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// ����������� ������� ��� ������� ������ � ������ ������
bool solveNQueens(int board[N][N], int row) {
    if (row == N) {
        // ��� ����� ���������, ������ �����
        printBoard(board);
        return true; // ����� ���������� false, ����� ����� ��� �������
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1; // ��������� �����

            // ����������� ����� ��� ��������� ������
            if (solveNQueens(board, row + 1)) return true;

            board[row][i] = 0; // ������������ � �������� ����������, ���� �� ����� �������
        }
    }

    return false;
}

int main() {
    setlocale(LC_ALL, "rus");

    int board[N][N] = { 0 }; // ������������� �����

    if (!solveNQueens(board, 0)) {
        if (cnt != 0) cout << "��������� ���-�� �������: " << cnt << endl;
        else cout << "������� �� �������." << endl;
    }
    return 0;
}
