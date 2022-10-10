///https://www.geeksforgeeks.org/find-paths-given-source-destination/
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
#include <sstream>
#include <map>


using namespace std;

class Graph
{
public:
    int V;

    vector<vector<int>> adj;

	Graph(int);
    void addEdge(int src, int dest);
    void findPath(int src, int dest);
    void findPathUtilts(int src, int dest, bool visited[], int path[], int path_index);
    void coutGraph();

private:
};

Graph::Graph(int V)
{
    this->V = V;
    for (size_t i = 0; i < V; i++)
    {
        vector<int> temp_vec;
        adj.push_back(temp_vec);
    }
};

void Graph::addEdge(int src, int dest)
{
    adj[src].push_back(dest);
}

void Graph::coutGraph()
{
    for (size_t i = 0; i < V; i++)
    {
        cout << " src: " << i << " connect to: ";
        for (vector<int>::iterator it = this->adj[i].begin(); it != this->adj[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}
void Graph::findPath(int src, int dest)
{
    cout << "find path" << endl;
    vector<vector<int>> paths;
    bool* visited = new bool[V];
    for (size_t i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    int* path = new int[V];
    int path_index = 0;

    findPathUtilts(src, dest, visited, path, path_index);
}


void Graph::findPathUtilts(int src, int dest, bool visited[], int path[], int path_index)
{
    visited[src] = true;
    cout << src << endl;

    path[path_index] = src;
    path_index++;
    if (src==dest)
    {
        for (size_t i = 0; i < path_index; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        vector<int>::iterator it;
        for (it = adj[src].begin(); it != adj[src].end(); ++it)
        {
            if (!visited[*it])
            {
                findPathUtilts(*it, dest, visited, path, path_index);
            }
        }
    }
    path_index--;
    visited[src] = false;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    //cin >> T;
    int test_case = 1;
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    //g.coutGraph();
    int s = 2, d = 3;
    cout << "Possible paths from src: " << s << " dest " << d << endl;
    g.findPath(s, d);

    return 0;
}

