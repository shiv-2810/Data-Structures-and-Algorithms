/*Problen statement
N=13
Output: 0,1,10,11,12,13,2,3,4,5,6,7,8,9

Solution:*/


#include<bits/stdc++.h>
using namespace std;
 void lexo(int n,int i)
 {
     if(i>n) return;
     cout<<i<< " ";
     for(int j=(i==0)?1:0;j<=9;j++)
     {
         lexo(n,10*i+j);
     }
 }
 int main()
 {
     int n;
     cin>>n;
     lexo(n,0);
 }
