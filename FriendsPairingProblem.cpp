#include<iostream>
using namespace std;
//Time complexity is O(n) And Space Complexity is O(n)
int fpp_bottom_up(int n)
{
    int *dp=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i<=2)
        {
            dp[i]=i;
        }
        else
        {
            dp[i]=dp[i-1]+(i-1)*dp[i-2];
        }
    }
    return dp[n];
}
//Time complexity is O(n) And Space Complexity is O(n)
int fpp_top_down(int *dp,int n)
{
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    if(n==0 || n==1 || n==2)
    {
        dp[n]=n;
        return dp[n];
    }
    else
    {
        dp[n]=fpp_top_down(dp,n-1)+(n-1)*fpp_top_down(dp,n-2);
        return dp[n];
    }
}
//Time Complexity is O(n) and Space Complexity is O(1)
int fpp_fibonacci(int n)
{
    int a=1;
    int b=2;
    int c=0;
    for(int i=3;i<=n;i++)
    {
        c=b+a*(i-1);
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"The number of friends pairing problem Using Bottom up is :"<<fpp_bottom_up(n)<<endl;
    int *dp=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
    cout<<"The number of friends pairing problem Using Top Down is :"<<fpp_top_down(dp,n)<<endl;
    cout<<"The number of friends pairing problem Using Fibonacci is :"<<fpp_fibonacci(n)<<endl;
}
