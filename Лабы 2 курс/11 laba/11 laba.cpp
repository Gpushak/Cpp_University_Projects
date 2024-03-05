#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node2 {
    string key;
    Node2* prev = nullptr;
    Node2* next = nullptr;
};

struct Node1 {
    string key;
    Node1* next = nullptr;
};

// Функция для создания пустого списка
Node2* createList() {
    return nullptr; // Возвращаем указатель на NULL, так как список пустой
}

// Функция для печати списка
void printList(Node2* head) {
    if (head == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }
    Node2* current = head;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

// Функция для добавления элемента в конец списка
void appendToList(Node2*& head, const string& newKey) {
    Node2* newNode = new Node2;
    newNode->key = newKey;
    newNode->next = nullptr;
    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }
    Node2* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Функция для удаления элемента с заданным ключом
void deleteNode(Node2*& head, const string& keyToDelete) {
    if (head == nullptr) {
        return;
    }
    Node2* current = head;
    while (current != nullptr) {
        if (current->key == keyToDelete) {
            if (current->prev == nullptr) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            }
            else {
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

// Функция для записи списка в файл
void writeListToFile(Node2* head, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи" << endl;
        return;
    }
    Node2* current = head;
    while (current != nullptr) {
        file << current->key << endl;
        current = current->next;
    }
    file.close();
}

// Функция для уничтожения списка
void destroyList(Node2*& head) {
    while (head != nullptr) {
        Node2* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    Node2* head = createList(); // Создаем пустой список
    printList(head); // Печатаем пустой список

    cout << "|" << endl << "|" << endl;

    // Добавляем элементы в список
    appendToList(head, "1");
    appendToList(head, "2");
    appendToList(head, "3");
    appendToList(head, "4");
    appendToList(head, "5");
    printList(head);

    cout << "|" << endl << "|" << endl;

    cout << "Введите элемент для удаления: ";
    string line;
    getline(cin, line);

    // Удаляем элемент из списка
    deleteNode(head, line);
    cout << "|" << endl << "|" << endl;
    printList(head);

    cout << "|" << endl << "|" << endl;

    cout << "Введите элемент для добавления: ";
    string line2;
    getline(cin, line2);
    cout << "|" << endl << "|" << endl;


    //Добавляем элемент в список
    appendToList(head, line2);
    printList(head);

    cout << "|" << endl << "|" << endl;
    // Записываем список в файл
    writeListToFile(head, "список.txt");

    // Уничтожаем список
    destroyList(head);
    cout << "Список уничтожен" << endl;
    printList(head); // Печатаем пустой список

    return 0;
}
