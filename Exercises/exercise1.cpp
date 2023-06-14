#include <iostream>

using namespace std;

struct elem {
	int n;
	elem* next;
	elem* prev;
};

typedef elem* list;

int head(list l) { return l->n; }

list tail(list l) { return l->next; }

elem* prev(elem* e) { return e->prev; }

elem* newElem(int n) {
	elem* e = new elem;

	e->n = n;
	e->next = e->prev = NULL;

	return e;
}

list insertElem(list l, elem* e) {
	if (l == NULL) {
		return e;
	} else {
		if (l->prev != NULL) {
			(l->prev)->next = e;
		}
		(l->next) = (l->prev);
		(e->prev) = (l->prev);
		(l->prev) = e;
		(e->next) = l;
	}

	return l;
}

list deleteLastElem(list l) {
	elem* e = (l->prev);

	(e->prev)->next = l;
	(l->prev) = (e->prev);

	delete e;

	return l;
}

void printList(list l) {
	list l1 = l;

	while (tail(l) != l1) {
		cout << l->n << endl;
		l = tail(l);

		if (tail(l) == l1&&) {
			l1 = tail(l1);
		}
	}
}

list emptyList(list& l) {
	while (l != NULL) {
		elem* e = l;

		l = tail(l);

		delete e;
	}

	return NULL;
}

int main() {
	int choice, n;
	list l = NULL;

	do {
		cout << "1) Insert a new number\n";
		cout << "2) Remove last element\n";
		cout << "3) Print list\n";
		cout << "4) Empty list\n";
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
				l = emptyList(l);
				break;

			default:
				break;
		}

		cout << endl;

	} while (choice);

	return 0;
}