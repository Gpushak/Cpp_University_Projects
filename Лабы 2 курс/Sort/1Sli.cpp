#include <iostream>
#include "CppGlAdu23.h"

using namespace std;

// ������� ��� ������� ���� ����������� arr[l..m] � arr[m+1..r] � ���� ��������������� ������
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // ������� ��������� �������
    int* L = new int[n1];
    int* R = new int[n2];
    // �������� ������ �� ��������� ������� L[] � R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // ������� ��������� �������� ������� � arr[l..r]
    int i = 0; // ������ ������� ����������
    int j = 0; // ������ ������� ����������
    int k = l; // ������ �������

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ����������� ���������� ��������� L[], ���� ��� ��������
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ����������� ���������� ��������� R[], ���� ��� ��������
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// ������� ���������� ��������
void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    setlocale(LC_ALL, "rus");
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "�������� ������: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "��������������� ������: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
