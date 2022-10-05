//https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <string>
#include <utility>
#include <cassert>
#include <iomanip>
#include <set>
#include <stdio.h>

#include "logger/Logger.h"

using namespace std;


class Edge
{
public:
    int src, dest;
    int weight;
    Edge(int _src, int _dest, int _weight);
};

bool sort_by_weight(const Edge& a, const Edge& b)
{
    return a.weight < b.weight;

};

Edge::Edge(int _src, int _dest, int _weight)
{
    src = _src;
    dest = _dest;
    weight = _weight;
}



class Subset
{
public:
    int parent;
    int rank;
};

int findParent(class Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = findParent(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void union_2_subset(class Subset subsets[], int xroot, int yroot)
{
    // Attach smaller rank under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    // If ranks are the same, make one of them as root
    // and increase its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}



class Graph {
public:
    int V; // number of nodes
    int E;
    set<int> set_Nodes; 
    vector<vector<int>> adj;
    vector<Edge> vec_Edges;

    Graph(int v);
    
    void addEdge(int src, int dest, int weight);
    Graph findKruskalMST();
    void cout_graph();
};

Graph::Graph(int v)
{
    V = v;
    E = 0;
    for (size_t i = 0; i < V; i++)
    {   
        vector<int> start_vec;
        adj.push_back(start_vec);
    }
}

void Graph::addEdge(int src, int dest, int weight)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
    E++;
    Edge tmp_edge(src, dest, weight);
    vec_Edges.push_back(tmp_edge);
};

void Graph::cout_graph()
{
    for (int i = 0; i < E; i++)
    {
        cout << vec_Edges[i].src << " --" << vec_Edges[i].weight << "-->" << vec_Edges[i].dest << endl;
    }
    for (size_t i = 0; i < adj.size(); i++)
    {
        for (size_t j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
};

Graph Graph::findKruskalMST()
{
    sort(vec_Edges.begin(), vec_Edges.end(), sort_by_weight);

    // Create minimum spanning tree
    Graph mstGraph(this->V);

    // Create memory for creating V sets
    class Subset* subsets = new Subset[V * sizeof(Subset)];
    for (size_t v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int numEdge = this->E;
    for (size_t i = 0; i < E; i++)
    {
        Edge currentEdge = vec_Edges[i];
        int x = findParent(subsets, currentEdge.src);
        int y = findParent(subsets, currentEdge.dest);
        if (x == y)
        {
            continue;
        }
        mstGraph.addEdge(currentEdge.src, currentEdge.dest, currentEdge.weight);
        union_2_subset(subsets, x, y);
    }
    return mstGraph;
};

int isCycle(class Graph* graph)
{
    int V = graph->V;
    int E = graph->E;

    // Create memory for creating V sets
    class Subset* subsets = new Subset[V * sizeof(Subset)];
    for (size_t v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Iterate through all edges of graph, 
    // find sets of both vertices of every edge.
    for (size_t i = 0; i < E; i++)
    {
        int x = findParent(subsets, graph->vec_Edges[i].src);
        int y = findParent(subsets, graph->vec_Edges[i].dest);
        if (x==y)
        {
            return 1;
        }
        union_2_subset(subsets, x, y);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    CLogger::GetLogger()->Log("Start Program");
    /* 
    Let us create following weighted graph
                    10
               0--------1
               |  \     |
              6|   5\   |15
               |      \ |
               2--------3
                   4      
    */
    int V = 5, E = 5;

    class Graph graph = Graph(V);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2,6);
    graph.addEdge(2, 3,4);
    graph.addEdge(1, 3, 15);
    graph.addEdge(0, 3, 5);

    class Graph mstGraph = graph.findKruskalMST();
    mstGraph.cout_graph();
    return 0;
}

