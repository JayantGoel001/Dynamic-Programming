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
int main()
{
    int n,r;
    cout<<"Enter the value of n and r :\n";
    cin>>n;
    cin>>r;
    cout<<"The Binomial Coefficient using recursion of C("<<n<<","<<r<<") is : "<<binoCoff(n,r)<<endl;
    cout<<"The Binomial Coefficient using DP of C("<<n<<","<<r<<") is : "<<binoCoffDP(n,r);
}
