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