// Main idea is 

#include <string>
#include <filesystem>
#include <sstream>
#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <map>
#include <set>

using namespace std;

struct edge
{
	int src, dest;
};

#define MAX_ELEMENTS 10000
int visisted[MAX_ELEMENTS];

set<vector<int>> DFS(map<int, vector<int>> adj, int src, int dest)
{
	memset(visisted, 0, sizeof(visisted));
	stack<vector<int>> allPaths;
	set<vector<int>> resultPaths;
	stack<int> nodes;
	
	nodes.push(src);
	visisted[src] = 1;
	vector<int> current_path;
	current_path.push_back(src);

	allPaths.push(current_path);
	while (!nodes.empty())
	{
		int top = nodes.top();
		vector<int> pathToTop = allPaths.top();

		vector<int> topNeighbor = adj[top];
		allPaths.pop();
		nodes.pop();
		if (top == dest)
		{
			resultPaths.insert(pathToTop);
			visisted[top] = 0;
			continue;
		}
		for (auto eachNode: topNeighbor)
		{
			if (visisted[eachNode] == 1)
			{
				continue;
			}
			vector<int> tempPath = pathToTop;
			tempPath.push_back(eachNode);
			nodes.push(eachNode);
			allPaths.push(tempPath);
			visisted[eachNode] = 1;
		}
	}
	return resultPaths;
};

int main()
{
	string testFile = "AllPathSrc2Dst.txt";
	if (!std::filesystem::exists(testFile))
	{
		cout << "Can't find test case: " << testFile;
		return 1;
	}
	cout << "Start to test case: " << testFile << endl;
	freopen(testFile.c_str(), "r", stdin);

	int numTestCase;
	cin >> numTestCase;
	for (int t = 0; t < numTestCase; t++)
	{
		map<int, vector<int>> adj;
		int V, E;
		cin >> V >> E;
		int a, b;

		for (int numEdge = 0; numEdge < E; numEdge++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int src, dest;
		cin >> src >> dest;
		set<vector<int>> paths = DFS(adj, src, dest);
		set<vector<int>> correctPaths;

		int numPath;
		cin >> numPath;
		for (int pathIndex = 0; pathIndex < numPath; pathIndex++)
		{
			int numNodeInPath;
			cin >> numNodeInPath;
			vector<int> path;
			int node;
			for (int nodeIdx = 0; nodeIdx < numNodeInPath; nodeIdx++)
			{
				cin >> node;
				path.push_back(node);
			}
			correctPaths.insert(path);
		}

		if (correctPaths == paths)
		{
			cout << " Test case: " << t << " is passed" << endl;
		}
		else
		{
			cout << " Test case: " << t << " is failed" << endl;
			cout << "Expect:" << endl;
			for (auto path: correctPaths)
			{
				for (auto node: path)
				{
					cout << node << " ";
				}
				cout << endl;
			}
			cout << "Get:" << endl;
			for (auto path : paths)
			{
				for (auto node : path)
				{
					cout << node << " ";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
}