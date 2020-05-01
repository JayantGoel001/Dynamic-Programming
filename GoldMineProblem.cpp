#include<iostream>
using namespace std;
//Time complexity is O(m*n) and Space Complexity is O(m*n)
int goldMine(int **ar,int m,int n)
{
    int **dp=new int*[m];
    for(int i=0;i<m;i++)
    {
        dp[i]=new int[n];
    }
    int maxi=-1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        dp[i][0]=ar[i][0];
    }
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            int up;
            int down;
            if(i!=0)
            {
                up=dp[i-1][j-1];
            }
            else
            {
                up=0;
            }
            if(i!=m-1)
            {
                down=dp[i+1][j-1];
            }
            else
            {
                down=0;
            }
            dp[i][j]=ar[i][j]+max(dp[i][j-1],max(up,down));
            if(j==n-1)
            {
                if(dp[i][j]>=maxi)
                {
                    maxi=dp[i][j];
                }
            }
        }
    }
    return maxi;
}
int main()
{
    int m,n;
    cout<<"Enter the value of m And n:"<<endl;
    cin>>m>>n;
    int **ar=new int*[m];
    for(int i=0;i<m;i++)
    {
        ar[i]=new int[n];
    }
    cout<<"\nEnter the value of Array:\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ar[i][j];
        }
        cout<<endl;
    }
    cout<<"Gold Mine Problem = "<<goldMine(ar,m,n);
}
