#include <iostream>
#define int long long int
using namespace std;
// Time Complexity is O(n^3) And Space Complexity is O(n^2).
int matrixChainTD(int *ar,int i,int j,int **dp){
    if (i>=j){
        dp[i][j] = 0;
        return dp[i][j];
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k <=j; ++k) {
        dp[i][j] = min(dp[i][j], matrixChainTD(ar,i,k,dp) + matrixChainTD(ar,k+1,j,dp) + ar[i-1]*ar[k]*ar[j]);
    }
    return dp[i][j];
}
// Time Complexity is O(n^3) And Space Complexity is O(n^2).
int matrixChainBU(const int *ar,int n){
    int **dp = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[n+1];
    }
    for (int i = n; i >0; --i) {
        for (int j = i; j <n; ++j) {
            if (i==0 || j==0 || i==j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INT_MAX;
            for (int k = i; k <=j ; ++k) {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + ar[i-1] * ar[k] * ar[j]);
            }
        }
    }
    return dp[1][n-1];
}
int32_t main(){
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int *ar=new int[n];
    cout<<"Enter the value of array:\n";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int **dp = new int*[n];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[n];
    }
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j <n; ++j) {
            dp[i][j] = -1;
        }
    }
    cout<<"Using Top Down Approach :\n";
    cout<<"Minimum cost is : "<<matrixChainTD(ar,1,n-1,dp)<<"\n";
    cout<<"Using Bottom Up Approach :\n";
    cout<<"Minimum cost is : "<<matrixChainBU(ar,n)<<"\n";
}