#include <iostream>

// clang-format off
#include "type.h"
#include "lists.h"
// clang-format on

using namespace std;

infType head(list l) { return l->url; }

list tail(list l) { return l->next; }

list prev(list l) { return l->prev; }

elem *newElem(infType url) {
	elem *e = new elem;

	copy(e->url, url);
	e->next = e->prev = NULL;

	return e;
}

elem *search(list l, infType url) {
	while (l != NULL) {
		if (compare(head(l), url) == 0) {
			return l;
		} else {
			l = tail(l);
		}
	}

	return NULL;
}

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
