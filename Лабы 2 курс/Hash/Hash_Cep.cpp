#include <iostream>
#include <string>
#include <ctime>
#define _USE_MATH_DEFINES // Вместо #include <cmath>
#include <math.h> // для использования констант
using namespace std;

const int M = 5;
const double A = M_PI_4; //Объявляет константу `A` со значением π/4.
int collisionCounter = 0;//Объявляет переменную для подсчета коллизий, инициализированную нулем.

struct Node { //структуры для узлов таблицы
	string key = "";
	string value = "";
	Node* next = nullptr;
	Node* prev = nullptr;
};

struct HashTable { //структура самой хэш-таблицы, инициализированные нулями
	Node* table[M];  //массив указателей на узлы
	HashTable() {
		for (int i = 0; i < M; ++i) {
			table[i] = nullptr;
		}
	}
};

double mod1(double k) {   //для вычисления дробной части числа k * A.
	int intPart = static_cast<int>(k);
	return k - intPart;
}

int getHash(double k) { //для вычисления хэша по числу
	return static_cast<int>(M * mod1(k * A));
}

int getHash(string line) { //для вычисления хэша по строке
	int n = 0;
	for (int i = 0; i < line.size(); i++) {
		//n += line[i];
		n += static_cast<int>(pow(line[i], 2) * M_2_SQRTPI + abs(line[i]) * M_SQRT1_2);
	}
	return getHash(abs(n));
}




bool add(HashTable& table, string key, string elem) //добавление нового элемента в хэш-таблицу(цепочка). 
{
	Node* newNode = new Node; //Создается новый узел `Node` с помощью оператора `new`, и ему присваиваются ключ (`key`) и значение (`elem`)
	newNode->key = key;
	newNode->value = elem;

	newNode->next = nullptr; //Устанавливаются указатели `next` и `prev` нового узла на `nullptr`, чтобы указать на то, что узел пока не связан ни с какими другими узлами.
	newNode->prev = nullptr;

	int hash = getHash(key); //Вычисляется хэш от ключа с помощью функции `getHash(key)`, чтобы определить индекс в массиве хэш-таблицы, куда нужно вставить новый узел

	if (table.table[hash] == nullptr) //Проверяется, есть ли уже какие-то узлы в этой ячейке хэш-таблицы. Если в указанной позиции нет других узлов, то новый узел становится первым в списке этой ячейки хэш-таблицы (`table.table[hash]`), и функция возвращает `true`
	{
		table.table[hash] = new Node;
		return true;
	}
	else {
		Node* current = table.table[hash]; //Извлекает указатель на первый узел в ячейке хэш-таблицы, определенной индексом `hash`
		while (current->next != nullptr) { //Начиная с первого узла в ячейке, функция проходит по связному списку до последнего узла.
			current = current->next;
		}
		current->next = newNode; //Новый узел добавляется в конец списка
		newNode->prev = current;//Устанавливаются связи между новым узлом и последним узлом списка.
		collisionCounter++;
		return true;
	}
}

bool removeByKey(HashTable& table, string key) { //удаляет элемент из хэш-таблицы по указанному ключу(цепочка)
	int hash = getHash(key);
	Node* current = table.table[hash];
	while (current != nullptr) {
		if (current->key == key) {
			if (current->prev != nullptr) {
				current->prev->next = current->next;
			}
			else {
				table.table[hash] = current->next;
			}
			if
				(current->next != nullptr) {
				current->next->prev = current->prev;
			}
			delete current;
			return true;
		}
		current = current->next;
	}
	return false;
}




bool removeByValue(HashTable& table, string elem) //удаление узла из связного списка в хэш-таблице по ключу `key`, если такой узел существует
{
	for (int i = 0; i < M; i++) {
		Node* current = table.table[i];
		while (current != nullptr) { //проходит по всем узлам в связном списке, начиная с узла `current`
			if (current->value == elem) {  //проверяется, совпадает ли ключ текущего узла `current` с ключом `key`, который мы хотим удалить
				if (current->prev != nullptr) { //Проверяется, существует ли предыдущий узел перед текущим узлом `current`. Если да, то перестраивается связь между предыдущим и следующим после удаляемого узла.
					current->prev->next = current->next;
				}
				else { // Если предыдущего узла нет (текущий узел `current` является первым в списке для данного хэша), то обновляется указатель начала списка в хэш-таблице `table.table[hash]`
					table.table[i] = current->next;
				}
				if (current->next != nullptr) { //Проверяется, существует ли следующий узел после текущего узла. Если да, то изменяется связь между следующим и предыдущим узлами.
					current->next->prev = current->prev;
				}
				delete current; // Удаляется текущий узел
				return true;
			}
			current = current->next;
		}
	}
	return false; //сли после прохода по всем узлам в списке не удалось найти узел с ключом `key`, возвращается `false`, обозначая, что узел с таким ключом не был найден и не был удален
}

Node* get(HashTable& table, string key) { //поиск узла в хэш-таблице по ключу `key
	int hash = getHash(key); //вычисляется хэш от ключа `key` с помощью функции `getHash(key)`
	Node* current = table.table[hash];//Получается указатель `current` на первый узел в связном списке в позиции хэш-таблицы, соответствующей вычисленному хэшу.
	while (current != nullptr) { //проходит по всем узлам связного списка, начиная с узла `current`
		if (current->key == key) //совпадает ли ключ текущего узла `current` с ключом `key`, который мы ищем. 
			return current; //функция возвращает указатель на текущий узел `current`, который содержит искомый ключ
		current = current->next;
	}
	return nullptr; //функция возвращает `nullptr`, что указывает на то, что элемент с таким ключом в хэш-таблице не был найден.
}

void print(HashTable& table) { // вывод содержимого всех ячеек хэш-таблицы
	for (int i = 0; i < M; i++) { //перебор всех индексов ячеек хэш-таблицы
		Node* current = table.table[i]; //Получается указатель `current` на первый узел в связном списке для текущей ячейки
		while (current != nullptr) { //проходит по всем узлам в связном списке.
			cout << "[" << current->key << ": " << current->value << "]\n"; //Для каждого узла выводится на экран содержимое в формате `[ключ: значение]`
			current = current->next; //- Указатель `current` переходит к следующему узлу в списке.
		}
	}
	cout << endl;
}

string surnames[] = { //Массив фамилий 
	"Иванов","Смирнов", "Муравьев", "Попов", "Глебко",
	"Менавщиков","Козлов", "Сычева", "Морозов", "Аликин",
	"Волков","Калинин", "Васильев", "Ломаев", "Аржевитин",
	"Семёнов", "Голубев", "Жигалов", "Богданов", "Воробьёв",
	"Амиров", "Михайлов", "Беляев", "Прозоров", "Белов",
	"Злыгостев", "Чудинов", "Соловьев", "Ходырев", "Овчинников"
};

string names[] = { //Массив имен 
	"Александр", "Сергей", "Андрей", "Дмитрий", "Алексей",
	"Михаил", "Иван", "Евгений", "Анатолий", "Владимир",
	"Николай", "Юрий", "Виктор", "Денис", "Влад",
	"Валентин", "Валерий", "Олег", "Константин", "Антон",
	"Роман", "Дмитрий", "Георгий", "Вячеслав", "Давид",
	"Никита", "Глеб", "Никита", "Руслан", "Александр"
};

string patronymics[] = { //Массив отчеств 
	"Александрович", "Сергеевич", "Андреевич", "Дмитриевич", "Алексеевич",
	"Иванович", "Николаевич", "Михайлович", "Олегович", "Петрович",
	"Анатольевич", "Владимирович", "Юрьевич", "Викторович", "Фёдорович",
	"Константинович", "Аркадьевич", "Егорович", "Васильевич", "Тимофеевич",
	"Игоревич", "Валерьевич", "Станиславович", "Романович", "Геннадьевич",
	"Павлович", "Вячеславович", "Евгеньевич", "Давыдович", "Григорьевич"
};

string generateFullName() { //Функция для генерации случайного ФИО.
	return surnames[rand() % 30] + ' ' + names[rand() % 30] + ' ' + patronymics[rand() % 30];
}

string correctStr(int n, int length) { //Вспомогательная функция для корректировки строк, добавляя нули или удаляя символы.
	string strn = to_string(n);
	while (strn.size() < length) {
		strn = '0' + strn;
	}
	while (strn.size() > length) {
		strn.erase(0, 1);
	}
	return strn;
}

string generatePhoneNum() { // Генерация случайной даты рождения.
	return '7' + correctStr(rand(), 3) + to_string(rand() % 10101010 * 100 + rand());
}

string generatePassportNum() { //Генерация случайного номера паспорта.
	return correctStr(rand() % 10000, 4) + ' ' + correctStr((rand() % 1000000 * 100 + rand()), 6);
}

int main() {
	system("chcp 1251>null");
	srand(time(NULL));
	HashTable myTable; //Создание экземпляра хэш-таблицы `myTable` обьект типа HashTable

	for (int i = 0; i < M; i++) //енерация случайных данных и добавление их в хэш-таблицу.
	{
		string PassNum = generatePassportNum();
		string newHuman = generateFullName() + " | " + generatePhoneNum() + " | " + PassNum;
		add(myTable, PassNum, newHuman);

	}
	cout << "Создана хэш-таблица: " << endl;
	print(myTable); //Вывод содержимого хэш-таблицы.

	cout << "Введите ключ для удаления: ";

	string keyToRemove;
	getline(cin, keyToRemove);
	cout << "Удаление по ключу '" << keyToRemove << "':" << endl;

	if (removeByKey(myTable, keyToRemove)) {
		cout << "Элемент с ключом '" << keyToRemove << "' успешно удалён." << endl;
	}
	else {
		cout << "Элемент с ключом '" << keyToRemove << "' не найден." << endl;
	}
	print(myTable);


	cout << "Введите значение для удаления: ";
	string valueToRemove;
	getline(cin, valueToRemove);
	cout << "Удаление по значению '" << valueToRemove << "':" << endl;

	if (removeByValue(myTable, valueToRemove)) {
		cout << "Элемент с значением '" << valueToRemove << "' успешно удалён." << endl;
	}
	else {
		cout << "Элемент с значением '" << valueToRemove << "' не найден." << endl;
	}
	print(myTable);

	cout << "Введите ключ для поиска: ";
	string keyToGet;
	getline(cin, keyToGet);
	cout << "Получение элемента по ключу '" << keyToGet << "':" << endl;
	Node* node = get(myTable, keyToGet);

	if (node != nullptr) { //проверка на последний элемент
		cout << "Найден элемент: " << node->value << endl;
	}
	else {
		cout << "Элемент с ключом '" << keyToGet << "' не найден." << endl;
	}
	cout << "Число коллизий: " << collisionCounter << endl;
	return 0;
}