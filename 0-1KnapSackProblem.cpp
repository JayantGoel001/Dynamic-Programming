#include<iostream>
#include<vector>
using namespace std;
//Time Complexity is O(2^n) And Space Complexity is O(n) in stack
int knapsackRec(int *value,int *weight,int n,int W)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(weight[n-1]>W)
    {
        return knapsackRec(value,weight,n-1,W);
    }
    else
    {
        return max(knapsackRec(value,weight,n-1,W),
        knapsackRec(value,weight,n-1,W-weight[n-1])+value[n-1]);
    }
}
//Time Complexity is O(n*W) And Space Complexity is O(n*w)
int knapsackDP(int *value,int *weight,int n,int W)
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[W+1];
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=W;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(weight[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],value[i-1]+dp[i-1][j-weight[i-1]]);
            }
        }
    }
    cout<<"The Values Included in 0/1 Knapsack are :\n";
    int total=dp[n][W];
    int w=W;
    for(int i=n;i>0 && total>0;i--)
    {
        if(total==dp[i-1][w])
        {
            continue;
        }
        else
        {
            cout<<weight[i-1]<<" ";
            total-=value[i-1];
            w-=weight[i-1];
        }
    }
    cout<<endl;
    return dp[n][W];
}
int knapsackDPU(int *value,int *weight,int n,int W)
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[W+1];
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=W;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(weight[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],value[i-1]+dp[i][j-weight[i-1]]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"Enter the values:\n";
    int *value=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    cout<<"Enter the weights of each item:\n";
    int *weight=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    int W;
    cout<<"Enter the value of knapsack capacity:\n";
    cin>>W;
    cout<<"Maximum value obtained through recursion is "<<knapsackRec(value,weight,n,W)<<endl;
    cout<<"Maximum value obtained through DP is "<<knapsackDP(value,weight,n,W)<<endl;
    cout<<"Maximum value obtained through DP(Unbounded) is "<<knapsackDPU(value,weight,n,W)<<endl;
}
