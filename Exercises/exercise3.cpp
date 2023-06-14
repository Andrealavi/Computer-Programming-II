#include <iostream>

using namespace std;

struct elem {
	int n;
	elem* next;
};

typedef elem* list;

elem* newElem(int n) {
	elem* el = new elem;

	el->n = n;
	el->next = NULL;

	return el;
}

void printList(list l) {
	while (l != NULL) {
		cout << l->n << endl;
		l = l->next;
	}
}

list insertElem(list l, elem* e) {
	if (l != NULL) {
		e->next = l;
	}

	return e;
}

int main() {
	int n;
	list l = NULL;

	for (int i = 0;; i++) {
		cout << "Insert a number: ";
		cin >> n;
		cout << endl;

		if (n == -1) {
			break;
		}

		elem* e = newElem(n);
		l = insertElem(l, e);
	}

	printList(l);

	return 0;
}