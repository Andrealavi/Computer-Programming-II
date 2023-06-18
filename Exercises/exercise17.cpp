#include <iostream>

using namespace std;

typedef int infType;

int compare(infType s1, infType s2) { return s1 - s2; };

void copy(infType& s1, infType s2) { s1 = s2; }

void print(infType s) { cout << s; }

struct elem {
	infType inf;
	elem* next;
};

typedef elem* list;

elem* newElem(infType inf) {
	elem* e = new elem;

	copy(e->inf, inf);
	e->next = NULL;

	return e;
}

infType head(list l) { return l->inf; }

list tail(list l) { return l->next; }

list insertElem(list l, elem* e) {
	if (l != NULL) {
		e->next = l;
	}

	return e;
}

void printList(list l) {
	while (l != NULL) {
		print(head(l));
		cout << endl;

		l = tail(l);
	}
}

list createList(int n) {
	list l = NULL;
	infType inf;

	for (int i = 0; i < n; i++) {
		cout << "Enter a number: ";
		cin >> inf;
		cout << endl;

		elem* e = newElem(inf);

		l = insertElem(l, e);
	}

	return l;
}

void sumElem(list l, int n) {
	list l2 = l;

	for (int i = 0; i < n && l2 != NULL; i++) {
		l2 = tail(l2);
	}

	if (l2 == NULL) {
		cout << "The number is too big!" << endl;
		return;
	}

	infType inf = head(l2);

	while (l != NULL) {
		l->inf += inf;
		l = tail(l);
	}
}

int main() {
	list l = createList(4);

	cout << "List before sum: " << endl;
	printList(l);

	cout << endl;

	sumElem(l, 2);

	cout << "List after sum: " << endl;
	printList(l);

	return 0;
}