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

using namespace std;


int main()
{
    freopen("test_case.txt", "w", stdout);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(-1000, 1000);

    int num_test_case = 100;
    int num_elements = 2;
    cout<<num_test_case<<endl;
    for(int i=0; i<num_test_case; i++)
    {
        int num_sample = 100;
        vector<int> test_case_vec;
        // Create 100 sample to find value
        for(int j=0; j<num_sample; j++)
        {
            int random_value = distr(gen);
            test_case_vec.push_back(random_value);
        }

        // Ranomly choose 2 of them to sum to target
        int target = 0;
        uniform_int_distribution<int> indexes(1, num_sample);
        for(int k=0; k<2;k++)
        {
            int index = indexes(gen);
            target+=test_case_vec[index];
        }

        cout<<num_sample<<" "<<target<<" ";
        for(int k =0; k<num_sample+1; k++)
        {
            cout<<test_case_vec[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}