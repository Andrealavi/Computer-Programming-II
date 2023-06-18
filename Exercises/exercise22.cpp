#include <iostream>

using namespace std;

struct elem {
	int inf;
	elem* next;
};

typedef elem* list;

int head(list l) { return l->inf; };
list tail(list l) { return l->next; };

elem* newElem(int inf) {
	elem* e = new elem;

	e->inf = inf;
	e->next = NULL;

	return e;
}

list insertElem(list l, elem* e) {
	if (l != NULL) {
		e->next = l;
	}

	return e;
}

void printList(list l) {
	while (l != NULL) {
		cout << l->inf << endl;
		l = tail(l);
	}
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

list splitList(list& l) {
	list splitList = NULL;
	list l2;

	if (head(l) % 2 == 0) {
		elem* e = l;

		l = tail(l);

		e->next = splitList;
		splitList = e;
	}

	l2 = l;

	while (l2 != NULL) {
		if (head(tail(l2)) % 2 == 0) {
			elem* e = l2->next;

			l2->next = (l2->next)->next;

			e->next = splitList;
			splitList = e;
		}

		l2 = tail(l2);
	}

	return splitList;
}

int main() {
	list l = createList(5);

	printList(l);

	list l2 = splitList(l);

	cout << endl;
	cout << endl;

	printList(l);

	cout << endl;
	cout << endl;

	printList(l2);

	return 0;
}