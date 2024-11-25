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
        int a[size1+1], b[size2+1];
        int value;
        for (int i = 0; i < size1; i++)
        {                               
            cin >> value;
            a[i] = value;
        }
        for (int i = 0; i < size2; i++)
        {
            cin >> value;
            b[i] = value;
        }
        // Below is to avoid checking boundary condition
        a[size1] = 1e9+1;
        b[size2] = 1e9+1;
        int c[size1+size2];
        int i=0, j=0, k=0;
        while (i<size1 || j<size2)
        {
            if (a[i] < b[j])
            {
                c[k] = a[i];
                i++;
            }
            else
            {
                c[k] = b[j];
                j++;
            }
            k++;
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