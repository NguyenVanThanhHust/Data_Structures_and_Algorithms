#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int test_case;
    freopen("Problem_1.txt", "r", stdin);
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {   
        int size1, size2;
        cin >> size1 >> size2;
        vector<int> a, b;
        int value;
        for (int i = 0; i < size1; i++)
        {                               
            cin >> value;
            a.push_back(value);
        }
        for (int i = 0; i < size2; i++)
        {
            cin >> value;
            b.push_back(value);
        }
            vector<int> c;
        vector<int>::iterator p1 = a.begin();
        vector<int>::iterator p2 = b.begin();
        while (p1 != a.end() && p2 != b.end())
        {
            if(p1 == a.end() && p2 == b.end())
            {
                break;
            }
            int v1 = *p1;
            int v2 = *p2;
            if (p1 == a.end())
            {
                while (p2 != b.end()) {
                    c.push_back(v2);
                    p2++;
                }
            }
            if (p2 == b.end())
            {
                while (p1 != a.end()) {
                    c.push_back(v1);
                    p1++;
                }
            }
            if (v1 < v2)
            {
                c.push_back(v1);
                p1++;
            }
            else
            {
                c.push_back(v2);
                p2++;
            }
        }
        cout << "C"<<endl;
        for (auto element: c)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}