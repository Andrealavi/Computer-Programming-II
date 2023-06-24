#include <iostream>
#include <fstream>
#include <cstring>

#include "type.h"
#include "list.h"
#include "word.h"

using namespace std;

word* load(int& dim) {
	ifstream file;
	file.open("./inverted");

	file >> dim;

	word* invertedIndex = new word[dim];

	for (int i = 0; i < dim; i++) {
		file >> invertedIndex[i].w;

		file >> invertedIndex[i].docOcc;

		invertedIndex[i].l = NULL;

		int id;

		for (int j = 0; j < invertedIndex[i].docOcc; j++) {
			file >> id;

			elem* e = newElem(id);

			invertedIndex[i].l = insertElem(invertedIndex[i].l, e);
		}
	}

	file.close();

	return invertedIndex;
}

void printIndex(word* invertedIndex, int dim) {
	for (int i = 0; i < dim; i++) {
		cout << invertedIndex[i].w << endl;
		list l = invertedIndex[i].l;

		while (l != NULL) {
			cout << head(l) << " ";
			l = tail(l);
		}

		cout << endl;
	}
}

void update(word*& invertedIndex, char* filename, int& n) {
	ifstream file(filename);

	int fileId;
	file >> fileId;

	while (file.peek() != EOF) {
		char w[80];

		file >> w;

		bool isEqual = false, isAlreadyPresent = false;

		for (int i = 0; i < n && !isEqual; i++) {
			isEqual = strcmp(w, invertedIndex[i].w) == 0;

			if (isEqual) {
				if (search(invertedIndex[i].l, fileId) == NULL) {
					invertedIndex[i].l =
						insertElem(invertedIndex[i].l, newElem(fileId));
				}

				isAlreadyPresent = true;
			}
		}

		if (!isAlreadyPresent) {
			word* newInvertedIndex = new word[n];

			for (int j = 0; j < n; j++) {
				strcpy(newInvertedIndex[j].w, invertedIndex[j].w);
				newInvertedIndex[j].docOcc = invertedIndex[j].docOcc;
				newInvertedIndex[j].l = invertedIndex[j].l;
			}

			strcpy(newInvertedIndex[n].w, w);
			newInvertedIndex[n].docOcc = 1;
			newInvertedIndex[n].l = NULL;

			newInvertedIndex[n].l =
				insertElem(newInvertedIndex[n].l, newElem(fileId));

			delete[] invertedIndex;

			n++;
			invertedIndex = newInvertedIndex;
		}
	}
}

void AND(word* invertedIndex, char* w1, char* w2, int n) {
	list occW1 = NULL, occW2 = NULL;

	bool isEqual = false;

	for (int i = 0; i < n; i++) {
		if (strcmp(w1, invertedIndex[i].w) == 0) {
			occW1 = invertedIndex[i].l;
		}

		if (strcmp(w1, invertedIndex[i].w) == 0) {
			occW2 = invertedIndex[i].l;
		}
	}

	while (occW1 != NULL) {
		list refOccW2 = occW2;

		while (refOccW2 != NULL) {
			if (compare(head(occW1), head(refOccW2)) == 0) {
				printInf(head(occW1));
				cout << endl;
			}

			refOccW2 = tail(refOccW2);
		}

		occW1 = tail(occW1);
	}
}

int main() {
	int dim;
	word* invertedIndex = load(dim);

	printIndex(invertedIndex, dim);

	update(invertedIndex, "doc", dim);

	cout << endl << endl;

	printIndex(invertedIndex, dim);

	cout << endl;

	AND(invertedIndex, "computer", "tower", dim);

	cout << endl;

	return 0;
}