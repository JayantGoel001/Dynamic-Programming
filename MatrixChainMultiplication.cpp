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
void printPara(int i,int j,int **kar,char &name)
{
    if(i==j)
    {
        cout<<name++;
        return;
    }
    cout<<"(";
    printPara(i,kar[i][j],kar,name);
    printPara(kar[i][j]+1,j,kar,name);
    cout<<")";
}
void printPara2(int i,int j,int **kar,char &name)
{
    if(i==j)
    {
        cout<<name++;
        return;
    }
    cout<<"(";
    printPara2(i,kar[j][i],kar,name);
    printPara2(kar[j][i]+1,j,kar,name);
    cout<<")";
}
//Time Complexity is O(n^3) And Space Complexity is O(n^2)
int matrixChainOrderDP(int *mat,int n)
{
    int **m=new int*[n];
    int **kar=new int*[n];
    for(int i=0;i<n;i++)
    {
        m[i]=new int[n];
        kar[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j]=0;
            kar[i][j]=0;
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
                    kar[i][j]=k;
                    //another approach
                    m[j][i]=k;
                    //another approach
                }
            }
        }
    }
    cout<<"Matrix Multiplication is Given as :\n";
    char name='A';
    printPara(1,n-1,kar,name);
    cout<<endl;
    //another approach
    cout<<"Matrix Multiplication is Given as :\n";
    name='A';
    printPara2(1,n-1,m,name);
    cout<<endl;
    //another approach
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
    cout<<"Minimum number of multiplication using DP in O(n^3) are ="<<matrixChainOrderDP(mat,n)<<endl;
}
