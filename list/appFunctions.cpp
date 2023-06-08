#include <iostream>

// clang-format off
#include "listType.h"
#include "lists.h"
#include "appFunctions.h"
// clang-format on

using namespace std;

list createList(int n) {
	if (n <= 0) {
		return NULL;
	}

	char url[50];

	list l = NULL;

	for (int i = 0; i < n; i++) {
		cout << "Insert URL: ";
		cin >> url;
		cout << endl;

		elem *e = newElem(url);

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