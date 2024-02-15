#include <iostream>
#include <string>
using namespace std;

void separateAndPrintWords(string s) {
    string digits; // �����, ���������� ������ �����
    string letters; // �����, ���������� ������ �����
    string mixed; // �����, ���������� � ����� � �����

    int start = 0;
    int end = 1;

    // ���������� ������� ������
    while (end != string::npos) {
        // ������� ������ ���������� �����
        start = s.find_first_not_of(" ", end);

        // ���� ��������� ����� ������, ������� �� �����
        if (start == string::npos)
            break;

        // ������� ����� �������� �����
        end = s.find_first_of(".", start);

        // ��������� ����� �� ������
        string word = s.substr(start, end - start);

        // ���������, �������� �� ����� ������ �����
        bool hasDigit = true;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!isdigit(c)) {
                hasDigit = false;
                break;
            }
        }

        // ���������, �������� �� ����� ������ �����
        bool hasLetter = true;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!isalpha(c)) {
                hasLetter = false;
                break;
            }
        }

        // ���������� ��������� ����� � ��������� ��� � ��������������� ������
        if (hasDigit && !hasLetter) {
            digits += word + " ";
        }
        else if (!hasDigit && hasLetter) {
            letters += word + " ";
        }
        else {
            mixed += word + " ";
        }
    }

    // ������� ����� � �������� �������
    cout << digits << letters << mixed << "." << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    string s;
    cout << "������� ������: ";
    getline(cin, s); // ���������� getline ��� ����� ������

    //������ ������������� ������:  Code Life01 01011010 SetUrMind

    separateAndPrintWords(s);

    return 0;
}
