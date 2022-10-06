// https://www.geeksforgeeks.org/minimum-sum-path-triangle/
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
#include <stdio.h>

using namespace std;

int getMinSum(vector<vector<int>>& triangle)
{
    int num_level = triangle.size();
    vector<vector<int>> min_triangle;
    for (size_t i = 0; i < num_level; i++)
    {
        vector<int> v;
        v.reserve(num_level + 1);
        min_triangle.push_back(v);
    }
    // Loop from the top to bottom of triangle
    for (int level_index = 0; level_index < num_level; level_index++)
    {
        int num_var_in_this_level = triangle[level_index].size();
        if (level_index == 0)
        {
            min_triangle[level_index].push_back(triangle[level_index][0]);
            continue;
        }
        for (int var_index = 0; var_index < num_var_in_this_level; var_index++)
        {
            if (var_index == 0)
            {
                min_triangle[level_index].push_back(triangle[level_index][var_index] + min_triangle[level_index-1][var_index]);
                continue;
            }
            if (var_index == num_var_in_this_level-1)
            {
                min_triangle[level_index].push_back(triangle[level_index][var_index] + min_triangle[level_index - 1][var_index - 1]);
                continue;
            }
            min_triangle[level_index].push_back(triangle[level_index][var_index] + min(min_triangle[level_index - 1][var_index - 1], min_triangle[level_index - 1][var_index]));
        }

        cout << endl;
    }

    int min_value = *min_element(min_triangle[num_level - 1].begin(), min_triangle[num_level - 1].end());
    return min_value;
}
int main()
{
    ios_base::sync_with_stdio(false);
    vector<vector<int> > A{ { 2 },
                            { 3, 7 },
                            { 8, 5, 6 },
                            { 6, 1, 9, 3 },
                            };

    int min_sum = getMinSum(A);
    cout << "Min sum " << min_sum << endl;
    return 0;
}

