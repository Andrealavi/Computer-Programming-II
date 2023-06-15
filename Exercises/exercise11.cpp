#include <iostream>

using namespace std;

struct player {
	int id;
	float score;
};

struct elem {
	player inf;
	elem* next;
};

typedef elem* list;

player head(list l) { return l->inf; }
list tail(list l) { return l->next; }

elem* newPlayer(int id, float score) {
	elem* e = new elem;

	(e->inf).id = id;
	(e->inf).score = score;

	return e;
}

bool compare(float a, float b) { return a <= b; }

void printList(list l) {
	while (l != NULL) {
		cout << "Player: " << head(l).id << endl;
		cout << "Score: " << head(l).score << endl;

		l = tail(l);

		cout << endl;
	}
}

list insertElem(list l, elem* e) {
	if (l != NULL) {
		e->next = l;
	}

	return e;
}

list createList(int n) {
	list l = NULL;

	int id;
	float score;

	for (int i = 0; i < n; i++) {
		cout << "Insert player id: ";
		cin >> id;
		cout << endl;

		cout << "Insert player score: ";
		cin >> score;
		cout << endl;

		elem* e = newPlayer(id, score);

		l = insertElem(l, e);
	}

	return l;
}

list selectByScore(list l, float checkScore, bool (*compare)(float, float)) {
	list filteredList = NULL;

	while (l != NULL) {
		if (compare(head(l).score, checkScore)) {
			elem* e = newPlayer(head(l).id, head(l).score);

			filteredList = insertElem(filteredList, e);
		}

		l = tail(l);
	}

	return filteredList;
}

int main() {
	list l = createList(10);

	printList(l);

	cout << endl;

	l = selectByScore(l, 50, compare);

	cout << endl;

	printList(l);
}