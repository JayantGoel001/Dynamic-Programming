#include<iostream>
using namespace std;
//Time complexity is O(n*r) and Space Complexity is O(n*r)
int perCof(int n,int r)
{
    int **ar=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        ar[i]=new int[r+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=r;j++)
        {
            ar[i][j]=0;
        }
    }
    ar[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,r);j++)
        {
            if(j==0)
            {
                ar[i][j]=1;
            }
            else
            {
                ar[i][j]=ar[i-1][j]+j*ar[i-1][j-1];
            }
        }
    }
    return ar[n][r];
}
//Time Complexity is O(n) And Space Complexity is O(n)
int perCof2(int n,int r)
{
    int *ar=new int[n+1];
    ar[0]=1;
    for(int i=1;i<=n;i++)
    {
        ar[i]=ar[i-1]*i;
    }
    return ar[n]/ar[n-r];
}
//Time Complexity is O(n) And Space Complexity is O(1)
int perCof3(int n,int r)
{
    int res=1;
    for(int i=n-r+1;i<=n;i++)
    {
        res*=i;
    }
    return res;
}
int main()
{
    int n,r;
    cout<<"Enter the value of n and r:\n";
    cin>>n;
    cin>>r;
    cout<<"Permutation Coefficient of P("<<n<<","<<r<<") is :"<<perCof(n,r)<<endl;
    cout<<"Permutation Coefficient of P("<<n<<","<<r<<") is :"<<perCof2(n,r)<<endl;
    cout<<"Permutation Coefficient of P("<<n<<","<<r<<") is :"<<perCof3(n,r)<<endl;
}
