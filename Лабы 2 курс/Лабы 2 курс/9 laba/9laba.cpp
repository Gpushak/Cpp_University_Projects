#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ������� ��� ����������� ������ ��������� ����� � ������
string findShortestWord(const string& line) {
    string shortestWord;
    int shortestLength = INT_MAX;
    string word;
    int start = 0;

    for (int i = 0; i <= line.length(); ++i) {
        if (i == line.length() || line[i] == ' ') {
            string currentWord = line.substr(start, i - start);
            if (currentWord.length() < shortestLength) {
                shortestLength = currentWord.length();
                shortestWord = currentWord;
            }
            start = i + 1;
        }
    }

    return shortestWord;
}

int main() {
    setlocale(LC_ALL, "rus");
    ifstream inFile("C:\\Users\\igleb\\OneDrive\\������� ����\\F1.txt");
    ofstream outFile("C:\\Users\\igleb\\OneDrive\\������� ����\\F2.txt");
    string line;
    int lineNumber = 0;
    int shortestWordLineNumber = 0;
    string shortestWord = "Bazinga";

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "������ �������� �����!" << endl;
        return 1;
    }

    // ������ ����� �� ����� F1
    while (getline(inFile, line)) {
        lineNumber++;

        string shortestWordInLine = findShortestWord(line);
        if (shortestWordInLine.length() < shortestWord.length()) {
            shortestWord = shortestWordInLine;
            shortestWordLineNumber = lineNumber;
        }

        outFile << line << endl;
    }

    for (int i = 0; i < lines.size(); ++i) {
        if (i + 1 != shortestWordLineNumber) { // ���������� ������ � ����� �������� ������
            outFile << lines[i] << endl;
        }
    }
    cout << "����� ������ � ����� �������� ������: " << shortestWordLineNumber + 1 << endl;

    inFile.close();
    outFile.close();

    return 0;
}
