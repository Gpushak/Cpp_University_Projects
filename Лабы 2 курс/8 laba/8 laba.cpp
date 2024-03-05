#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// ��������� "������������"
struct Videocassette {
    string title;
    string director;
    int duration;
    double price;
};

// ������� ��� ������ ���������� � �������������
void printVideocassettes(const vector<Videocassette>& videocassettes) {
    for (const auto& cassette : videocassettes) {
        cout << "��������: " << cassette.title << endl;
        cout << "��������: " << cassette.director << endl;
        cout << "�����������������: " << cassette.duration << " �����" << endl;
        cout << "����: $" << cassette.price << endl << endl;
    }
}

// ������� ��� �������� ��������� � ����� ���� ��������
void removeCassettesAbovePrice(vector<Videocassette>& videocassettes, double maxPrice) {
    videocassettes.erase(
        remove_if(videocassettes.begin(), videocassettes.end(),
            [maxPrice](const Videocassette& cassette) {
                return cassette.price > maxPrice;
            }
        ),
        videocassettes.end()
    );
}

// ������� ��� ���������� ���� ��������� � ����� �����
void addCassettesToEnd(vector<Videocassette>& videocassettes) {
    for (int i = 0; i < 3; ++i) {
        Videocassette newCassette;
        cout << "***" << endl << "������� ������ ��� ����� ������������:" << endl;
        cout << "��������: ";
        getline(cin, newCassette.title);
        cout << "��������: ";
        getline(cin, newCassette.director);
        cout << "����������������� (� �������): ";
        cin >> newCassette.duration;
        cout << "����: $";
        cin >> newCassette.price;
        cin.ignore(); // ������� ������ �����
        videocassettes.push_back(newCassette);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    const string filename = "videocassettes.bin";

    // �������� ����� ��� ������ � ������ � �������� �������
    ofstream outFile(filename, ios::binary);
    ifstream inFile(filename, ios::binary);

    if (!outFile.is_open() || !inFile.is_open()) {
        cerr << "������ �������� �����." << endl;
        return 1;
    }

    vector<Videocassette> videocassettes;

    // ������������ �������� ����������� � ������ �� � ����
    Videocassette cassette1 = { "Film1", "Producer1", 120, 9.99 };
    Videocassette cassette2 = { "Film", "Producer2", 90, 14.99 };
    videocassettes.push_back(cassette1);
    videocassettes.push_back(cassette2);

    outFile.write(reinterpret_cast<char*>(&videocassettes[0]), videocassettes.size() * sizeof(Videocassette));

    // ����� ����������� �����
    cout << "�������� ���������� �����:" << endl;
    printVideocassettes(videocassettes);

    // �������� ��������� � ����� ���� ��������
    double maxPrice = 12.0;
    removeCassettesAbovePrice(videocassettes, maxPrice);

    // ����� ������������ ����������� �����
    cout << "********************************************" << endl << "���������� ����� ����� �������� ��������� � ����� ���� $" << maxPrice << ":" << endl;
    printVideocassettes(videocassettes);

    // ���������� ���� ��������� � ����� �����
    addCassettesToEnd(videocassettes);

    // ������ ����������� ������ � ����
    outFile.seekp(0, ios::beg);
    outFile.write(reinterpret_cast<char*>(&videocassettes[0]), videocassettes.size() * sizeof(Videocassette));

    // ����� �������������� ����������� �����
    cout << "********************************************" << endl << "���������� ����� ����� ���������� ����� ���������:" << endl;
    printVideocassettes(videocassettes);

    // �������� ������
    outFile.close();
    inFile.close();

    return 0;
}
