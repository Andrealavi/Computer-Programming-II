#include <iostream>

#include "type.h"
#include "list.h"

using namespace std;

infType head(list l) { return l->id; };
list tail(list l) { return l->next; };

elem* newElem(infType inf) {
	elem* e = new elem;

	copy(e->id, inf);
	e->next = NULL;

	return e;
}

list insertElem(list l, elem* e) {
	if (l != NULL) {
		e->next = l;
	}

	return e;
}

list deleteElem(list l, elem* e) {
	if (e == l) {
		l = tail(l);
	} else {
		while (tail(l) != e) {
			l = tail(l);
		}

		l->next = e->next;
	}

	delete e;

	return l;
}

elem* search(list l, infType id) {
	while (l != NULL && compare(head(l), id) != 0) {
		l = tail(l);
	}

	return l;
}
