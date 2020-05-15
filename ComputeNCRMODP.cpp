#include<iostream>
using namespace std;
//Time complexity is O(n*r) And Space Complexity is O(r)
int binoCoff(int n,int r,int p)
{
    if(r>n-r)
    {
        r=n-r;
    }
    int *dp=new int[r+1];
    for(int i=0;i<=r;i++)
    {
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,r);j>0;j--)
        {
            dp[j]=(dp[j]+dp[j-1])%p;
        }
    }
    return dp[r];
}
int main()
{
    int n,r;
    cout<<"Enter the value of n,r and p :\n";
    cin>>n;
    cin>>r;
    int p;
    cin>>p;
    cout<<"The NCR mod p using DP of C("<<n<<","<<r<<") is : "<<binoCoff(n,r,p)<<endl;
}
