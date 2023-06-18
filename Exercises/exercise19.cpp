#include <iostream>
#include "coda-bfs.h"

using namespace std;

struct adjNode {
	int node;
	float weight;
	adjNode* next;
};

typedef adjNode* adjList;

struct graph {
	int dim;
	adjList* nodes;
};

int getDim(graph g) { return g.dim; };

adjList getAdjList(graph g, int n) { return g.nodes[n - 1]; }

int getAdjNode(adjList l) { return (l->node) + 1; }

adjList getNextAdj(adjList l) { return l->next; }

float getAdjWeight(adjNode* n) { return n->weight; };

void addArc(graph g, int u, int v, float weight) {
	adjNode* n = new adjNode;

	n->node = v - 1;
	n->next = g.nodes[u - 1];
	n->weight = weight;

	g.nodes[u - 1] = n;
}

void addEdge(graph g, int u, int v, float weight) {
	addArc(g, u, v, weight);
	addArc(g, v, u, weight);
}

bool evenPath(graph g, int x, int y) {
	codaBFS q = newQueue();

	q = enqueue(q, x);

	while (!isEmpty(q)) {
		int node = dequeue(q);

		adjList l = getAdjList(g, node);

		while (l != NULL) {
			if (getAdjNode(l) == y) {
				return true;
			}

			if (getAdjNode(l) % 2 == 0) {
				q = enqueue(q, getAdjNode(l));
			}

			l = getNextAdj(l);
		}
	}

	return false;
}

int main() {
	// Esempio di utilizzo
	graph g;
	g.dim = 6;
	g.nodes = new adjList[g.dim];

	// Inizializzazione nodi del grafo
	for (int i = 0; i < g.dim; i++) {
		g.nodes[i] = NULL;
	}

	// Aggiunta archi nel grafo
	adjNode* node1 = new adjNode;
	node1->node = 2;
	node1->weight = 0.5;
	node1->next = NULL;
	g.nodes[0] = node1;

	adjNode* node2 = new adjNode;
	node2->node = 3;
	node2->weight = 1.2;
	node2->next = NULL;
	g.nodes[1] = node2;

	adjNode* node3 = new adjNode;
	node3->node = 4;
	node3->weight = 2.1;
	node3->next = NULL;
	g.nodes[2] = node3;

	adjNode* node4 = new adjNode;
	node4->node = 5;
	node4->weight = 3.7;
	node4->next = NULL;
	g.nodes[3] = node4;

	adjNode* node5 = new adjNode;
	node5->node = 1;
	node5->weight = 0.9;
	node5->next = NULL;
	g.nodes[4] = node5;

	if (evenPath(g, 1, 4)) {
		cout << "Esiste un cammino da 1 a 6 con nodi pari" << endl;
	} else {
		cout << "Non esiste un cammino da 1 a 6 con nodi pari" << endl;
	}
}