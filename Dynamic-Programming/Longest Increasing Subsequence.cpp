#include <math.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	int n; cin >> n;
	int *a = new int[n + 1];
	a[0] = -INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int LIS[100][100];
	for (int i = 0; i <= n; i++)
	{
		LIS[i][n + 1] = 0;
	}
	for (int j = n; j >= 1; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (a[i] >= a[j])
			{
				LIS[i][j] = LIS[i][j + 1];
			}
			else
			{
				LIS[i][j] = max(LIS[i][j + 1], 1 + LIS[j][j + 1]);
			}
		}
	}
	cout << LIS[0][1] << endl;
	return 0;
}