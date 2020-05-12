#include<iostream>
using namespace std;
//Time complexity is exponential And Space Complexity is O(n)
bool subSetSum(int *ar,int n,int sum)
{
    if(n==0 && sum!=0)
    {
        return false;
    }
    if(sum==0)
    {
        return true;
    }
    if(ar[n-1]<=sum)
    {
        return subSetSum(ar,n-1,sum-ar[n-1])||subSetSum(ar,n-1,sum);
    }
    else
    {
        return subSetSum(ar,n-1,sum);
    }
}
//Time Complexity is O(n*sum) And Space Complexity is O(n*sum)
bool subSetSumDP(int *ar,int n,int sum)
{
    bool **dp=new bool*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new bool[sum+1];
    }
    for(int j=0;j<=sum;j++)
    {
        dp[0][j]=false;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>ar[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-ar[i-1]];
            }
        }
    }
    return dp[n][sum];
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
    int sum;
    cout<<"Enter the value of sum:\n";
    cin>>sum;
    if(subSetSum(ar,n,sum)==true)
    {
        cout<<"Using Recursion Subset with sum = "<<sum<<" exists.";
    }
    else
    {
        cout<<"Using Recursion Subset with sum = "<<sum<<" does not exists.";
    }
    if(subSetSumDP(ar,n,sum)==true)
    {
        cout<<"Using DP Subset with sum = "<<sum<<" exists.";
    }
    else
    {
        cout<<"Using DP Subset with sum = "<<sum<<" does not exists.";
    }

}
