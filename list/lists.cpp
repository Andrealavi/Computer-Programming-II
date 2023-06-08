#include <iostream>

// clang-format off
#include "listType.h"
#include "lists.h"
// clang-format on

using namespace std;

list tail(list l) { return l->next; }

list prev(list l) { return l->prev; }

list insertElem(list l, elem *e) {
	if (l != NULL) {
		l->prev = e;
	}

	e->next = l;
	e->prev = NULL;

	return e;
}

list deleteElem(list l, elem *e) {
	if (e == NULL) {
		return l;
	}

	if (l == e) {
		l = tail(l);
		delete e;

		return l;
	} else {
		e->next->prev = prev(e);
		e->prev->next = tail(e);
	}
	return l;
}