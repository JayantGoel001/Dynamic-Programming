#include<iostream>
using namespace std;
//Time Complexity is O(m^2) And Space Complexity is O(m)
bool sssdm(int *ar,int n,int m)
{
    if(n>m)
    {
        return true;
    }
    bool *dp=new bool[m];
    for(int i=0;i<m;i++)
    {
        dp[m]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(dp[0]==true)
        {
            return true;
        }
        bool *temp=new bool[m];
        for(int j=0;j<m;j++)
        {
            temp[j]=false;
        }
        for(int j=0;j<m;j++)
        {
            if(dp[j]==true)
            {
                if(dp[(j+ar[i])%m]==false)
                {
                    temp[(j+ar[i])%m]=true;
                }
            }
        }
        for(int j=0;j<m;j++)
        {
            if(temp[j]==true)
            {
                dp[j]=true;
            }
        }
        dp[ar[i]%m]=true;
    }
    return dp[0];
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int *ar=new int[n];
    cout<<"Enter the value of array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int m;
    cout<<"Enter the value of m:\n";
    cin>>m;
    if(sssdm(ar,n,m)==true)
    {
        cout<<"Subset with modulo = "<<m<<" exists."<<endl;
    }
    else
    {
        cout<<"Subset with modulo = "<<m<<"does not exists."<<endl;
    }


}
