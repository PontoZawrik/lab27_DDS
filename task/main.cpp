#include <iostream> // Роблокс
#include <Windows.h>
using namespace std;

struct Book {
	char ID[20];
	char author[50];
	char name[50];
	int year;
	char company[50];
	int pageCount;

	void show() {
		cout << "Регистрационный номер: " << ID << endl
			<< "Автор: " << author << " - Название: \"" << name << '\"' << endl
			<< "Количество страниц: " << pageCount << endl
			<< "Издательство: " << company << " в " << year << "г." << endl
			<< "Возраст: " << 2026 - year;
	}
};

struct Spis {
	Book info;
	Spis* next;
};

void Create(Spis** begin, Spis** end, Book inf) {
	Spis* t = new Spis();

	if (!t) {
		cout << "";
		system("pause");
		return;
	}
	t->info = inf;
	t->next = NULL;

	if (*begin == NULL) {
		*begin = *end = t;
	}
	else {
		(*end)->next = t;
		*end = t;
	}
}

void DeleteFirst(Spis** begin, Spis** end) {
	if (*begin == NULL) {
		cout << "";
		return;
	}

	Spis* t = *begin;
	*begin = (*begin)->next;
	delete t;
}

void DeleteQueue(Spis** begin, Spis** end) {
	while (*begin != NULL) {
		DeleteFirst(begin, end);
	}
}

void ViewElemQueue(Spis** begin, Spis** end) {
	if (*begin == NULL) {
		cout << "";
		return;
	}
	(*begin)->info.show();
	cout << endl;
}

void ViewQueue(Spis** begin, Spis** end) {
	if (*begin == NULL) {
		cout << "";
		return;
	}
	Spis* t = *begin;
	while (t != NULL) {
		ViewElemQueue(&t, end);
		t = t->next;
	}
}

int main() {
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	Spis* begin = NULL, * end = NULL;
	Spis* t = new Spis();

	if (!t) {
		cout << "Ошибка памяти";
		system("pause");
		return 0;
	}

	int count;
	cout << "Количество книг: ";
	cin >> count;
	cin.ignore();

	Book inf;

	for (int i = 0; i < count; i++) {
		cout << "Книга " << i + 1 << endl << endl;

		cout << "Регистрационный номер: ";
		cin.getline(inf.ID, 50);
		cout << "Автор: ";
		cin.getline(inf.author, 50);
		cout << "Название: ";
		cin.getline(inf.name, 50);
		cout << "Издательство: ";
		cin.getline(inf.company, 50);
		cout << "Год выпуска: ";
		cin >> inf.year;
		cout << "количество страниц: ";
		cin >> inf.pageCount;
		cout << endl;

		Create(&begin, &end, inf);
	}

	int p;
	do {
		cout << "1-Создать элемент\n2-Удалить первый элемент\n3-Удалить очередь\n4-Отобразить первый элемент\n5-Отобразить очередь ";
		cout << "Введите значение: ";
		cin >> p;
		cin.ignore();

		switch (p) {
			case 1: {
				cout << "Регистрационный номер: ";
				cin.getline(inf.ID, 50);
				cout << "Автор: ";
				cin.getline(inf.author, 50);
				cout << "Название: ";
				cin.getline(inf.name, 50);
				cout << "Издательство: ";
				cin.getline(inf.company, 50);
				cout << "Год выпуска: ";
				cin >> inf.year;
				cout << "количество страниц: ";
				cin >> inf.pageCount;
				cout << endl;

				Create(&begin, &end, inf);
				break;
			}
			case 2: {
				DeleteFirst(&begin, &end);
				break;
			}
			case 3: {
				DeleteQueue(&begin, &end);
				break;
			}
			case 4: {
				ViewElemQueue(&begin, &end);
				cout << endl;
				break;
			}
			case 5: {
				ViewQueue(&begin, &end);
				cout << endl;
				break;
			}
			default: cout << "Неверный ввод." << endl; break;
		}
	} while (p != -1);

	system("pause");
	DeleteQueue(&begin, &end);
	return 0;

}