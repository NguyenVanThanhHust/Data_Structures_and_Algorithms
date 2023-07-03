#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int test_case;
    cin>>test_case;
    for(int t=1; t<=test_case;t++)
    {
        int N;
        cin>>N;
        priority_queue<int> prize_to_get;
        stack<vector<int>> input_prize;
        for(int n=1; n<=N; n++)
        {
            int M, prize;
            cin>>M;
            vector<int> this_prize;
            for(int m=1;m<=M;m++)
            {
                cin>>prize;
                this_prize.push_back(prize);
            }
            input_prize.push(this_prize);
        }
        unsigned long long int total_prize=0;
        while(!input_prize.empty())
        {
            vector<int> last_prize = input_prize.top();
            for(auto each_prize: last_prize)
            {
                prize_to_get.push(each_prize);
            }
            input_prize.pop();
            unsigned long long int max_prize = static_cast<unsigned long long int>(prize_to_get.top());
            total_prize += max_prize;
            prize_to_get.pop();
        }
        cout<<"# "<<t<<" "<<total_prize<<endl;
    }
    return 0;
}