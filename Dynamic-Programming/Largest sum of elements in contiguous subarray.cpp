#include <math.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	vector<vector<double>> a;
	int n; cin >> n;
	double k;
	vector<double> tv;
	int max = 0, ib = 0, ie = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		tv.push_back(k);
	}
	a.push_back(tv);
	for (int i = 1; i < n; i++)
	{
		vector<double> tv2;
		for (int j = 0; j < n - i; j++)
		{
			double g = a[i - 1][j] + a[0][j + i];
			if (max < g)
			{
				max = g;
				ib = j;
				ie = i + 1;
			}
			tv2.push_back(g);
		}
		a.push_back(tv2);
	}
	cout << max << " " << ib << " " << ie;
	return 0;
}