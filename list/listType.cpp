#include "listType.h"

#include <cstring>

#include "lists.h"

char *head(list l) { return l->url; }

elem *newElem(char *url) {
	elem *e = new elem;

	strcpy(e->url, url);
	e->next = e->prev = NULL;

	return e;
}

elem *search(list l, char *url) {
	while (l != NULL) {
		if (strcmp(head(l), url) == 0) {
			return l;
		} else {
			l = tail(l);
		}
	}

	return NULL;
}