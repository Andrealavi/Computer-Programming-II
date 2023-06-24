#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct elemBFS {
	int inf;
	elemBFS* pun;
};

typedef elemBFS* lista;

typedef struct {
	lista head;
	elemBFS* tail;
} codaBFS;

static elemBFS* new_elem(int n) {
	elemBFS* p = new elemBFS;
	p->inf = n;
	p->pun = NULL;
	return p;
}

codaBFS enqueue(codaBFS c, int i) {
	elemBFS* e = new_elem(i);
	if (c.tail != NULL) c.tail->pun = e;
	c.tail = e;
	if (c.head == NULL) c.head = c.tail;
	return c;
}

int dequeue(codaBFS& c) {
	int ris = (c.head)->inf;
	c.head = (c.head)->pun;
	return ris;
};

int first(codaBFS c) { return (c.head)->inf; };

bool isEmpty(codaBFS c) {
	if (c.head == NULL) return true;
	return false;
}

codaBFS newQueue() {
	codaBFS c = {NULL, NULL};
	return c;
}

struct adjNode {
	int node;
	float weight;
	adjNode* next;
};

typedef adjNode* adjList;

struct graph {
	adjList* nodes;
	char** names;
	int dim;
};

graph newGraph(int n) {
	graph g;

	g.dim = n;
	g.nodes = new adjList[n];
	g.names = new char*[n];

	return g;
}

void addArc(graph& g, int s, int d, float w) {
	adjNode* n = new adjNode;
	n->node = d - 1;
	n->next = g.nodes[s - 1];
	n->weight = w;

	g.nodes[s - 1] = n;
}

void addEdge(graph& g, int s, int d, float w) {
	addArc(g, s, d, w);
	addArc(g, d, s, w);
}

int getDim(graph g) { return g.dim; }

adjList getAdjList(graph g, int n) { return g.nodes[n - 1]; }

int getAdjNode(adjNode* n) { return (n->node) + 1; }

adjList getNextAdj(adjList l) { return l->next; }

float getAdjWeight(adjNode* l) { return (l->weight); }

graph gBuild(ifstream& file, bool d, bool w) {
	int dim;
	char input[50];

	file >> dim;

	graph g = newGraph(dim);

	for (int i = 0; i < dim; i++) {
		file >> input;

		g.names[i] = new char[50];
		strcpy(g.names[i], input);
	}

	while (file.peek() != EOF) {
		int u, v;
		float weight = 0;

		file >> u;
		file >> v;

		if (w) {
			file >> weight;
		}

		if (d) {
			addArc(g, u, v, w);
		} else {
			addEdge(g, u, v, w);
		}
	}

	file.close();

	return g;
}

bool isTherePath(graph g, int s, int d) {
	codaBFS q = newQueue();
	bool* visited = new bool[g.dim];

	for (int i = 0; i < g.dim; i++) {
		visited[i] = false;
	}

	q = enqueue(q, s);

	while (!isEmpty(q)) {
		int n = dequeue(q);

		adjList l = getAdjList(g, n);

		while (l != NULL) {
			if (!visited[getAdjNode(l) - 1]) {
				if (getAdjNode(l) == d) {
					return true;
				}

				q = enqueue(q, getAdjNode(l));
				visited[getAdjNode(l) - 1] = true;
			}

			l = getNextAdj(l);
		}
	}

	return false;
}

bool isTherePathTrough(graph g, int s, int d, char* street) {
	int streetNode;

	int i = 0;
	for (; strcmp(g.names[i], street) != 0; i++) {
	}
	i++;

	bool pathFromStoStreet = isTherePath(g, s, i);
	bool pathFromStreetToD = isTherePath(g, i, d);

	cout << pathFromStoStreet << endl;
	cout << pathFromStreetToD << endl;

	if (pathFromStoStreet && pathFromStreetToD) {
		return true;
	}

	return false;
}

int main() {
	ifstream file("./graph.txt");

	graph g = gBuild(file, true, true);

	cout << "Number of nodes: " << getDim(g) << endl;
	for (int i = 0; i < getDim(g); i++) {
		cout << "Node " << i + 1 << " name: " << g.names[i] << endl;
		adjList adj = getAdjList(g, i + 1);
		while (adj != nullptr) {
			cout << "Adjacent node: " << getAdjNode(adj) << endl;
			adj = getNextAdj(adj);
		}
		cout << endl;
	}

	cout << isTherePathTrough(g, 1, 4, "maria") << endl;

	return 0;
}