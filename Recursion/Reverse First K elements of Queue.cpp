#include <bits/stdc++.h>

using namespace std;
void rev(int arr[],int n,int i,int k)
{
    if(i==k/2)
     return;
     swap(arr[i],arr[k-i-1]);
     rev(arr,n,i+1,k);
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    rev(arr,n,0,k);
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";

    return 0;
}
