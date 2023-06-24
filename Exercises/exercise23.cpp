#include <iostream>

using namespace std;

struct node {
	int inf;
	node* parent;
	node* firstChild;
	node* nextSibling;
};

typedef node* tree;

int getInfo(node* n) { return n->inf; };
node* getParent(node* n) { return n->parent; }

tree getFirstChild(tree t) { return t->firstChild; }

tree getNextSibling(node* n) { return n->nextSibling; }

node* newNode(int inf) {
	node* n = new node;

	n->inf = inf;
	n->parent = n->firstChild = n->nextSibling = NULL;

	return n;
}

void insertChild(tree t, tree c) {
	c->nextSibling = getFirstChild(t);
	t->firstChild = c;
	c->parent = t;
}

void insertSibling(tree t, node* s) {
	s->nextSibling = t->nextSibling;

	s->parent = getParent(t);
	t->nextSibling = s;
}

int evenNodesCount(tree t) {
	if (t != NULL) {
		if (getInfo(t) % 2 == 0) {
			return 1 + evenNodesCount(getFirstChild(t)) +
				   evenNodesCount(getNextSibling(t));
		} else {
			return evenNodesCount(getFirstChild(t)) +
				   evenNodesCount(getNextSibling(t));
		}
	}

	return 0;
}

int main() {
	tree t = newNode(1);

	insertChild(t, newNode(2));
	insertChild(t, newNode(3));
	insertChild(t, newNode(4));
	insertChild(t, newNode(5));

	tree subtree = getFirstChild(t);

	insertChild(subtree, newNode(6));
	insertChild(subtree, newNode(7));
	insertChild(subtree, newNode(8));
	insertChild(subtree, newNode(9));

	subtree = getNextSibling(subtree);

	insertChild(subtree, newNode(10));
	insertChild(subtree, newNode(11));

	subtree = getFirstChild(subtree);

	insertChild(subtree, newNode(12));
	insertChild(subtree, newNode(166));

	cout << evenNodesCount(t) << endl;
}