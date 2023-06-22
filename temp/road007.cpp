#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdarg>

using namespace std;

const int MAX_CAPACITY=10000;
int parents[MAX_CAPACITY];

struct road {
	int s, e, c;
};

int find_set(int v)
{
	if (parents[v] == v)
	{
		return v;
	}
	return parents[v] = find_set(parents[v]);
};


void union_set(int u, int v)
{
	int par_u = find_set(u);
	int par_v = find_set(v);
	if (par_v != par_u)
	{
		parents[u] = par_v;
	}
}
bool compare_road(const road& r1, const road& r2)
{
	return r1.c < r2.c;
};

int main()
{
	int test_case;
	cin >> test_case;
	for (size_t t = 0; t < test_case; t++)
	{
		int N, M;
		cin >> N >> M;
		vector<road> roads;
		for (size_t n = 1; n <= N; n++)
		{
			parents[n] = n;
		}

		for (size_t m = 0; m < M; m++)
		{
			road new_road;
			cin >> new_road.s >> new_road.e >> new_road.c;
			roads.push_back(new_road);
		}

		sort(roads.begin(), roads.end(), compare_road);
		int total_cost = 0;
		int num_roads = roads.size();
		for (int road_index = 0; road_index < num_roads; road_index++)
		{
			road each_road = roads[road_index];
			int s = each_road.s;
			int e = each_road.e;
			int par_s = find_set(s);
			int par_e = find_set(e);
			if (par_s != par_e)
			{
				union_set(s, e);
				total_cost += each_road.c;
			}

		}
		cout << "# " << t + 1 << " " << total_cost << endl;
	}
	return 0;
}