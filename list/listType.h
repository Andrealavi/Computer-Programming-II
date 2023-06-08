struct elem {
	char url[50];
	elem *next;
	elem *prev;
};

typedef elem *list;

char *head(list);

elem *newElem(char *);

elem *search(list, char *);