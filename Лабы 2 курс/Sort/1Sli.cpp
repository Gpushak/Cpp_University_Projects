#include <iostream>
#include "CppGlAdu23.h"

using namespace std;

// Функция для слияния двух подмассивов arr[l..m] и arr[m+1..r] в один отсортированный массив
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Создаем временные массивы
    int* L = new int[n1];
    int* R = new int[n2];
    // Копируем данные во временные массивы L[] и R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Слияние временных массивов обратно в arr[l..r]
    int i = 0; // Индекс первого подмассива
    int j = 0; // Индекс второго подмассива
    int k = l; // Индекс слияния

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

    // Копирование оставшихся элементов L[], если они остались
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов R[], если они остались
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Функция сортировки слиянием
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

    cout << "Исходный массив: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
