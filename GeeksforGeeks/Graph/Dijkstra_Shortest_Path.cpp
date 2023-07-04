// ShotestPathDijstraPQ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

const int MAX_VERTEX = 100000;
const int MAX_DISTANCE = 1000000;

using namespace std;
struct edge {
    int dest;
    int cost;
};

struct visiting_vertex {
    int vertex;
    int travel_cost;
};

struct compare
{
    bool operator()(const visiting_vertex& e1, const visiting_vertex& e2)
    {
        return e1.travel_cost < e2.travel_cost;
    }
};

class Graph {
public:
    int V;
    vector<vector<edge>> adj;
    Graph(int V);
    int distances[MAX_VERTEX];
    
    void addEdge(int a, int b, int c);

    void shortestPath(int s);
};

Graph::Graph(int V)
{
    V = V;
    for (size_t i = 0; i < V; i++)
    {
        vector<edge> each_vertex_neighbor;
        adj.push_back(each_vertex_neighbor);
        distances[i] = 1000000;
    }
}

void Graph::addEdge(int a, int b, int c)
{
    adj[a].push_back({ b, c });
    adj[b].push_back({ a, c });
}

void Graph::shortestPath(int s)
{
    // Initialize the priority queue for finding shortest path
    priority_queue<visiting_vertex, vector<visiting_vertex>, compare> pq;
    pq.push({ 0, s });
    distances[s] = 0;
    while (!pq.empty())
    {
        visiting_vertex current_vertex = pq.top();
        pq.pop();
        int vertex = current_vertex.vertex;
        for (auto neighbor : adj[vertex])
        {
            if (distances[neighbor.dest] > distances[current_vertex.vertex] + neighbor.cost)
            {
                distances[neighbor.dest] = distances[current_vertex.vertex] + neighbor.cost;
                pq.push({ neighbor.dest, distances[neighbor.dest] });
            }
        }
    }
    for (size_t i = 0; i < 9; i++)
    {
        cout << "Short path from s: " << s << " to v: " << i << " is: " << distances[i] << endl;
    }

};

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.shortestPath(0);

    return 0;
}

