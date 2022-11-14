/*
https://leetcode.com/problems/permutations/
*/
#include <iostream>
#include <algorithm>
#include <vector> 
#include <array>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<int>> all_res;
    int visited[7];
    vector<int> res;
    int n;
    vector<int> ori_nums;

    void backtrack(int k)
    {
        if(k > n)
        {
            // cout<<"current output: "<<endl;
            vector<int> current_res;
            for (int  i = 0; i < res.size(); i++)
            {
                // cout<<res[i]<<" ";
                current_res.push_back(res[i]);
            }
            all_res.push_back(current_res);
            return;
        }

        for(int i=1; i<=n; i++)
        {
            if(visited[i]==0)
            {
                visited[i] = 1;
                res.push_back(ori_nums[i-1]);
                backtrack(k+1);
                visited[i] = 0;
                res.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        ori_nums = nums;
        memset(visited, 0, sizeof(visited));
        backtrack(1);
        return all_res;
    }
};

int main()
{
    int num_test_case;
    freopen("local_test_case.txt", "r", stdin);
    cin>>num_test_case;
    for (int test_case = 0; test_case < num_test_case; test_case++)
    {
        int num_element;
        cin>>num_element;
        vector<int> current_array;
        int tmp_value;
        Solution sol = Solution();
        for (int ele_index = 0; ele_index < num_element; ele_index++)
        {
            cin>>tmp_value;
            current_array.push_back(tmp_value);
        }
        vector<vector<int>> res = sol.permute(current_array);
        cout<<endl;
        cout<<"Output: "<<endl;
        for (int vector_index = 0; vector_index < res.size(); vector_index++)
        {
            /* code */
            vector<int> current_vec = res[vector_index];
            for (int  element_index = 0; element_index < current_vec.size(); element_index++)
            {
                cout<<current_vec[element_index]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
