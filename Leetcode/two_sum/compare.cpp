/*
https://leetcode.com/problems/two-sum/
*/
#include <iostream>
#include <algorithm>
#include <vector> 
#include <array>
#include <fstream>
#include <cstdlib>
#include <random>
#include <iterator>
#include <iostream>
#include <string> 

using namespace std;


int main()
{

    freopen("brute_force_result.txt", "r", stdin);
    int test_case;
    cin>>test_case;
    vector<vector<int>> brute_force_res;
    for (size_t i = 0; i < test_case; i++)
    {
        int a, b;
        cin>>a>>b;
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        brute_force_res.push_back(vec);   
    }

    freopen("binary_search.txt", "r", stdin);
    int test_case;
    cin>>test_case;
    vector<vector<int>> binary_search_res;
    for (size_t i = 0; i < test_case; i++)
    {
        int a, b;
        cin>>a>>b;
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        binary_search_res.push_back(vec);   
    }

    
    return 0;
}