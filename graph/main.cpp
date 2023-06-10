#include <iostream>
#include <fstream>

#include "graph.h"
#include "coda-bfs.h"

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

void iterativeBFS(graph g, int v) {
	bool* visited = new bool[g.dim];

	for (int i = 0; i < g.dim; i++) {
		visited[i] = false;
	}

	codaBFS q = newQueue();

	q = enqueue(q, v);

	visited[v - 1] = true;

	while (!isEmpty(q)) {
		int n = dequeue(q);

		adjList l = getAdjList(g, n);

		while (l != NULL) {
			if (!visited[getAdjNode(l) - 1]) {
				cout << getAdjNode(l) << endl;

				visited[getAdjNode(l) - 1] = true;

				q = enqueue(q, getAdjNode(l));
			}

			l = getNextAdj(l);
		}
	}
}

int main(int argc, char* argv[]) {
	ifstream file;

	file.open(argv[1]);

	graph g = gBuild(file, atoi(argv[2]), atoi(argv[3]));

	iterativeBFS(g, 1);

	return 0;
}