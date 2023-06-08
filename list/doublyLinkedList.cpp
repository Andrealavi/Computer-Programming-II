#include <cstring>
#include <iostream>

// clang-format off
#include "listType.h"
#include "lists.h"
#include "appFunctions.h"
// clang-format on

using namespace std;

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