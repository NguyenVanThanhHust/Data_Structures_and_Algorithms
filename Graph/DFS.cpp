//// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <string>
//#include <filesystem>
//#include <sstream>
//#include <iostream>
//#include <vector>
//#include <array>
//#include <stack>
//#include <map>
//
//using namespace std;
//
//struct edge
//{
//	int src, dest;
//};
//#define MAX_ELEMENTS 10000
//int visisted[MAX_ELEMENTS];
//
//vector<int> DFS(map<int, vector<int>> adj, int src, int dest)
//{
//	memset(visisted, 0, sizeof(visisted));
//	vector<int> path;
//	stack<int> neighbors;
//	neighbors.push(src);
//	while (!neighbors.empty())
//	{
//		int top = neighbors.top();
//		neighbors.pop();
//		visisted[top] = 1;
//		path.push_back(top);
//		if (top == dest)
//		{
//			break;
//		}
//		
//		for (auto v : adj[top])
//		{
//			if (visisted[v] == 0)
//			{
//				neighbors.push(v);
//			}
//		}
//	}
//	return path;
//};
//
//int main()
//{
//	string testFile = "DFS.txt";
//	if (!std::filesystem::exists(testFile))
//	{
//		cout << "Can't find test case: " << testFile;
//		return 1;
//	}
//	cout << "Start to test case: " << testFile << endl;
//	freopen(testFile.c_str(), "r", stdin);
//
//	int numTestCase;
//	cin >> numTestCase;
//	for (int t = 0; t < numTestCase; t++)
//	{
//		map<int, vector<int>> adj;
//		int V, E;
//		cin >> V >> E;
//		int a, b;
//
//		for (int numEdge = 0; numEdge < E; numEdge++)
//		{
//			cin >> a >> b;
//			adj[a].push_back(b);
//			adj[b].push_back(a);
//		}
//
//		int src, dest;
//		cin >> src >> dest;
//		vector<int> path = DFS(adj, src, dest);
//		for (auto v: path)
//		{
//			cout << v << " ";
//		}
//		cout << endl;
//	}
//}
//
