#include<iostream>
#include<algorithm>
using namespace std;
//Time complexity is O(n^2) And Space Complexity is O(n)
int ldps(int *ar,int n)
{
    int *dp=new int[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        int x=ar[i];
        for(int j=i+1;j<n;j++)
        {
            if(ar[j]%x==0 && dp[i]+1>dp[j])
            {
                dp[j]=dp[i]+1;
                x=ar[j];
            }
        }
    }
    int maxi=-1;
     for(int i=0;i<n;i++)
    {
        if(dp[i]>maxi)
        {
            maxi=dp[i];
        }
    }
    return maxi;
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int *ar=new int[n];
    cout<<"Enter the value of array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    sort(ar,ar+n);
    cout<<"The Length of Largest Subset is:"<<ldps(ar,n);
}
