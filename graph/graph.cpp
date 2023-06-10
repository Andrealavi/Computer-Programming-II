#include "graph.h"

graph newGraph(int n) {
	graph g;

	g.dim = n;
	g.nodes = new adjList[n];

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
