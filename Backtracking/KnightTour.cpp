/**********************************************************************************************************************************************************************************
                                                                       SOLUTION
*********************************************************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int > >&grid,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isitsafe(vector<vector<int> >&grid,int n,int i,int j,vector<vector<bool> >&visited)
{
   return (i>=0 && j>=0 && i<n && j<n && visited[i][j]==false);
}

void countKnights(vector<vector<int> >&grid,int n,int i,int j,int c,vector<vector<bool> >&visited)
{
    if(c== n*n-1)
    {
        grid[i][j]=c;
        display(grid,n);
        cout<<endl<<endl;
        return;
    }
    if(c>=n*n)
    {
        return;
    }
    int xdir[8]={-2,-2,-1,-1,2,2,1,1};
    int ydir[8]={1,-1,2,-2,1,-1,2,-2};
    visited[i][j]=true;
    grid[i][j]=c;
    for(int k=0;k<8;k++)
    {
        if(isitsafe(grid,n,i+xdir[k],j+ydir[k],visited))
        {
            countKnights(grid,n,i+xdir[k],j+ydir[k],c+1,visited);
        }
    }
     grid[i][j]=-1;
    visited[i][j]=false;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<bool> >visited(n,vector<bool>(n,false));
    vector<vector<int> >grid(n,vector<int>(n,-1));
    countKnights(grid,n,0,0,0,visited);
    }
/********************************************************************************************************************************************************************************/
