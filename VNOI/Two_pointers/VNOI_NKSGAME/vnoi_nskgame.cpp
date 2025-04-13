#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>

using namespace std;
#define MAX_SIZE 100000

void print_array(int a[],int size) 
{ 
    cout<<"array: ";
    for (int i = 0; i < size; i++) 
        cout<<a[i]<<" ";
    cout<<endl;
} 

int main()
{
    int array_size;
    cin >> array_size;
    int  b[array_size+1], c[array_size+1];
    int value;
    for (int i = 0; i < array_size; i++)
    {                               
        cin >> value;
        b[i] = value;
    }
    sort(b, b+array_size);
    for (int j = 0; j < array_size; j++)
    {
        cin >> value;
        c[j] = value;
    }
    sort(c, c+array_size);
    b[array_size] = 1e9;
    c[array_size] = 1e9;

    // Start algorithm here
    int i=0, j=array_size-1;
    while (true)
    {
        // cout<<i<<" "<<j<<endl;
        if ((b[i] + c[j]) < 0)
        {
            if ((i+1)==array_size)
            {
                break;
            }
            i++;
        }
        else if ((b[i] + c[j]) > 0)
        {
            if ((j-1)<0)
            {
                break;
            }
            j--;
        }
        else
        {
            break;
        }
    }
    // End algorithm here
    cout<<abs(b[i]+c[j])<<endl;
    return 0;
}