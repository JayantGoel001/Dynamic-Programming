#include<iostream>
#define ll long long int
#include <map>
using namespace std;
//Time complexity is exponential And Space Complexity is O(n)
int coinWay(int *ar,int n,int sum){
    if(sum==0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    if(n<=0 && sum>0){
        return 0;
    }
    return coinWay(ar,n-1,sum)+coinWay(ar,n,sum-ar[n-1]);
}
//Time complexity is O(n*sum) And Space Complexity is O(n*sum)
int coinWayDP(const int *ar,int n,int sum){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[sum+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<ar[i-1]){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-ar[i-1]];
            }
        }
    }
    return dp[n][sum];
}
//Time complexity is O(n*sum) And Space Complexity is O(sum)
int coinWayDP2(const int *ar,int n,int sum){
    int *dp=new int[sum+1];
    for(int i=0;i<=sum;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=ar[i];j<=sum;j++){
            dp[j]+=dp[j-ar[i]];
        }
    }
    return dp[sum];
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int *ar=new int[n];
    cout<<"\nEnter the value of array:\n";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int sum;
    cout<<"\nEnter the sum to be searched :\n";
    cin>>sum;
    cout<<"Number of ways through Recursion = "<<coinWay(ar,n,sum)<<endl;
    cout<<"Number of ways through DP = "<<coinWayDP(ar,n,sum)<<endl;
    cout<<"Number of ways through DP2 = "<<coinWayDP2(ar,n,sum)<<endl;
}
