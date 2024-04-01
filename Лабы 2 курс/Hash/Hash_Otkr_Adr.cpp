#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
const int HASH_TABLE_SIZE = 100;

struct Record {
    string fullName;
    string phoneNumber;
    string passportNumber;
};

struct HashEntry {
    Record* record;
    bool deleted; // ���� ��������
};

int hashFunction(const std::string& key) {
    int M = HASH_TABLE_SIZE;
    double hashValue = fmod(key.length(), M);
    return static_cast<int>(hashValue);
}


void insertRecord(HashEntry** table, const Record& newRecord) { //������� 
    int index = hashFunction(newRecord.passportNumber);
    while (table[index] != nullptr && !table[index]->deleted) {
        index = (index + 1) % HASH_TABLE_SIZE; // �������� ������������
    }
    table[index] = new HashEntry{ new Record{newRecord}, false };
}

void deleteRecord(HashEntry** table, const string& key) { //�������� 
    int index = hashFunction(key);
    while (table[index] != nullptr) {
        if (table[index]->record->passportNumber == key) {
            table[index]->deleted = true;
            return;
        }
        index = (index + 1) % HASH_TABLE_SIZE;
    }
}

Record* searchRecord(HashEntry** table, const string& key) { //�����
    int index = hashFunction(key);
    while (table[index] != nullptr) {
        if (!table[index]->deleted && table[index]->record->passportNumber == key) {
            return table[index]->record;
        }
        index = (index + 1) % HASH_TABLE_SIZE;
    }
    return nullptr;
}




void saveToFile(HashEntry** table, const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (table[i] != nullptr && !table[i]->deleted) {
            file << table[i]->record->fullName << " " << table[i]->record->phoneNumber << " " << table[i]->record->passportNumber << endl;
        }
    }
    file.close();
}

void loadFromFile(HashEntry** table, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string fullName, phoneNumber, passportNumber;
        while (file >> fullName >> phoneNumber >> passportNumber) {
            insertRecord(table, Record{ fullName, phoneNumber, passportNumber });
        }
        file.close();
    }
}

int countCollisions(HashEntry** table, int tableSize) {
    HashEntry** tempTable = new HashEntry * [HASH_TABLE_SIZE]();
    int collisions = 0;

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (table[i] != nullptr && !table[i]->deleted) {
            int index = hashFunction(table[i]->record->passportNumber) % tableSize;
            while (tempTable[index] != nullptr) {
                collisions++;
                index = (index + 1) % tableSize;
            }
            tempTable[index] = table[i];
        }
    }

    delete[] tempTable;
    return collisions;
}

int main() {
    system("chcp 1251>null");
    HashEntry** hashTable = new HashEntry * [HASH_TABLE_SIZE]();
    insertRecord(hashTable, Record{ "��������� ����� ����������", "7(982)611-32-43", "12345" });
    insertRecord(hashTable, Record{ "������� ������ ����������", "7(982)564-95-33", "64590" });
    insertRecord(hashTable, Record{ "���������� ���� ����������", "7(982)501-28-05", "67890" });
    insertRecord(hashTable, Record{ "������ ������� ������������", "7(982)746-97-39", "90890" });
    insertRecord(hashTable, Record{ "�������� ������� ���������", "7(982)407-65-12", "12890" });
    insertRecord(hashTable, Record{ "������� ������� ���������", "7(982)770-30-48", "40890" });


    // ���������� ������� � ����
    saveToFile(hashTable, "records.txt");

    // �������� ������� �� �����
    loadFromFile(hashTable, "records.txt");

    // ����� �������� �� �����
    Record* foundRecord = searchRecord(hashTable, "67890");
    if (foundRecord != nullptr) {
        cout << "������ �������: " << foundRecord->fullName << " " << foundRecord->phoneNumber << " " << foundRecord->passportNumber << endl;
    }
    else {
        std::cout << "������� �� ������." << endl;
    }

    // ������� ��������
    int collisions40 = countCollisions(hashTable, 40);
    int collisions75 = countCollisions(hashTable, 75);
    int collisions90 = countCollisions(hashTable, 90);

    cout << "���������� �������� ��� ������� ���-������� 40: " << collisions40 << endl;
    cout << "���������� �������� ��� ������� ���-������� 75: " << collisions75 << endl;
    cout << "���������� �������� ��� ������� ���-������� 90: " << collisions90 << endl;

    // ������� ������
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (hashTable[i] != nullptr) {
            delete hashTable[i]->record; // ������������ ������ ��� �������
            delete hashTable[i];
        }
    }
    delete[] hashTable;

    return 0;
}
