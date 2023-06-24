struct node {
	infType inf;
	node* parent;
	node* firstChild;
	node* nextSibling;
};

typedef node* tree;

infType getInfo(node*);
node* getParent(node*);
node* getFirstChild(node*);
node* getNextSibling(node*);

node* newNode(infType);
void insertChild(tree, tree);
void insertSibling(node*, tree);
void deleteNode(tree&, node*);
node* search(tree, infType);