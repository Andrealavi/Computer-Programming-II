struct adjNode {
	int node;
	float weight;
	adjNode* next;
};

typedef adjNode* adjList;

struct graph {
	adjList* nodes;
	int dim;
};

graph newGraph(int);

void addArc(graph&, int, int, float);
void addEdge(graph&, int, int, float);

int getDim(graph);
adjList getAdjList(graph, int);
int getAdjNode(adjNode*);
adjList getNextAdj(adjList);
