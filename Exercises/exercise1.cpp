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

list insertHead(list l, elem* e) {
	if (l != NULL) {
		e->next = l;
	}

	return e;
}

list insertPos(list l, elem* e, int pos) {
	list l1 = l;

	for (int i = 1; i < pos; i++) {
		l1 = tail(l1);
	}

	cout << head(l1) << endl;

	e->next = tail(l1);
	l1->next = e;

	return l;
}

list insertAfter(list l, elem* e, int pos) {
	list l1 = l;

	for (int i = 0; i < pos; i++) {
		l1 = tail(l1);
	}

	e->next = tail(l1);
	l1->next = e;

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

list deletePos(list l, int pos) {
	list l1 = l;

	for (int i = 1; i < pos; i++) {
		l1 = tail(l1);
	}

	elem* e = tail(l1);
	l1->next = e->next;

	delete e;

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
	int choice, n, pos;
	list l = NULL;

	do {
		cout << "1) Insert a new number\n";
		cout << "2) Remove last element\n";
		cout << "3) Print list\n";
		cout << "4) Empty list\n";
		cout << "5) Insert as first element\n";
		cout << "6) Insert in pos\n";
		cout << "7) Insert after\n";
		cout << "8) Delete in pos\n";
		cout << "9) Exit\n";
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
				cout << "Insert a number: ";
				cin >> n;
				cout << endl;

				l = insertHead(l, newElem(n));
				break;

			case 6:
				cout << "Insert a number: ";
				cin >> n;
				cout << endl;

				cout << "Insert position: ";
				cin >> pos;
				cout << endl;

				l = insertPos(l, newElem(n), pos);
				break;

			case 7:
				cout << "Insert a number: ";
				cin >> n;
				cout << endl;

				cout << "Insert position: ";
				cin >> pos;
				cout << endl;

				l = insertAfter(l, newElem(n), pos);
				break;

			case 8:
				cout << "Insert position: ";
				cin >> pos;
				cout << endl;

				deletePos(l, pos);
				break;

			case 9:
				return 0;

			default:
				break;
		}

		cout << endl;

	} while (choice);

	return 0;
}