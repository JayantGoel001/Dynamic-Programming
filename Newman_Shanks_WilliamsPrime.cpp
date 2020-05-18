#include<iostream>
using namespace std;
//Time Complexity is O(n) And Space Complexity is O(n)
int nswp(int n)
{
    int *dp=new int[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=2*dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//Time Complexity is O(n) And Space Complexity is O(1)
int nswp2(int n)
{
    int a=1;
    int b=1;
    int c;
    for(int i=2;i<=n;i++)
    {
        c=2*b+a;
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
    cout<<"Newman-Shanks-Williams Prime number in O(n) Space at "<<n<<" = "<<nswp(n);
    cout<<"Newman-Shanks-Williams Prime number in O(1) Space at "<<n<<" = "<<nswp(n);
}
