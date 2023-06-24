#include <iostream>

using namespace std;

struct node {
	int inf;
	node* parent;
	node* firstChild;
	node* nextSibling;
};

typedef node* tree;

node* newNode(int inf) {
	node* n = new node;

	n->inf = inf;
	n->firstChild = n->nextSibling = NULL;

	return n;
}

node* getParent(node* n) { return n->parent; };
tree getFirsChild(tree t) { return t->firstChild; };
tree getNextSibling(node* t) { return t->nextSibling; };

void insertChild(tree t, tree c) {
	c->nextSibling = getFirsChild(t);
	c->parent = t;

	t->firstChild = c;
}

void insertSibling(node* n, tree s) {
	s->parent = getParent(n);

	s->nextSibling = getNextSibling(n);
	n->nextSibling = s;
}

int main() {
	tree t = newNode(1);

	insertChild(t, newNode(2));
	insertChild(t, newNode(3));
	insertChild(t, newNode(4));
	insertChild(t, newNode(5));
	insertChild(t, newNode(6));

	tree subtree = getFirsChild(t);

	insertChild(subtree, newNode(7));
	insertChild(subtree, newNode(8));

	subtree = getNextSibling(subtree);

	insertChild(subtree, newNode(9));
	insertChild(subtree, newNode(10));
	insertChild(subtree, newNode(11));

	subtree = getNextSibling(subtree);

	insertChild(subtree, newNode(15));

	subtree = getFirsChild(subtree);

	insertChild(subtree, newNode(20));
	insertChild(subtree, newNode(25));

	return 0;
}