#include<iostream>
using namespace std;
//Time Complexity is O(n^2) And Space Complexity is O(n^2)
int cutARod(int *pr,int n)
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(pr[i-1]+dp[i][j-i],dp[i-1][j]);
            }
        }
    }
    return dp[n][n];
}
//Time Complexity is O(n^2) And Space Complexity is O(n)
int cutARod2(int *pr,int n)
{
    int *dp=new int[n+1];

    for(int i=0;i<=n;i++)
    {
        dp[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            dp[j]=max(pr[i-1]+dp[j-i],dp[j]);
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cout<<"Enter the length:\n";
    cin>>n;
    int *price=new int[n];
    cout<<"Enter the prices :\n";
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    cout<<"The maximum Value Obtained in O(n^2) = "<<cutARod(price,n);
    cout<<"The maximum Value Obtained in O(n)   = "<<cutARod2(price,n);
}
