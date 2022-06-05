/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

int EditDistance(string &s1, string &s2)
{
    int l1, l2;
    l1 = s1.length();
    l2 = s2.length();
    
    int ED[100][100];
    for(int i =0; i<l2; i++)
    {
        ED[0][i]=i;
        //cout<<ED[0][i]<<" "<<endl;
    }
    for(int j=0;j<l1;j++)
    {
        ED[j][0]=j;
        for(int i =1;i<l2;i++)
        {
            if(s1[j]==s2[i])
            {
                ED[i][j]=min(min(ED[i-1][j]+1,ED[i][j-1]+1), ED[i-1][j-1]);
            }
            else
            {
                ED[i][j]=min(min(ED[i-1][j]+1,ED[i][j-1]+1), ED[i-1][j-1]+1);
            }
        }
    }

   return ED[l1-1][l2-1];
}
int main()
{
    string s1,s2;
    cout<<"First String: ";
    cin>>s1;
    cout<<s1<<endl;
    cout<<"Second String: ";
    cin>>s2;
    cout<<s2<<endl;
    int k = EditDistance(s1,s2);
    cout<<k<<endl;
    return 0;
}
