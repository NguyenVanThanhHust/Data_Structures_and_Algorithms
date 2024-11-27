#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using namespace std;

#define MAX_NUM 10000

template <typename T>
vector<int> sort_indexes(const vector<T> &v)
{
    // initailze origianl index locations
    vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values 
    stable_sort(idx.begin(), idx.end(), [&v](int i1, int i2) {return v[i1] < v[i2];});
    return idx;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> sorted_indexes = sort_indexes(nums);
    sort(nums.begin(), nums.end());

    int num_number = nums.size();
    int left=0, right = num_number-1;
    while (left < right)
    {
        if (nums[left]+nums[right]<target)
        {
            left++;
        }
        else if (nums[left]+nums[right]>target)
        {
            right--;
        }
        else
        {
            break;
        }
    }
    vector<int> res;
    res.push_back(sorted_indexes[left]);
    res.push_back(sorted_indexes[right]);
    return res;
}
int main()
{
    freopen("two_sum.txt", "r", stdin);
    int test_case;
    cin>>test_case;
    int array[MAX_NUM];
    for (int t = 0; t < test_case; t++)
    {
        int num_numbers;
        cin>>num_numbers;
        vector<int> nums;
        int a;
        for (int i = 0; i < num_numbers; i++)
        {
            cin>>a;
            nums.push_back(a);
        }
        int target;
        cin>>target;

        vector<int> res = twoSum(nums, target);
        cout<<"test case: "<<t<<" "<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}