#include <iostream>
#define int long long int
using namespace std;
// Time Complexity is O(n^2) And Space Complexity is O(n^2).
int rodCuttingTD(int *price,int n,int m,int **dp){
    if (n==0 || m==0){
        dp[n][m] = 0;
        return dp[n][m];
    }
    if (dp[n][m]!=-1){
        return dp[n][m];
    }
    if (m>=n){
        dp[n][m] = max(rodCuttingTD(price,n-1,m,dp),price[n-1] + rodCuttingTD(price,n,m-n,dp));
    } else{
        dp[n][m] = rodCuttingTD(price,n-1,m,dp);
    }
    return dp[n][m];
}
// Time Complexity is O(n^2) And Space Complexity is O(n^2).
int rodCuttingBU(int *price,int n){
    int **dp = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[n+1];
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=n; ++j) {
            if (i==0 || j==0){
                dp[i][j] = 0;
            } else if (j>=i){
                dp[i][j] = max(dp[i-1][j], price[i-1]+dp[i][j-i]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}
int32_t main(){
    int n;
    cout<<"Enter the length:\n";
    cin>>n;
    int *price=new int[n];
    cout<<"Enter the prices :\n";
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int **dp = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[n+1];
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=n; ++j) {
            dp[i][j] = -1;
        }
    }
    cout<<"The maximum Value Obtained Using Top Down Approach is : "<<rodCuttingTD(price,n,n,dp)<<"\n";
    cout<<"The maximum Value Obtained Using Bottom Up Approach is : "<<rodCuttingBU(price,n)<<"\n";
}