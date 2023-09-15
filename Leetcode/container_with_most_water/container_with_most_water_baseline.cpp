#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int current_right_pt = height.size() - 1;
        int current_left_pt = 0;
        int maxArea = min(height[current_left_pt], height[current_right_pt]) * (current_right_pt - current_left_pt);
        if (length == 2)
        {
            return maxArea;
        }

        // Run for current_right_pt
        for (int right_pt = length - 1; right_pt > current_left_pt; right_pt--) {
            if (height[right_pt] <= height[current_right_pt]) {
                continue;
            }
            int thisArea = min(height[right_pt], height[current_left_pt]) * (right_pt - current_left_pt);
            if (thisArea > maxArea)
            {
                maxArea = thisArea;
                current_right_pt = right_pt;
            }
        }

        for (int left_pt = 1; left_pt < length - 1; left_pt++) {
            if (height[left_pt] < height[current_left_pt])
            {
                continue;
            }
            for (int right_pt = length - 1; right_pt > left_pt; right_pt--) {
                if (height[right_pt] < height[current_right_pt]) {
                    continue;
                }
                int thisArea = min(height[left_pt], height[right_pt]) * (right_pt - left_pt);
                if (thisArea > maxArea)
                {
                    maxArea = thisArea;
                    current_right_pt = right_pt;
                    current_left_pt = left_pt;
                }
            }
        }
        cout << current_left_pt << "--" << current_right_pt << endl;
        return maxArea;
    };
};

int main()
{
   freopen("input.txt", "r", stdin);
   int test_case;
   cin >> test_case;
   Solution s;
   for (int i = 0; i < test_case; i++)
   {
       int vector_size;
       cin >> vector_size;
       vector<int> v;
       int vector_val;
       for (int j = 0; j < vector_size; j++)
       {
           cin >> vector_val;
           v.push_back(vector_val);
       }
       int res = s.maxArea(v);
       int correct_res;
       cin >> correct_res;
       if (correct_res == res)
       {
           cout << "case: " << i << " correct" << endl;
       }
       else
       {
           cout << "case: " << i;
           cout << "incorrect ";
           cout << "Expect: " << correct_res << " get: " << res << endl;
       }
   }
   return 0;
}
