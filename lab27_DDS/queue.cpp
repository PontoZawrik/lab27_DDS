#include <iostream>
using namespace std;

struct Spis {
	int info;
	Spis* next;
};

void Create(Spis** begin, Spis** end, int inf) {
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
	cout << "" << t << "" << t->info << "" << t->next << endl;
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
	cout << "" << *begin << "" << (*begin)->info << "" << (*begin)->next << endl;
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
	Spis* begin = NULL, * end = NULL;
	Spis* t = new Spis();

	if (!t) {
		cout << "";
		system("pause");
		return 0;
	}

	int inf;
	cout << "";
	cin >> inf;
	t->info = inf;
	t->next = NULL;
	begin = end = t;

	t = new Spis();
	if (!t) {
		cout << "";
		system("pause");
		return 0;
	}

	cout << "";
	cin >> inf;
	t->info = inf;
	t->next = NULL;
	end->next = t;
	end = t;

	int repeat = 1;
	while (repeat) {
		cout << "";
		cin >> inf;
		Create(&begin, &end, inf);

		cout << "";
		cin >> repeat;
	}

	ViewQueue(&begin, &end);
	int r = 1;

	do {
		cout << "";
		cin >> r;

		switch (r) {
			case 0: {
				break;
			}
			case 1: {
				int inf;
				cout << "";
				cin >> inf;
				Create(&begin, &end, inf);
				cout << "";
				break;
			}
			case 2: {
				ViewElemQueue(&begin, &end);
				break;
			}
			case 3: {
				ViewQueue(&begin, &end);
				break;
			}
			case 4: {
				DeleteFirst(&begin, &end);
				break;
			}
			case 5: {
				DeleteQueue(&begin, &end);
				break;
			}
		}
	} while (r != 0);
	system("pause");
	return 0;
}