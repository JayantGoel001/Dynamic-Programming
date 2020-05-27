#include<bits/stdc++.h>
using namespace std;
int lcsDP(int ***dp,string s1,int l,int r,int flag)
{
    if(l>r)
    {
        return 0;
    }
    if(dp[l][r][flag]!=-1)
    {
        return dp[l][r][flag];
    }
    int ans=0;
    if(flag==1)
    {
        if(s1[l]==s1[r])
        {
            ans=max(ans,1+lcsDP(dp,s1,l+1,r-1,1));
        }
    }
    else
    {
        if(s1[l]==s1[r])
        {
            ans=max(ans,1+lcsDP(dp,s1,l+1,r-1,1));
        }
        ans=max(ans,max(lcsDP(dp,s1,l+1,r,0),lcsDP(dp,s1,l,r-1,0)));
    }

    return dp[l][r][flag]=ans;
}
int main()
{
    string str;
    cout<<"Enter the value of string:\n";
    cin>>str;
    string revstr=str;
    int x=str.length();
    reverse(revstr.begin(),revstr.end());
    int ***dp=new int**[x+1];
    for(int i=0;i<=x;i++)
    {
        dp[i]=new int*[x+1];
        for(int j=0;j<=x;j++)
        {
            dp[i][j]=new int[2];
        }
    }
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=x;j++)
        {
            for(int k=0;k<2;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    cout<<"Length of Longest Common Subset in string "<<str<<" and "<<revstr<<" is : "<<lcsDP(dp,str,0,x-1,0)<<endl;
}

