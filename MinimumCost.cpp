#include <iostream>
#define ll long long int
using namespace std;
ll minCost(ll **ar,int n,int m,ll **dp,int i=0,int j=0){
    if (i==n || j==m){
        return INT_MAX;
    }
    if (i==n-1 && j==m-1){
        dp[i][j] = ar[i][j];
        return dp[i][j];
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = ar[i][j]+min(minCost(ar,n,m,dp,i+1,j), minCost(ar,n,m,dp,i,j+1));
    return dp[i][j];
}
ll minCost2(ll **ar,int n,int m){
    ll **dp = new ll*[n+1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new ll[m+1];
    }
    for (int i = 0; i <=n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <=m; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m ; ++j) {
            if (i==1){
                dp[i][j] = (dp[i][j-1] + ar[i-1][j-1]);
            }else if (j==1){
                dp[i][j] = (dp[i-1][j] + ar[i-1][j-1]);
            }else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + ar[i - 1][j - 1];
            }
        }
    }
    return dp[n][m];
}
int main(){
    cout<<"Enter the value of n & m:\n";
    int n,m;
    cin>>n>>m;
    ll **ar = new ll* [n];
    for (ll i = 0; i < n; ++i) {
        ar[i] = new ll[m];
    }
    cout<<"\nEnter the value of array:\n";
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin>>ar[i][j];
        }
    }
    ll **dp = new ll* [n];
    for (ll i = 0; i < n; ++i) {
        dp[i] = new ll[m];
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            dp[i][j] = -1;
        }
    }
    cout<<"Using Top Down Approach:\n";
    cout<<"Minimum Cost is : "<<minCost(ar,n,m,dp)<<"\n";
    cout<<"Using Bottom Up Approach:\n";
    cout<<"Minimum Cost is : "<<minCost2(ar,n,m)<<"\n";
}