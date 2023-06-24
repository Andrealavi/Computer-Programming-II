#include "string.h"
#include "tree.h"

#include <iostream>

infType getInfo(node* n) { return n->inf; }

node* getParent(node* n) { return n->parent; }

node* getFirstChild(node* n) { return n->firstChild; }

node* getNextSibling(node* n) { return n->nextSibling; }

node* newNode(infType inf) {
	node* n = new node;

	n->firstChild = n->parent = n->nextSibling = NULL;

	copy(n->inf, inf);

	return n;
}

void insertChild(tree t, tree c) {
	c->parent = t;

	c->nextSibling = getFirstChild(t);
	t->firstChild = c;
}

void insertSibling(node* n, tree s) {
	s->parent = getParent(n);
	s->nextSibling = getNextSibling(n);

	n->nextSibling = s;
}

void deleteNode(tree& t, node* n) {
	if (t == n) {
		t = getFirstChild(t);

		t->parent = NULL;

		node* sibling = getNextSibling(t);

		while (sibling != NULL) {
			sibling->parent = t;
			sibling = getNextSibling(sibling);
		}

		if (getFirstChild(t) != NULL) {
			insertSibling(getFirstChild(t), getNextSibling(t));
		} else {
			sibling = getNextSibling(getNextSibling(t));
			insertChild(t, getNextSibling(t));
			t->firstChild->nextSibling = sibling;
		}

		t->nextSibling = NULL;
	} else if (getFirstChild(n) != NULL) {
		insertChild(getParent(n), getFirstChild(n));

		node* sibling = getNextSibling(getFirstChild(n));

		while (sibling != NULL) {
			sibling->parent = getParent(n);
			sibling = getNextSibling(sibling);
		}

		sibling = getFirstChild(getParent(n));

		while (getNextSibling(sibling) != n) {
			sibling = getNextSibling(sibling);
		}

		sibling->nextSibling = (sibling->nextSibling)->nextSibling;

	} else {
		if (getFirstChild(getParent(n)) == n) {
			if (getNextSibling(n) != NULL) {
				node* sibling = getNextSibling(getNextSibling(n));
				insertChild(getParent(n), getNextSibling(n));
				n->parent->firstChild->nextSibling = sibling;
			} else {
				n->parent->firstChild = NULL;
			}
		} else {
			node* sibling = getFirstChild(getParent(n));

			while (getNextSibling(sibling) != n) {
				sibling = getNextSibling(sibling);
			}

			sibling->nextSibling = (sibling->nextSibling)->nextSibling;
		}
	}

	delete n;
}

node* search(tree t, infType inf) {
	if (t != NULL) {
		if (compare(getInfo(t), inf) == 0) {
			return t;
		}

		node* n1 = search(getFirstChild(t), inf);
		node* n2 = search(getNextSibling(t), inf);

		if (n1 != NULL) {
			return n1;
		} else {
			return n2;
		}
	}

	return NULL;
}