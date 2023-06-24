struct elem {
	infType id;
	elem* next;
};

typedef elem* list;

infType head(list);
list tail(list);

elem* newElem(infType);

list insertElem(list, elem*);
list deleteElem(list, elem*);
elem* search(list, infType);
