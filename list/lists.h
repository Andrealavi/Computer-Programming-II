struct elem {
	infType url;
	elem *next;
	elem *prev;
};

typedef elem *list;

infType head(list);

elem *newElem(infType);

elem *search(list, infType);

list tail(list l);

list prev(list l);

list insertElem(list, elem *);

list deleteElem(list, elem *);