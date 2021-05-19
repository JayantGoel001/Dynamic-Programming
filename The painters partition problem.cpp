#include <iostream>
#define int long long int
using namespace std;
// Time Complexity is (k*n^2) And Space Complexity is (kn).
int partitionTD(int *cumSum,int n,int k,int **dp){
    if (k==1){
        dp[k][n] = cumSum[n] - cumSum[0];
        return dp[k][n];
    }
    if (n==1){
        dp[k][n]=cumSum[1];
        return dp[k][n];
    }
    if (dp[k][n]!=-1){
        return dp[k][n];
    }
    dp[k][n] = INT_MAX;
    for (int l = 1; l <= n; ++l) {
        dp[k][n] = min(dp[k][n], max(partitionTD(cumSum,l,k-1,dp),cumSum[n]-cumSum[l]));
    }
    return dp[k][n];
}
// Time Complexity is (k*n^2) And Space Complexity is (kn).
int partitionBU(int *cumSum,int n,int k){
    int **dp = new int*[k+1];
    for (int i = 0; i <=k; ++i) {
        dp[i] = new int[n+1];
    }
    for (int i = 1; i <=k; ++i) {
        for (int j = 1; j <=n ; ++j) {
            if (i==1){
                dp[i][j] = cumSum[j] - cumSum[0];
                continue;
            }
            if (j==1){
                dp[i][j] = cumSum[1];
                continue;
            }
            dp[i][j] = INT_MAX;
            for (int l = 1; l <=j ; ++l) {
                dp[i][j] = min(dp[i][j], max(dp[i-1][l],cumSum[j]-cumSum[l]));
            }
        }
    }
    return dp[k][n];
}
int32_t main(){
    cout<<"Enter the value of n:\n";
    int n;
    cin>>n;
    cout<<"Enter the value of array:\n";
    int *ar = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    cout<<"Enter the value of k:\n";
    int k;
    cin>>k;
    int *cumSum = new int[n+1];
    cumSum[0]= 0;
    for (int i = 1; i <= n; ++i) {
        cumSum[i] = cumSum[i-1] + ar[i-1];
    }
    int **dp = new int*[k+1];
    for (int i = 0; i <= k; ++i) {
        dp[i] = new int[n+1];
    }
    for (int i = 0; i <=k; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = -1;
        }
    }
    cout<<"Using Top Down Approach\n";
    cout<<"Minimum Time Required to get this work done is : "<<partitionTD(cumSum,n,k,dp)<<'\n';
    cout<<"Using Bottom Up Approach\n";
    cout<<"Minimum Time Required to get this work done is : "<<partitionBU(cumSum,n,k)<<'\n';
}