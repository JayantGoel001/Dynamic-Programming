#include <bits/stdc++.h>
using namespace std;
//Time Complexity is O(n^2) and Space Complexity is O(n)
int LIS(int *ar,int n)
{
    int *dp=new int[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(ar[i]>ar[j] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    int maxi=-1;
    for(int i=0;i<n;i++)
    {
        if(maxi<dp[i])
        {
            maxi=dp[i];
        }
    }
    return maxi;
}
int getIndexOfElement(vector<int> &ar,int n,int ele)
{
    int low=0;
    int high=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ar[mid]>ele && ar[mid+1]<ele)
        {
            return mid;
        }
        else if(ar[mid]<ele)
        {
            low=mid+1;
        }
        else if(ar[mid]>ele)
        {
            high=mid-1;
        }
    }
    return low;
}
//Time Complexity is O(n*log(n)) And Space Complexity is O(n)
int LIS2(int *ar,int n)
{
    vector<int> v;
    v.push_back(ar[0]);
    int vl=1;
    for(int i=1;i<n;i++)
    {
        if(ar[i]>v[vl-1])
        {
            v.push_back(ar[i]);
            vl++;
        }
        else if(ar[i]<v[0])
        {
            v[0]=ar[i];
        }
        else
        {
            int index=getIndexOfElement(v,vl,ar[i]);
            v[index]=ar[i];
        }
    }
    return vl;
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

    cout<<"Maximum Increasing Sequence in Array in O(n^2)= "<<LIS(ar,n)<<endl;
    cout<<"Maximum Increasing Sequence in Array in O(n*log(n)) ="<<LIS2(ar,n);

}
