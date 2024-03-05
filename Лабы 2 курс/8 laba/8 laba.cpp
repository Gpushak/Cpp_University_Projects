#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Структура "Видеокассета"
struct Videocassette {
    string title;
    string director;
    int duration;
    double price;
};

// Функция для вывода информации о видеокассетах
void printVideocassettes(const vector<Videocassette>& videocassettes) {
    for (const auto& cassette : videocassettes) {
        cout << "Название: " << cassette.title << endl;
        cout << "Режиссер: " << cassette.director << endl;
        cout << "Продолжительность: " << cassette.duration << " минут" << endl;
        cout << "Цена: $" << cassette.price << endl << endl;
    }
}

// Функция для удаления элементов с ценой выше заданной
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

// Функция для добавления трех элементов в конец файла
void addCassettesToEnd(vector<Videocassette>& videocassettes) {
    for (int i = 0; i < 3; ++i) {
        Videocassette newCassette;
        cout << "***" << endl << "Введите данные для новой видеокассеты:" << endl;
        cout << "Название: ";
        getline(cin, newCassette.title);
        cout << "Режиссер: ";
        getline(cin, newCassette.director);
        cout << "Продолжительность (в минутах): ";
        cin >> newCassette.duration;
        cout << "Цена: $";
        cin >> newCassette.price;
        cin.ignore(); // Очистка буфера ввода
        videocassettes.push_back(newCassette);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    const string filename = "videocassettes.bin";

    // Открытие файла для записи и чтения в бинарном формате
    ofstream outFile(filename, ios::binary);
    ifstream inFile(filename, ios::binary);

    if (!outFile.is_open() || !inFile.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    vector<Videocassette> videocassettes;

    // Формирование структур видеокассет и запись их в файл
    Videocassette cassette1 = { "Film1", "Producer1", 120, 9.99 };
    Videocassette cassette2 = { "Film", "Producer2", 90, 14.99 };
    videocassettes.push_back(cassette1);
    videocassettes.push_back(cassette2);

    outFile.write(reinterpret_cast<char*>(&videocassettes[0]), videocassettes.size() * sizeof(Videocassette));

    // Вывод содержимого файла
    cout << "Исходное содержимое файла:" << endl;
    printVideocassettes(videocassettes);

    // Удаление элементов с ценой выше заданной
    double maxPrice = 12.0;
    removeCassettesAbovePrice(videocassettes, maxPrice);

    // Вывод обновленного содержимого файла
    cout << "********************************************" << endl << "Содержимое файла после удаления элементов с ценой выше $" << maxPrice << ":" << endl;
    printVideocassettes(videocassettes);

    // Добавление трех элементов в конец файла
    addCassettesToEnd(videocassettes);

    // Запись обновленных данных в файл
    outFile.seekp(0, ios::beg);
    outFile.write(reinterpret_cast<char*>(&videocassettes[0]), videocassettes.size() * sizeof(Videocassette));

    // Вывод окончательного содержимого файла
    cout << "********************************************" << endl << "Содержимое файла после добавления новых элементов:" << endl;
    printVideocassettes(videocassettes);

    // Закрытие файлов
    outFile.close();
    inFile.close();

    return 0;
}
