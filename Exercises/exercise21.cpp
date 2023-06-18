#include <iostream>

using namespace std;

int compareKey(int k1, int k2) { return k1 - k2; }

struct bnode {
	int key;
	bnode* left;
	bnode* right;
	bnode* parent;
};

typedef bnode* bst;

bnode* bstNewNode(int key) {
	bnode* n = new bnode;

	n->key = key;

	n->left = n->right = n->parent = NULL;

	return n;
}

int getKey(bnode* n) { return n->key; }

bst getLeft(bst t) { return t->left; }

bst getRight(bst t) { return t->right; }

bnode* getParent(bnode* n) { return n->parent; }

void bstInsert(bst& t, bnode* n) {
	if (t == NULL) {
		t = n;
		return;
	} else {
		if (getLeft(t) == NULL && compareKey(getKey(n), getKey(t)) <= 0) {
			t->left = n;
			n->parent = t;
		} else if (getRight(t) == NULL &&
				   compareKey(getKey(n), getKey(t)) > 0) {
			t->right = n;
			n->parent = t;
		} else if (getLeft(t) != NULL &&
				   compareKey(getKey(n), getKey(t)) <= 0) {
			bstInsert(t->left, n);
		} else if (getRight(t) != NULL &&
				   compareKey(getKey(n), getKey(t)) > 0) {
			bstInsert(t->right, n);
		}
	}
}

bnode* bstSearch(bst t, int k) {
	if (t == NULL) {
		return NULL;
	} else {
		if (compareKey(k, getKey(t)) == 0) {
			return t;
		} else if (compareKey(k, getKey(t)) < 0) {
			return bstSearch(getLeft(t), k);
		} else if (compareKey(k, getKey(t)) > 0) {
			return bstSearch(getRight(t), k);
		}
	}

	return NULL;
}

void printSubtree(bst t, int x, int y) {
	if (t != NULL) {
		if (t->parent == NULL) {
			t = bstSearch(t, x);
		}

		if (getKey(t) < y) {
			cout << getKey(t) << endl;
		}

		if (getKey(t) >= y) {
			printSubtree(getLeft(t), x, y);
		} else {
			printSubtree(getLeft(t), x, y);
			printSubtree(getRight(t), x, y);
		}
	}
}

int main() {
	bst t = bstNewNode(6);

	bstInsert(t, bstNewNode(15));
	bstInsert(t, bstNewNode(3));
	bstInsert(t, bstNewNode(2));
	bstInsert(t, bstNewNode(10));
	bstInsert(t, bstNewNode(12));
	bstInsert(t, bstNewNode(11));
	bstInsert(t, bstNewNode(8));
	bstInsert(t, bstNewNode(7));
	bstInsert(t, bstNewNode(9));

	printSubtree(t, 6, 10);

	return 0;
}