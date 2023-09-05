// Leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        string res;
        string::iterator it1 = word1.begin();
        string::iterator it2 = word2.begin();
        while (it1 != word1.end() || it2 != word2.end())
        {
            if (it1 == word1.end())
            {
                while (it2 != word2.end())
                {
                    res += *it2;
                    it2++;
                }
            }
            else if (it2 == word2.end())
            {
                while (it1 != word1.end())
                {
                    res += *it1;
                    it1++;
                }
            }
            else
            {
                res += *it1;
                res += *it2;
                it1++;
                it2++;
            }
        }
        return res;
    };
};

int main()
{
    freopen("input.txt", "r", stdin);
    int test_case;
    cin >> test_case;
    Solution s;
    for (int i = 0; i < test_case; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << s1 << " " << s2 << endl;
        string res = s.mergeAlternately(s1, s2);
        cout << res << endl;
    }
    return 0;
}
