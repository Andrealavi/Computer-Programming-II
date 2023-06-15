#include <iostream>

using namespace std;

struct list_t {
	int elem;
	list_t *next;
};

typedef list_t *list;

void printList(list &l) {
	if (l != NULL) {
		cout << l->elem << endl;
		printList(l->next);
	}
}

void insertElem(list &l) {
	list_t *e = new list_t;
	int n;

	cout << "Insert number: ";
	cin >> n;
	cout << endl;

	e->elem = n;

	if (l != NULL) {
		e->next = l;
	}

	l = e;
}

void deleteElem(list &l) {
	list_t *e = l;
	l = l->next;

	delete e;
}

void emptyList(list &l) {
	if (l != NULL) {
		deleteElem(l);
		emptyList(l);
	}
}

void deleteFirstElem(list) {}

int main(int argc, char *argv[]) {
	void (*funPnt[4])(list &) = {printList, insertElem, deleteElem, emptyList};
	int options = 4;
	list l = NULL;
	char choice;

	while (!cin.eof()) {
		cout << endl << "scegliere azione:" << endl;
		cout << "a) stampare la lista" << endl;
		cout << "b) inserire un nuovo numero all'inizio della lista" << endl;
		cout << endl;
		cout << "c) rimuovere il primo numero della lista" << endl;
		cout << "d) svuotare la lista" << endl;
		cout << endl;
		cout << "(o premere Ctrl+D per uscire)" << endl;

		cin >> choice;

		if (choice >= 'a' && choice < 'a' + options) {
			funPnt[choice - 'a'](l);
		} else if (choice != '\0')
			cerr << "opzione non riconosciuta" << endl;
	}
}