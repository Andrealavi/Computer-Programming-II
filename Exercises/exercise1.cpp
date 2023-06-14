#include <iostream>

using namespace std;

struct elem {
	int n;
	elem* next;
};

typedef elem* list;

int head(list l) { return l->n; }

list tail(list l) { return l->next; }

elem* newElem(int n) {
	elem* e = new elem;

	e->n = n;
	e->next = NULL;

	return e;
}

list insertElem(list l, elem* e) {
	if (l == NULL) {
		l = e;
	} else {
		list l1 = l;

		while (tail(l1) != NULL) {
			l1 = tail(l1);
		}

		l1->next = e;
	}

	return l;
}

void printList(list l) {
	while (l != NULL) {
		cout << l->n << endl;
		l = tail(l);
	}
}

list deleteLastElem(list l) {
	list l1 = l;

	while (tail(tail(l1)) != NULL) {
		l1 = tail(l1);
	}

	delete tail(l1);

	l1->next = NULL;

	return l;
}

void emptyList(list& l) {
	while (l != NULL) {
		elem* e = l;
		l = tail(l);

		delete e;
	}

	l = NULL;
}

int main() {
	int choice, n;
	list l = NULL;

	do {
		cout << "1) Insert a new number\n";
		cout << "2) Remove last element\n";
		cout << "3) Print list\n";
		cout << "4) Empty list\n";
		cout << "5) Exit\n";
		cout << endl;

		cout << "Make your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 1:
				cout << "Insert a number: ";
				cin >> n;
				cout << endl;

				l = insertElem(l, newElem(n));
				break;

			case 2:
				deleteLastElem(l);
				break;

			case 3:
				printList(l);
				break;

			case 4:
				emptyList(l);
				break;

			case 5:
				return 0;

			default:
				break;
		}

		cout << endl;

	} while (choice);

	return 0;
}