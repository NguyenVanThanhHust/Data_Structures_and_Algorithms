// https://www.geeksforgeeks.org/union-find/
#include <iostream>
#include <queue>

using namespace std;

class Edge{
public:
	int src, dest;
};

class Graph {
public:
	// V: Number of vertices, E: Number of edges
	int V, E;

	// Graph is array of edges
	Edge* edge;
};

// Create graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[graph->E * sizeof(Edge)];
	return graph;
}

void addEdge(Graph *g, int src, int dst)
{
	g->edge[src].src = src;
	g->edge[src].dest = dst;
}

// Functio to find subset of an element i
int find_subset(int parent[], int i)
{
	if (parent[i] == i)
	{
		return i;
	}
	return find_subset(parent, parent[i]);
}

void union_2_subsets(int parent[], int x, int y)
{
	parent[x] = y;
}

int isCycle(Graph* graph)
{
	// Allocate memory for creating V subsets
	int *parent = new int[graph->V * sizeof(int)];
	
	// Initialize all subsets a single element sets
	memset(parent, 0, sizeof(int) * graph->V);


	// Iterrate all edge of graph, find the subset
	// of both bertices of every edge, if both subsets are same
	// then there is a cycle in graph
	for (int i = 0; i < graph->E; i++)
	{
		int x = find_subset(parent, graph->edge[i].src);
		int y = find_subset(parent, graph->edge[i].dest);
		if (x == y)
		{
			return 1;
		}
		union_2_subsets(parent, x, y);
	}
}

int main()
{
	int V = 3, E = 3;
	Graph* graph = createGraph(3, 3);

	addEdge(graph, 0, 1);
	addEdge(graph, 1, 2);
	addEdge(graph, 0, 2);

	if (isCycle(graph)) {
		cout << "Graph contains cycle. \n";
	}
	else {
		cout << "Graph doesn't contain cycle. \n";
	}
	return 0;
}