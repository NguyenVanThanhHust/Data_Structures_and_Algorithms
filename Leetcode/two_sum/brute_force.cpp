/*
https://leetcode.com/problems/two-sum/
*/
#include <iostream>
#include <algorithm>
#include <vector> 
#include <array>


using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    res.push_back(-1);
    res.push_back(-1);
    int num_numbers = nums.size();
    for (size_t i = 0; i < num_numbers; i++)
    {
        int value = nums[i];
        for (size_t j = 0; j < num_numbers; j++)
        {
            if (i==j)
            {
                continue;
            }
            if ((nums[j] + nums[i]) == target)
            {
                vector<int> res;
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
    };
};

int main()
{
    freopen("test_case.txt", "r", stdin);
    freopen("brute_force.txt", "w", stdout);
    int test_case;
    cin>>test_case;
    cout<<test_case;
    cout<<endl;
    for (size_t test_case_index = 0; test_case_index < test_case; test_case_index++)
    {
        int num_sample;
        int target;
        cin>>num_sample;
        cin>>target;

        int value;
        vector<int> vec;
        for (size_t i = 0; i < num_sample; i++)
        {
            cin>>value;
            vec.push_back(value);
        }
        
        Solution sol = Solution();
        vector<int> res = sol.twoSum(vec, target);
        for(vector<int>::iterator it = res.begin(); it!= res.end(); ++it)
        {
            cout<<*it<<" ";
        }   
    }
    return 0;

}