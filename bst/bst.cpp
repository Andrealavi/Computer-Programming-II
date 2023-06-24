#include "key.h"
#include "string.h"
#include "bst.h"

#include <iostream>

using namespace std;

bnode* bstNewNode(infType inf, keyType key) {
	bnode* n = new bnode;

	copy(n->key, key);
	copy(n->inf, inf);

	n->left = n->right = n->parent = NULL;

	return n;
}

keyType getKey(bnode* n) { return n->key; }

infType getValue(bnode* n) { return n->inf; }

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

bnode* bstSearch(bst t, keyType k) {
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

bool isLeftChild(bst t, bnode* n) {
	if (getLeft(t) == n) {
		return true;
	}

	return false;
}

bnode* getNextSuccessor(bst t) {
	if (getRight(t) == NULL) {
		return t;
	}

	t = getRight(t);

	while (getLeft(t) != NULL) {
		t = getLeft(t);
	}

	return t;
}

void bstDelete(bst& t, bnode* n) {
	bnode* newChild;

	if (getLeft(n) == NULL) {
		if (getRight(n) == NULL) {
			newChild = NULL;
		} else {
			newChild = getRight(n);
		}
	} else if (getRight(n) == NULL) {
		newChild = getLeft(n);
	}

	else {
		bnode* app = getLeft(n);

		while (getRight(app) != NULL) {
			app = getRight(app);
		}

		if (getLeft(app) == NULL) {
			app->parent->right = NULL;
		} else {
			app->parent->right = getLeft(app);
			app->left->parent = getParent(app);
		}

		app->left = getLeft(n);
		app->right = getRight(n);

		if (getLeft(app) != NULL) {
			app->right->parent = app;
		}
		if (getLeft(app) != NULL) {
			app->left->parent = app;
		}

		newChild = app;
	}

	if (newChild != NULL) {
		newChild->parent = getParent(n);
	}

	if (n == t) {
		t = newChild;
	} else {
		n == getLeft(getParent(n)) ? n->parent->left = newChild
								   : n->parent->right = newChild;
	}

	delete n;
}

void update_father(bnode* p, bnode* q) {
	if (p == getLeft(getParent(p)))
		(p->parent)->left = q;
	else
		(p->parent)->right = q;
}

void bst_delete(bst& b, bnode* n) {
	bnode* new_child;  // variabile d'appoggio che individua il nodo da sostuire
					   // a n come figlio
	if (getLeft(n) == NULL) {
		if (getRight(n) == NULL)  // Nodo foglia
			new_child = NULL;
		else {
			cout << "Nodo con solo figlio destro\n";  // Solo figlio destro
			new_child = getRight(n);
		}
	} else if (getRight(n) == NULL) {  // Solo figlio sinistro
		cout << "Nodo con solo figlio sinistro\n";
		new_child = getLeft(n);

	} else {  // Entrambi i figli: cerco l'elemento più grande nel sottoalbero
			  // di sx
		cout << "Nodo con entrambi i figli\n";
		bnode* app = getLeft(n);
		while (getRight(app) !=
			   NULL)  // cerco l'elemento più a destra nel sottoalbero di sx
			app = getRight(app);
		if (getLeft(app) == NULL) {	 // app è una foglia
			update_father(app, NULL);
		} else {  // app ha il figlio sinistro
			(app->parent)->right = getLeft(app);
			(app->left)->parent = getParent(app);
		}
		// sostituisco app a n
		app->left = getLeft(n);
		app->right = getRight(n);
		if (getLeft(app) != NULL) (app->right)->parent = app;
		if (getLeft(app) != NULL) (app->left)->parent = app;
		new_child = app;
	}
	if (new_child != NULL) new_child->parent = getParent(n);
	if (n == b)	 // n è la radice
		b = new_child;
	else
		update_father(n, new_child);
	delete n;
}