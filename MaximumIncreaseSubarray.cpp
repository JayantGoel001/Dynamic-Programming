#include<iostream>
using namespace std;
//Time Complexity is O(n) and Space Complexity is O(n)
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"Enter the value of array:\n";
    int *ar=new int[n];
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
        if(ar[i-1]<ar[i])
        {
            dp[i]=dp[i-1]+1;
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
    cout<<endl<<"Maximum increase in sub Array = "<<maxi;

}
