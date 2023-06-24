#include <iostream>

using namespace std;

struct elem {
	int inf;
	elem* next;
	elem* prev;
};

typedef elem* list;

int head(list l) { return l->inf; };
list tail(list l) { return l->next; };
elem* prev(list l) { return l->prev; };

elem* newElem(int inf) {
	elem* e = new elem;

	e->inf = inf;
	e->next = e->prev = NULL;

	return e;
}

list insertElem(list l, elem* e) {
	if (l != NULL) {
		e->next = l;
		l->prev = e;
	}

	return e;
}

list createList(int n) {
	list l = NULL;
	int inf;

	for (int i = 0; i < n; i++) {
		cout << "Enter a number: ";
		cin >> inf;
		cout << endl;

		elem* e = newElem(inf);
		l = insertElem(l, e);
	}

	return l;
}

elem* findMiddleElem(list l) {
	int elemCount = 0;
	list l2 = l;

	for (; l2 != NULL; elemCount++, l2 = tail(l2)) {
	}

	if (elemCount == 0) {
		return NULL;
	}

	for (int i = 0; i < elemCount / 2; i++) {
		l = tail(l);
	}

	return l;
}

void printList(list l) {
	while (l != NULL) {
		cout << l->inf << endl;
		l = tail(l);
	}
}

int main() {
	list l = createList(5);

	printList(l);

	cout << endl;

	cout << findMiddleElem(l)->inf << endl;

	return 0;
}