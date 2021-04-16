/*//////////////////////////////////////////////////////////////////////PROBLEM STATEMENT\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

You are given a 2-D matrix of(n*m) you will tart from top left cell and you want to go to bottom right.At each point you can move either right or down.
Print and count all posible paths.



:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOLUTION::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include<bits/stdc++.h>
using namespace std;
int c=0;
void maze(int i,int j,int n,int m,string s)
{
    if(i==n-1&&j==m-1)
    {
        c+=1;
        cout<<s<<endl;
        return;
        
    }
    if(i>=n||j>=m)
       return;
    maze(i+1,j,n,m,s+"D");
    maze(i,j+1,n,m,s+"R");
}
int main()
{
    maze(0,0,3,3,"");
    cout<<"Total paths ="<<c;
}
