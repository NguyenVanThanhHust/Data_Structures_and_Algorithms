// Breath first search
#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> edge;

// Graph is defined as linked list format
// In here, it is vector of vectors of ints
// Graph is acyclic directed graph

class Graph 
{
	int V; // Number of vertices
	
	vector<vector<int>> graph;

public:
	Graph(int V);

	void addEdge(int v, int u);

	void breathFirstSearch(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	graph.resize(V);
};

void Graph::addEdge(int v, int u)
{
	graph[v].push_back(u);
	graph[u].push_back(v);
};

void Graph::breathFirstSearch(int s)
{
	queue<int> q;
	q.push(s);
	vector<bool> visited;
	visited.resize(V, false);
	while (!q.empty())
	{
		int value = q.front();
		cout << "vertex: " << q.front() << endl;
		q.pop();
		visited[value] = true;
		for (auto& element : graph[value]){
			if (!visited[element])
			{
				q.push(element);
				visited[element] = true;
			}
		}
	}
};

//int main()
//{
//	Graph g(9);
//	g.addEdge(0, 1);
//	g.addEdge(1, 3);
//	g.addEdge(1, 2);
//	g.addEdge(2, 6);
//	g.addEdge(2, 4);
//	g.addEdge(2, 5);
//	g.addEdge(4, 8);
//	g.addEdge(5, 7);
//	g.breathFirstSearch(2);
//	return 0;
//}
