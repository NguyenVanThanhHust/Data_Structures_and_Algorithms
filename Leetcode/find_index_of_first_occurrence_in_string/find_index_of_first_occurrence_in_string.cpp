// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle) {
        int needle_size = needle.size();
        int haystack_size = haystack.size();
        int first_occurence = -1;
        int p1 = 0, p2 = 0;
        while (p2 != haystack_size)
        {
            if (needle[p1] != haystack[p2])
            {
                p2++;
                continue;
            }
            bool match = true;
            for (int i = 0; i < needle_size; i++)
            {
                if (needle[p1+i] != haystack[p2 + i])
                {
                    match = false;
                    p2++;
                    break;
                }
            }
            if (match)
            {
                return p2;
            }
        }
        return -1;
    }
};

int main()
{
    freopen("find_index_of_first_occurrence_in_string.txt", "r", stdin);
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {
        std::string haystack;
        std::string needle;
        cin >> haystack >> needle;
        Solution s;
        int occ = s.strStr(haystack, needle);
        int res;
        cin >> res;
        if (occ != res)
        {
            cout << "wrong at: " << test_case << " expect: " << res << " get: " << occ << endl;
            break;
            return 0;
        }
    }
    cout << "pass" << endl;
    return 0;
}
