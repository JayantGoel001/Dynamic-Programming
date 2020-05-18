#include<iostream>
using namespace std;
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
    cout<<"The maximum Value Obtained = "<<cutARod(price,n);
}
