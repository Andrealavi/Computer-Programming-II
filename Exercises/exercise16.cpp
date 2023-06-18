#include <iostream>

using namespace std;

typedef int infType;

int compare(infType s1, infType s2) { return s1 - s2; }

void copy(infType& s1, infType s2) { s1 = s2; }

void print(infType s) { cout << s; }

struct node {
	infType inf;
	node* parent;
	node* firstChild;
	node* nextSibling;
};

typedef node* tree;

node* newNode(infType inf) {
	node* n = new node;

	copy(n->inf, inf);
	n->parent = n->firstChild = n->nextSibling = NULL;

	return n;
}

infType getInfo(node* n) { return n->inf; }

node* getParent(node* n) { return n->parent; }

tree getFirstChild(tree t) { return t->firstChild; }

tree getNextSibling(tree t) { return t->nextSibling; }

void insertChild(tree t, tree c) {
	c->nextSibling = getFirstChild(t);

	c->parent = t;
	t->firstChild = c;
}

void insertSibling(node* n, tree s) {
	s->parent = getParent(n);

	s->nextSibling = getNextSibling(n);
	n->nextSibling = s;
}

int countLess(tree t, infType n) {
	if (t != NULL) {
		if (compare(getInfo(t), n) < 0) {
			return 1 + countLess(getFirstChild(t), n) +
				   countLess(getNextSibling(t), n);
		} else {
			return countLess(getFirstChild(t), n) +
				   countLess(getNextSibling(t), n);
		}
	}

	return 0;
}

int main() {
	tree root = newNode(0);

	insertChild(root, newNode(1));

	tree subtree = getFirstChild(root);
	insertChild(subtree, newNode(3));
	insertChild(subtree, newNode(5));

	subtree = getFirstChild(subtree);
	insertChild(subtree, newNode(7));
	insertChild(subtree, newNode(9));
	insertChild(subtree, newNode(11));
	insertChild(subtree, newNode(13));

	insertChild(root, newNode(2));

	subtree = getFirstChild(root);
	insertChild(subtree, newNode(4));
	insertChild(subtree, newNode(6));
	subtree = getFirstChild(subtree);
	insertChild(subtree, newNode(10));
	subtree = getParent(subtree);
	insertChild(subtree, newNode(8));

	cout << countLess(root, 25) << endl;

	return 0;
}