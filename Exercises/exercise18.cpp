#include <iostream>

using namespace std;

struct elem {
	int inf;
	elem* next;
	elem* prev;
};

typedef elem* list;

int head(list l) { return l->inf; }

list tail(list l) { return l->next; };
list prev(list l) { return l->prev; };

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

bool isPalindrome(list l) {
	list revList = l;

	while (tail(revList) != NULL) {
		revList = tail(revList);
	}

	while (l != NULL) {
		if (head(l) != head(revList)) {
			return false;
		}

		l = tail(l);
		revList = prev(revList);
	}

	return true;
}

int main() {
	list l = createList(5);

	cout << isPalindrome(l) << endl;

	return 0;
}
