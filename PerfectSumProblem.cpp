#include<iostream>
using namespace std;
printSubset(int *ar,int n,int sum,vector<int> p,int **dp)
{

}
void PerfectSum(int *ar,int n,int sum)
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
                dp[i][j]=dp[i-1][j-ar[i-1]];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if(dp[n][sum]==true)
    {
        vector<int> p;
        cout<<"The subset with sum = "<<sum<<endl;
        printSubsets(ar,n-1,sum,p,dp);
    }
    else
    {
        cout<<"There are No subsets with sum "<<sum;
    }
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
    PerfectSum(ar,n,sum);
}

