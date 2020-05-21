#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int **ar=new int*[2];
    int **t=new int*[2];
    for(int i=0;i<2;i++)
    {
        ar[i]=new int[n];
        t[i]=new int[n];
    }
    cout<<"Enter the value of time spent on each station:\n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ar[i][j];
        }
    }
    cout<<"Enter the value of time spent on diagonal movement:\n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>t[i][j];
        }
    }
    int *entry=new int[2];
    int *exit=new int[2];
    cout<<"Enter the entry time:\n";
    for(int i=0;i<2;i++)
    {
        cin>>entry[i];
    }
    cout<<"Enter the exit time:\n";
    for(int i=0;i<2;i++)
    {
        cin>>exit[i];
    }
    //Time Complexity is O(n) And Space Complexity is O(n)
    ar[0][0]+=entry[0];
    ar[1][0]+=entry[1];

    ar[0][n-1]+=exit[0];
    ar[1][n-1]+=exit[1];

    int **dp=new int*[2];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[n];
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<2;i++)
        {
            if(j==0)
            {
                dp[i][j]=ar[i][j];
            }
            else
            {
                dp[i][j]=min(dp[i][j-1],dp[!i][j-1]+t[!i][j])+ar[i][j];
            }
        }
    }
    cout<<"Minimum Time Required to build a car chassis in O(n) Space : "<<min(dp[0][n-1],dp[1][n-1])<<endl;

    //Time Complexity is O(n) And Space Complexity is O(1)
    int a=ar[0][0];
    int b=ar[1][0];
    int c;
    int d;
    for(int j=1;j<n;j++)
    {
        c=min(a,b+t[1][j])+ar[0][j];
        d=min(b,a+t[0][j])+ar[1][j];
        a=c;
        b=d;
    }
     cout<<"Minimum Time Required to build a car chassis in O(1) Space : "<<min(a,b);
}
