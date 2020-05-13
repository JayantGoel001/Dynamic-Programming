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
            if(j<ar[i-1])
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


//Time Complexity is O(n*sum) And Space Complexity is O(sum)
bool subSetSumDP2(int *ar,int n,int sum)
{
    bool **dp=new bool*[2];
    for(int i=0;i<2;i++)
    {
        dp[i]=new bool[sum+1];
    }
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=false;
    }
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
            {
                dp[i%2][j]=true;
            }
            else if(ar[i-1]<=j)
            {
                dp[i%2][j]=dp[(i-1)%2][j]||dp[(i-1)%2][j-ar[i-1]];
            }
            else
            {
                dp[i%2][j]=dp[(i-1)%2][j];
            }
        }
    }
    return dp[n%2][sum];
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
        cout<<"Using Recursion Subset with sum = "<<sum<<" exists."<<endl;
    }
    else
    {
        cout<<"Using Recursion Subset with sum = "<<sum<<" does not exists."<<endl;
    }
    if(subSetSumDP(ar,n,sum)==true)
    {
        cout<<"Using DP Subset with sum = "<<sum<<" exists."<<endl;
    }
    else
    {
        cout<<"Using DP Subset with sum = "<<sum<<" does not exists."<<endl;
    }
    if(subSetSumDP2(ar,n,sum)==true)
    {
        cout<<"Using DP2 Subset with sum = "<<sum<<" exists."<<endl;
    }
    else
    {
        cout<<"Using DP2 Subset with sum = "<<sum<<" does not exists."<<endl;
    }

}
