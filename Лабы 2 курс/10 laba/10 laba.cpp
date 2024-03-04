#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // ��� 1: ���� �������� �������
    int rows, cols;
    cout << "������� ���������� ����� � ��������: ";
    cin >> rows >> cols;

    // ��� 2: �������� ���������� ������� � ������� �������� new
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    // ��� 3: ���������� ������� ���������� �������
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100; // ������ ���������� ���������� ������� �� 0 �� 99
        }
    }

    // ��� 4: ���������� ������ � ������� � ��������� ��������
    int newRow = 2; // ������ ������ ������ ��� ����������
    int newCol = 3; // ������ ������ ������� ��� ����������

    // �������� ������ �������-���������� � �������������� �������
    int** newArray = new int* [rows + 1];
    for (int i = 0; i < rows + 1; ++i) {
        newArray[i] = new int[cols];
    }

    // ����������� ������ ����� �� ����������� ������
    for (int i = 0; i < newRow; ++i) {
        for (int j = 0; j < cols; ++j) {
            newArray[i][j] = array[i][j];
        }
    }

    // ���������� ����� ������
    for (int j = 0; j < cols; ++j) {
        newArray[newRow][j] = rand() % 100; // ������ ���������� ��������� ������
    }

    // ����������� ���������� �����
    for (int i = newRow; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newArray[i + 1][j] = array[i][j];
        }
    }

    // ���������� ������ �������
    for (int i = 0; i < rows + 1; ++i) {
        newArray[i][newCol] = rand() % 100; // ������ ���������� ��������� ������
    }

    // ��� 5: ����� �������-����������
    cout << "������-���������:" << endl;
    for (int i = 0; i < rows + 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << newArray[i][j] << " ";
        }
        cout << endl;
    }

    // ��� 6: ������������ ������������ ������
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
