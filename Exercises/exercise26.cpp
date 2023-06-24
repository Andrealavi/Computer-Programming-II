#include <iostream>

using namespace std;

typedef int infType;

struct bnode {
	infType inf;
	bnode* parent;
	bnode* left;
	bnode* right;
};

typedef bnode* bst;

int compare(infType s1, infType s2) { return s1 - s2; }

void copy(infType& s1, infType s2) { s1 = s2; }

infType getInf(bst t) { return t->inf; }

bnode* getLeft(bst t) { return t->left; };
bnode* getRight(bst t) { return t->right; };
bnode* getParent(bnode* n) { return n->parent; };

bnode* newNode(infType inf) {
	bnode* n = new bnode;

	copy(n->inf, inf);

	n->parent = n->left = n->right = NULL;

	return n;
}

void bstInsert(bst& t, bnode* n) {
	if (t == NULL) {
		t = n;
	} else {
		if (compare(t->inf, n->inf) >= 0 && getLeft(t) == NULL) {
			t->left = n;
			n->parent = t;
		} else if (compare(t->inf, n->inf) >= 0 && getLeft(t) != NULL) {
			bstInsert(t->left, n);
		} else if (compare(t->inf, n->inf) < 0 && getRight(t) == NULL) {
			t->right = n;
			n->parent = t;
		} else if (compare(t->inf, n->inf) < 0 && getRight(t) != NULL) {
			bstInsert(t->right, n);
		}
	}
}

bool isBst(bst t) {
	if (t != NULL) {
		if ((getParent(t) != NULL) &&
			((getLeft(getParent(t)) == t && getInf(t) > getInf(getParent(t))) ||
			 (getRight(getParent(t)) == t &&
			  getInf(t) < getInf(getParent(t))))) {
			return false;
		}

		return true && isBst(getLeft(t)) && isBst(getRight(t));
	}

	return true;
}

int main() {
	bst t = NULL;

	bstInsert(t, newNode(25));
	bstInsert(t, newNode(10));
	bstInsert(t, newNode(2));
	bstInsert(t, newNode(5));
	bstInsert(t, newNode(245));
	bstInsert(t, newNode(100));
	bstInsert(t, newNode(46));
	bstInsert(t, newNode(27));
	bstInsert(t, newNode(45));

	bnode* n = newNode(1);

	t->right->left->right = n;
	n->parent = t->right->left;

	cout << isBst(t) << endl;

	return 0;
}
