#include<iostream>
using namespace std;
//Time Complexity is exponential And Space Complexity is O(n)
int binoCoff(int n,int r)
{
    if(n==r || r==0)
    {
        return 1;
    }
    else
    {
        return binoCoff(n-1,r) + binoCoff(n-1,r-1);
    }
}
//Time Complexity is O(n*k) And Space Complexity is O(n*k)
int binoCoffDP(int n,int r)
{
    int **ar=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        ar[i]=new int[r+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,r);j++)
        {
            if(i==j || j==0)
            {
                ar[i][j]=1;
            }
            else
            {
                ar[i][j]=ar[i-1][j-1]+ar[i-1][j];
            }
        }
    }
    return ar[n][r];
}
//Time complexity is O(n*k) And Space Complexity is O(k)
int binoCoffDP2(int n,int r)
{
    int *ar=new int[r+1];
    for(int i=0;i<=r;i++)
    {
        ar[i]=0;
    }
    ar[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,r);j>0;j--)
        {
            ar[j]+=ar[j-1];
        }
    }
    return ar[r];
}
//Time Complexity is O(n*k) And Space complexity is O(n)
int binoCoffDP3(int n,int r,int **dp)
{
    if(dp[n][r]!=-1)
    {
        return dp[n][r];
    }
    if(r==n || r==0)
    {
        dp[n][r]=1;
        return dp[n][r];
    }
    else
    {
        dp[n][r]=binoCoffDP3(n-1,r-1,dp)+binoCoffDP3(n-1,r,dp);
        return dp[n][r];
    }
}
int main()
{
    int n,r;
    cout<<"Enter the value of n and r :\n";
    cin>>n;
    cin>>r;
    cout<<"The Binomial Coefficient using recursion of C("<<n<<","<<r<<") is : "<<binoCoff(n,r)<<endl;
    cout<<"The Binomial Coefficient using DP of C("<<n<<","<<r<<") is : "<<binoCoffDP(n,r)<<endl;
    cout<<"The Binomial Coefficient using DP2 of C("<<n<<","<<r<<") is : "<<binoCoffDP2(n,r)<<endl;
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[r+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=r;j++)
        {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=1;
    cout<<"The Binomial Coefficient using DP3 of C("<<n<<","<<r<<") is : "<<binoCoffDP3(n,r,dp);
}
