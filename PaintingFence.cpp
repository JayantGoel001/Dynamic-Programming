#include <bits/stdc++.h>
using namespace std;
//Time Complexity is O(n) And Space Complexity is O(n)
int paintFence(int n,int k)
{
    int *dp=new int[n+1];
    dp[1]=k;
    dp[2]=k*k;
    int mod97=pow(10,9)+7;
    for(int i=3;i<=n;i++)
    {
        dp[i]=((dp[i-1]+dp[i-2])*(k-1))%mod97;
    }
    return dp[n];
}
//Time Complexity is O(n) And Space Complexity is O(1)
int paintFence2(int n,int k)
{
    int same;
    int diff=k;
    int total=k;
    int mod97=pow(10,9)+7;
    for(int i=2;i<=n;i++)
    {
        same=diff;
        diff=(total*(k-1))%(mod97);
        total=same+diff;
    }
    return total;
}
int main()
{
    int n, k;
    cout<<"Enter the value of n and k:\n";
    cin>>n;
    cin>>k;
    cout<<"Number of ways to paint the fence in O(n) Space are : "<<paintFence(n, k);
    cout<<"Number of ways to paint the fence in O(1) Space are : "<<paintFence2(n, k);
}
