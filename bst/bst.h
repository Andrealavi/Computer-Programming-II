struct bnode {
	keyType key;
	infType inf;
	bnode* left;
	bnode* right;
	bnode* parent;
};

typedef bnode* bst;

bnode* bstNewNode(infType, keyType);
keyType getKey(bnode*);
infType getValue(bnode*);

bst getLeft(bst);
bst getRight(bst);
bnode* getParent(bnode*);

void bstInsert(bst&, bnode*);
void bstDelete(bst&, bnode*);
void bst_delete(bst&, bnode*);

bnode* bstSearch(bst, keyType);
