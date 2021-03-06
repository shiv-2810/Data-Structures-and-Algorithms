/*///////////////////////////////////////////////////////////////////////////PROBLEM STATEMENT\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

There are n-cells arranged in linear fashion .You have a dice with 6 faces [1,2,3,4,5,6].You are standing at the 0th cell and wants to reach to the (n-1)th cell.
At each cell you have 6 possible jumps to make.In how many ways you can reach out the n-1th cell.


::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOLUTION::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include<bits/stdc++.h>
using namespace std;
int c=0;
void path(int n,int i,string s)
{
    if(i==n-1)
    {
        cout<<s<<endl;
        c+=1;
        return;
    }
    if(i>=n) return;
    for(int j=1;j<=6;j++)
    {
        path(n,i+j,s+to_string(j)+"->");
    }
}
int main()
{
    path(7,0,"");
    cout<<"Total paths ="<<c;
}
