/*///////////////////////////////////////////////////////////////////////////////PROBLEM STATEMENT\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Story: You have to find a path through which the rat move from the starting position (0,0) to the final position where cheese is (n,n). List the total no of possible paths which the rat can take to reach the cheese.

Input
A file whose first line contains the size of the square maze The next n lines contain n binary values separated by space. 0 denotes an open cell while 1 denotes a blocked cell. You have to find paths which contain only cells which are open, and finally print the total no of such unique paths. Retracing the 1 or more cells back and forth is not considered a new path. The set of all cells covered in a single path should be unique from other paths

Output
The output should be the total no of paths possible on the first line

Example
Input: 
7
0 0 1 0 0 1 0
1 0 1 1 0 0 0
0 0 0 0 1 0 1
1 0 1 0 0 0 0 
1 0 1 1 0 1 0
1 0 0 0 0 1 0
1 1 1 1 0 0 0



Output:
4
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOLUTION:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

#include<bits/stdc++.h>
using namespace std;
int totalpaths=0;
bool issafe(int n,int i,int j,vector<vector<bool> >&visited)
{
    return i>=0&&j>=0&&i<n&&j<n&&visited[i][j]==false;
}
void helper(int n,int i,int j,vector<vector<int> >&grid,vector<vector<bool> >&visited)
{
    if(i==n-1&&j==n-1)
    {
      totalpaths+=1;
      return;
    }
    if(!issafe(n,i,j,visited))
    {
        return;
    }
    visited[i][j]=true;
    if(i+1<n&&grid[i+1][j]==0)
      helper(n,i+1,j,grid,visited);
    if(i-1>=0&&grid[i-1][j]==0)
      helper(n,i-1,j,grid,visited);
    if(j+1<n&&grid[i][j+1]==0)
      helper(n,i,j+1,grid,visited);
    if(j-1>=0&&grid[i][j-1]==0)
      helper(n,i,j-1,grid,visited);
    visited[i][j]=false;
    return;
}
int counttotalpath(vector<vector<int> >&grid)
{
    int n=grid.size();
    vector<vector<bool> >visited(n,vector<bool>(n,false));
    helper(n,0,0,grid,visited);
    return totalpaths;

}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> >grid(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<counttotalpath(grid);
}
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::END:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/




