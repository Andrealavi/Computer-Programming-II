#include <iostream>
#include <cstring>

using namespace std;

struct bnode {
	char key[50];
	bnode* left;
	bnode* right;
	bnode* parent;
};

typedef bnode* bst;

bnode* bstNewNode(char* key) {
	bnode* n = new bnode;

	strcpy(n->key, key);
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;

	return n;
}

char* getKey(bnode* n) { return n->key; }

bst getLeft(bnode* n) { return n->left; }

bst getRight(bnode* n) { return n->right; }

bnode* getParent(bnode* n) { return n->parent; }

void bstInsert(bst& t, bnode* n) {
	if (t == NULL) {
		t = n;
		return;
	} else {
		if (getLeft(t) == NULL && strcmp(getKey(n), getKey(t)) <= 0) {
			t->left = n;
			n->parent = t;
		} else if (getRight(t) == NULL && strcmp(getKey(n), getKey(t)) > 0) {
			t->right = n;
			n->parent = t;
		} else if (getLeft(t) != NULL && strcmp(getKey(n), getKey(t)) <= 0) {
			bstInsert(t->left, n);
		} else if (getRight(t) != NULL && strcmp(getKey(n), getKey(t)) > 0) {
			bstInsert(t->right, n);
		}
	}
}

bnode* bstSearch(bst t, char* key) {
	if (t == NULL) {
		return NULL;
	} else if (strcmp(getKey(t), key) == 0) {
		return t;
	} else if (strcmp(getKey(t), key) >= 0) {
		return bstSearch(getLeft(t), key);
	} else {
		return bstSearch(getRight(t), key);
	}
}

int main() {
	bst t = bstNewNode("ghar");

	bstInsert(t, bstNewNode("cacchio"));
	bstInsert(t, bstNewNode("mad"));
	bstInsert(t, bstNewNode("asdf"));
	bstInsert(t, bstNewNode("baccio"));

	cout << getKey(bstSearch(t, "asdf"));
}