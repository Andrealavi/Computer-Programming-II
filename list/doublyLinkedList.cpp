#include <iostream>

using namespace std;

struct elem {
	char url[50];
	elem *next;
	elem *prev;
};

typedef elem *list;

char *head(list l) { return l->url; }

list tail(list l) { return l->next; }

list prev(list l) { return l->prev; }

list insertElem(list l, elem *e) {
	if (l != NULL) {
		l->prev = e;
	}

	e->next = l;
	e->prev = NULL;

	return e;
}

list deleteElem(list l, elem *e) {
	if (e == NULL) {
		return l;
	}

	if (l == e) {
		l = tail(l);
		delete e;

		return l;
	} else {
		e->next->prev = prev(e);
		e->prev->next = tail(e);
	}
	return l;
}

list createList(int n) {
	if (n <= 0) {
		return NULL;
	}

	list l = new elem;

	cout << "Insert URL: ";
	cin >> l->url;
	cout << endl;

	l->next = l->prev = NULL;

	for (int i = 1; i < n; i++) {
		elem *e = new elem;

		cout << "Insert URL: ";
		cin >> e->url;
		cout << endl;

		e->next = e->prev = NULL;

		l = insertElem(l, e);
	}

	return l;
}

void deleteList(list l) {
	while (l != NULL) {
		l = deleteElem(l, l);
	}
}

void printList(list l) {
	while (l != NULL) {
		cout << head(l) << endl;

		l = tail(l);
	}
}

elem *search(list l, char *url) {
	while (l != NULL) {
		if (strcmp(head(l), url) == 0) {
			return l;
		} else {
			l = tail(l);
		}
	}

	return NULL;
}

void navigateList(list l, char *url) {
	elem *e = search(l, url);
	char choice;

	if (e == NULL) {
		cout << "Element not found" << endl;

		return;
	} else {
		do {
			cout << "Selected URL: " << head(e) << endl;

			cout << "f)\t Forward\n";
			cout << "b)\t Back\n";
			cout << "e)\t Exit navigation\n";

			cout << "Choose what you want to do: ";
			cin >> choice;
			cout << endl;

			switch (choice) {
				case 'f':
					if (tail(e) != NULL) {
						e = tail(e);
					} else {
						cout << "You've reached the end of the list" << endl;
					}
					break;
				case 'b':
					if (prev(e) != NULL) {
						e = prev(e);
					} else {
						cout << "You've reached the beginning of the list"
							 << endl;
					}
				default:
					break;
			}

			cout << endl;
		} while (choice != 'e');
	}
}

int main() {
	int choice, n;
	char url[50];
	list l;

	do {
		cout << "1)\t Create URLs list\n";
		cout << "2)\t Delete URL from list\n";
		cout << "3)\t Print list\n";
		cout << "4)\t Scan URL list starting from a specific URL\n";
		cout << "5)\t Exit\n";

		cout << endl;

		cout << "Insert your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 1:
				cout << "Insert list dimension: ";
				cin >> n;
				cout << endl;

				l = createList(n);
				break;
			case 2:
				cout << "Insert the url you want to delete: ";
				cin >> url;
				cout << endl;

				l = deleteElem(l, search(l, url));
				break;
			case 3:
				printList(l);
				break;
			case 4:
				cout << "Insert the url you want to delete: ";
				cin >> url;
				cout << endl;

				navigateList(l, url);
				break;
			case 5:
				return 0;
			default:
				break;
		}

		cout << endl;
	} while (choice);
}