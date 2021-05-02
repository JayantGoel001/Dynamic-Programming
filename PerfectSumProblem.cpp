#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& p)
{
    for(int i=0;i<p.size();i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
void printSubset(int *ar,int i,int sum,vector<int> &p,bool **dp)
{
    if(i==0 && sum!=0 && dp[0][sum])
    {
        p.push_back(ar[i-1]);
        display(p);
        return;
    }
    if(i==0 && sum==0)
    {
        display(p);
        return;
    }
    if(dp[i-1][sum])
    {
        vector<int> b=p;
        printSubset(ar,i-1,sum,b,dp);
    }
    if(sum>=ar[i-1] && dp[i-1][sum-ar[i-1]])
    {
        p.push_back(ar[i-1]);
        printSubset(ar,i-1,sum-ar[i-1],p,dp);
    }
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
                dp[i][j]=dp[i-1][j]||dp[i-1][j-ar[i-1]];
            }
        }
    }
    if (!dp[n][sum]) {
        cout << "There are No subsets with sum " << sum;
    } else {
        vector<int> p;
        cout << "The subset with sum = " << sum << " are " << endl;
        printSubset(ar, n, sum, p, dp);
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

