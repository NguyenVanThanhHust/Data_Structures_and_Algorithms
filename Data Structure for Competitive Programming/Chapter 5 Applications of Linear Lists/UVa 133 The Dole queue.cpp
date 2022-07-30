#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int N, k, m;
    cin >> N >> k >> m;
    while (N||k||m)
    {
        int left_index = 0, right_index = 0;
        int left_choice = 0, right_choice = 0;

        std::vector<int> lines;
        for (size_t i = 0; i < N; i++)
        {
            lines.push_back(i+1);
        }
        
        while (!lines.empty())
        {
            left_choice = (left_index + k -1)%lines.size();
            right_choice = (right_index - m + 1)%lines.size();

            while (right_choice < 0)
            {
                right_choice += lines.size();
            }
            if(left_choice == right_choice)
            {
                left_index = left_choice;
                right_index = right_choice - 1;
                lines.erase(lines.begin() + left_choice);
            }
            else if(left_choice > right_choice)
            {
                left_index = left_choice - 1;
                right_index = right_choice - 1;

                lines.erase(lines.begin() + left_choice);
                lines.erase(lines.begin() + right_choice);
            }
            else
            {
                right_index = right_choice - 2;
                left_index = left_choice;

                lines.erase(lines.begin() + right_choice);
                lines.erase(lines.begin() + left_choice);
            }
        }
    }
    return 0;
}
