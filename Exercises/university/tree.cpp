#include "type.h"
#include "tree.h"

typedef node* tree;

infType getInfo(node* n) { return n->inf; }

node* getParent(node* n) { return n->parent; };
node* getFirstChild(node* n) { return n->firstChild; };
node* getNextSibling(node* n) { return n->nextSibling; };

void insertChild(tree p, tree c) {
	c->nextSibling = getFirstChild(p);

	p->firstChild = c;
	c->parent = p;
}

void insertSibling(node* n, tree s) {
	s->nextSibling = getNextSibling(n);

	n->nextSibling = s;
	s->parent = getParent(n);
}