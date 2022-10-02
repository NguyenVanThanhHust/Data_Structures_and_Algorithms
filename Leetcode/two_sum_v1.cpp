/*
https://leetcode.com/problems/two-sum/
binary search appoarch
*/
#include <iostream>
#include <algorithm>
#include <vector> 
#include <array>


using namespace std;

int binary_search_index(vector<int> v, int start_index, int end_index, int value)
{
    if(start_index > end_index)
    {
        return -1;
    }
    int medium_index = (start_index + end_index) / 2;
    if(value == v[medium_index])
    {
        return medium_index;
    }
    else if(value > v[medium_index])
    {
        return binary_search_index(v, medium_index+1, end_index, value);
    }
    else
    {
        return binary_search_index(v, start_index, medium_index-1, value);
    }
    
};


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> sortedNums(nums);
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        sort(sortedNums.begin(), sortedNums.end());
        int vector_size = nums.size();
        for(int i=0; i<vector_size; i++)
        {
            cout<<sortedNums[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<vector_size; i++)
        {
            int to_find_value = target - nums.at(i);
            int index_found = binary_search_index(sortedNums, 0, vector_size -1, to_find_value);
            cout<<i<<" "<<nums.at(i)<<" "<<to_find_value<<" "<<index_found<<" "<<endl;
            // printAll(i, nums.at(i), to_find_value, value_found);
            if(index_found != -1)
            {
                int value_found = sortedNums.at(index_found);
                for(int j=0;j<vector_size;j++)
                {
                    if(j==i)
                        continue;
                    if(nums[j] == value_found)
                    {
                        vector<int> res;
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                }
            }
        }
        return res;
    }
};


int main()
{
    // vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    int arr[] = { 5, 75, 25};
    int target = 100;
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> vec;
    for(int i=0; i<n; i++)
    {
        vec.push_back(arr[i]);
        
    }
    
    Solution sol = Solution();
    vector<int> res = sol.twoSum(vec, target);
    for(vector<int>::iterator it = res.begin(); it!= res.end(); ++it)
    {
        cout<<*it<<" ";
    }
    return 0;
}