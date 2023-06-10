#include <iostream>
#include <fstream>
#include <cfloat>

#include "graph.h"
#include "codap.h"

using namespace std;

graph gBuild(ifstream& file, bool d, bool w) {
	int dim;
	file >> dim;

	graph g = newGraph(dim);

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

int* dijkstra(graph g, int v) {
	float* dist = new float[g.dim];
	int* parents = new int[g.dim];

	for (int i = 0; i < g.dim; i++) {
		dist[i] = FLT_MAX;
		parents[i] = 0;
	}

	dist[v - 1] = 0;

	codap q = NULL;

	for (int i = 0; i < g.dim; i++) {
		q = enqueue(q, i + 1, dist[i]);
	}

	while (!isEmpty(q)) {
		int node = dequeue(q);

		adjList l = getAdjList(g, node);

		while (l != NULL) {
			if (dist[getAdjNode(l) - 1] > dist[node - 1] + getAdjWeight(l)) {
				parents[getAdjNode(l) - 1] = node;
				dist[getAdjNode(l) - 1] = dist[node - 1] + getAdjWeight(l);

				q = Decrease_Priority(q, getAdjNode(l),
									  dist[getAdjNode(l) - 1]);
			}

			l = getNextAdj(l);
		}
	}

	return parents;
}

int main(int argc, char* argv[]) {
	ifstream file(argv[1]);
	graph g = gBuild(file, atoi(argv[2]), atoi(argv[3]));

	int* parents = dijkstra(g, 1);

	for (int i = 0; i < g.dim; i++) {
		cout << parents[i] << endl;
	}

	return 0;
}