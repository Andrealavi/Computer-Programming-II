#include <iostream>

using namespace std;

typedef int infType;

int compare(infType s1, infType s2) { return s1 - s2; }

void copy(infType& s1, infType s2) { s1 = s2; }

void print(infType s) { cout << s; }

struct elem {
	infType inf;
	elem* next;
	elem* prev;
};

typedef elem* list;

infType head(list l) { return l->inf; }

list tail(list l) { return l->next; }

elem* prev(elem* e) { return e->prev; }

void printList(list l) {
	while (l != NULL) {
		print(head(l));
		cout << endl;

		l = tail(l);
	}
}

elem* newElem(infType inf) {
	elem* e = new elem;

	e->next = NULL;
	e->prev = NULL;

	copy(e->inf, inf);

	return e;
}

list insertElem(list l, elem* e) {
	if (l != NULL) {
		e->next = l;
		l->prev = e;
	}

	return e;
}

void insertList(list& l1, list l2) {
	while (l2 != NULL) {
		list l3 = l1;

		while (compare(head(l2), head(l3)) > 0) {
			if (tail(l3) != NULL) {
				l3 = tail(l3);
			} else {
				break;
			}
		}

		elem* e = newElem(head(l2));

		if (tail(l3) == NULL && compare(head(l2), head(l3)) > 0) {
			e->prev = l3;
			l3->next = e;
		} else {
			e->next = l3;
			e->prev = l3->prev;

			if (l3 == l1) {
				l1 = e;
			} else {
				(l3->prev)->next = e;
			}

			l3->prev = e;
		}

		l2 = tail(l2);
	}
}

list createList(int n) {
	list l = NULL;
	infType num;

	for (int i = 0; i < n; i++) {
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		l = insertElem(l, newElem(num));
	}

	return l;
}

int main() {
	cout << "List 1: " << endl;
	list l1 = createList(3);

	cout << "List 2: " << endl;
	list l2 = createList(3);

	cout << "List 1: " << endl;

	printList(l1);

	cout << endl << "List 2: " << endl;

	printList(l2);

	cout << endl;

	insertList(l1, l2);

	cout << endl;

	printList(l1);
}