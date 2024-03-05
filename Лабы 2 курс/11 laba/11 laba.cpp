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

// ������� ��� �������� ������� ������
Node2* createList() {
    return nullptr; // ���������� ��������� �� NULL, ��� ��� ������ ������
}

// ������� ��� ������ ������
void printList(Node2* head) {
    if (head == nullptr) {
        cout << "������ ����" << endl;
        return;
    }
    Node2* current = head;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

// ������� ��� ���������� �������� � ����� ������
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

// ������� ��� �������� �������� � �������� ������
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

// ������� ��� ������ ������ � ����
void writeListToFile(Node2* head, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "������ �������� ����� ��� ������" << endl;
        return;
    }
    Node2* current = head;
    while (current != nullptr) {
        file << current->key << endl;
        current = current->next;
    }
    file.close();
}

// ������� ��� ����������� ������
void destroyList(Node2*& head) {
    while (head != nullptr) {
        Node2* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    Node2* head = createList(); // ������� ������ ������
    printList(head); // �������� ������ ������

    cout << "|" << endl << "|" << endl;

    // ��������� �������� � ������
    appendToList(head, "1");
    appendToList(head, "2");
    appendToList(head, "3");
    appendToList(head, "4");
    appendToList(head, "5");
    printList(head);

    cout << "|" << endl << "|" << endl;

    cout << "������� ������� ��� ��������: ";
    string line;
    getline(cin, line);

    // ������� ������� �� ������
    deleteNode(head, line);
    cout << "|" << endl << "|" << endl;
    printList(head);

    cout << "|" << endl << "|" << endl;

    cout << "������� ������� ��� ����������: ";
    string line2;
    getline(cin, line2);
    cout << "|" << endl << "|" << endl;


    //��������� ������� � ������
    appendToList(head, line2);
    printList(head);

    cout << "|" << endl << "|" << endl;
    // ���������� ������ � ����
    writeListToFile(head, "������.txt");

    // ���������� ������
    destroyList(head);
    cout << "������ ���������" << endl;
    printList(head); // �������� ������ ������

    return 0;
}
