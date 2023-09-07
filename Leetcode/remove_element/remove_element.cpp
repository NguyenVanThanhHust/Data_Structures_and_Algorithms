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
    int removeElement(vector<int>& nums, int val)
    {
        priority_queue<int> non_val_indexes;
        priority_queue<int, vector<int>, greater<int>> val_indexes;
        int length = nums.size();
        vector<int> v_val_indexes;
        vector<int> v_non_val_indexes;
        for (int i = 0; i < length; i++)
        {
            if (nums[i] == val)
            {
                val_indexes.push(i);
                v_val_indexes.push_back(i);
            }
            else
            {
                non_val_indexes.push(i);
                v_non_val_indexes.push_back(i);
            }
        }

        if (val_indexes.size() == 0)
        {
            return nums.size();
        }
        if (non_val_indexes.size() == 0)
        {
            return 0;
        }
        int min_val_index = val_indexes.top();
        int max_non_val_index = non_val_indexes.top();

        while (min_val_index < max_non_val_index)
        {
            swap(nums[min_val_index], nums[max_non_val_index]);
            val_indexes.pop();
            val_indexes.push(max_non_val_index);
            non_val_indexes.pop();
            non_val_indexes.push(min_val_index);
            min_val_index = val_indexes.top();
            max_non_val_index = non_val_indexes.top();
        }
        return non_val_indexes.size();
    };
}
;

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
        int remove_value;
        cin >> remove_value;
        int res = s.removeElement(v, remove_value);
        int correct_res;
        cin >> correct_res;
        for (size_t k = 0; k < correct_res; k++)
        {
            cout << v[k] << " ";
        }
        cout << endl;
        if (correct_res == res)
        {
            cout << "correct" << endl;
        }
        else
        {
            cout << "incorrect" << endl;
            cout << "Expect: " << correct_res << " get: " << res << endl;
        }
    }
    return 0;
}
