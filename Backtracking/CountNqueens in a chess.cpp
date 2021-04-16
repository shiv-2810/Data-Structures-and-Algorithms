/*////////////////////////////////////////////////////////////////////////////////////PROBLEM STATEMENT\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



Input::::::::::4
OUTPUT:::::::2


:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOLUTION::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

#include<bits/stdc++.h>
using namespace std;
int totalpaths=0;
bool isitsafe(int n,int row,int col,vector<vector<bool>> &grid)
{
    for(int i=row-1;i>=0;i--) if(grid[i][col]) return false;  //Column Check
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)  if(grid[i][j]) return false;   //left-diagonal check
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)  if(grid[i][j]) return false;   //Right-diagonal check
    return true;
}

void countNqueens(vector<vector<bool>>&grid,int curr_row,int n)
{
    if(curr_row==n)
    {
      totalpaths+=1;
      return;
    }
   for(int i=0;i<n;i++)
   {
       if(isitsafe(n,curr_row,i,grid))
       {
           grid[curr_row][i]=true;
           countNqueens(grid,curr_row+1,n);
           grid[curr_row][i]=false;
       }
   }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<bool>>grid(n,vector<bool>(n,false));
    countNqueens(grid,0,n);
    cout<<totalpaths<<endl;
}
