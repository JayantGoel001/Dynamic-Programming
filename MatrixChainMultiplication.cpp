#include<iostream>
using namespace std;
//Time Complexity is O(2^n) And Space Complexity is O(n) in stack
int matrixChainOrder(int *mat,int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    int mini=INT_MAX;
    int x;
    for(int k=i;k<j;k++)
    {
        x=matrixChainOrder(mat,i,k)+matrixChainOrder(mat,k+1,j)+mat[i-1]*mat[k]*mat[j];
        if(x<mini)
        {
            mini=x;
        }
    }
    return mini;
}
//Time Complexity is O(n^3) And Space Complexity is O(n^2)
int matrixChainOrderDP(int *mat,int n)
{
    int **m=new int*[n];
    for(int i=0;i<n;i++)
    {
        m[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j]=0;
        }
    }
    for(int l=1;l<n-1;l++)
    {
        for(int i=1;i<n-l;i++)
        {
            int j=i+l;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int x=m[i][k]+m[k+1][j]+mat[i-1]*mat[k]*mat[j];
                if(x<m[i][j])
                {
                    m[i][j]=x;
                }
            }
        }
    }
    return m[1][n-1];
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int *mat=new int[n];
    cout<<"Enter the value of array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>mat[i];
    }
    cout<<"Minimum number of multiplication Using Recurrence are ="<<matrixChainOrder(mat,1,n-1)<<endl;
    cout<<"Minimum number of multiplication using DP are ="<<matrixChainOrderDP(mat,n);
}
