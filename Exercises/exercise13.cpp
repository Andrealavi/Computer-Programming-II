#include <iostream>

using namespace std;

struct elem {
	int inf;
	elem* next;
};

typedef elem* list;

int head(list l) { return l->inf; }

list tail(list l) { return l->next; }

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

list createList(int n) {
	list l = NULL;
	int inf;

	for (int i = 0; i < n; i++) {
		cout << "Insert a number: ";
		cin >> inf;
		cout << endl;

		elem* e = newElem(inf);

		l = insertElem(l, e);
	}

	return l;
}

void recursivePrintList(list l) {
	if (l != NULL) {
		cout << head(l) << endl;
		recursivePrintList(tail(l));
	}
}

int main() {
	list l = createList(4);

	recursivePrintList(l);
}