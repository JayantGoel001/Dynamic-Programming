#include<iostream>
using namespace std;
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
    int *dp=new int[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(ar[i]>ar[j] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    int maxi=-1;
    for(int i=0;i<n;i++)
    {
        if(maxi<dp[i])
        {
            maxi=dp[i];
        }
    }
    cout<<"Maximum Increasing Sequence in Array = "<<maxi;

}
