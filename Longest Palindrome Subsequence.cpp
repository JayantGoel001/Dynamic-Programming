#include <iostream>
#define int long long int
using namespace std;
int LPS(string str,int i,int j,int **dp){
    if (i>j){
        dp[i][j] = 0;
        return dp[i][j];
    }
    if (i==j){
        dp[i][j] = 1;
        return dp[i][j];
    }
    if (str[i-1] == str[j-1]){
        dp[i][j] = 2 + LPS(str,i+1,j-1,dp);
        return dp[i][j];
    }
    dp[i][j] = max(LPS(str,i+1,j,dp), LPS(str,i,j-1,dp));
    return dp[i][j];
}
int LPS2(string str,int n){
    int **dp = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[n+1];
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=n; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = n; i >0; --i) {
        for (int j = i; j <=n; ++j) {
            if (i==j){
                dp[i][j] = 1;
            } else if (str[i-1] == str[j-1]){
                dp[i][j] = 2 + dp[i+1][j-1];
            } else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[1][n];
}
int32_t main(){
    cout<<"Enter A String :\n";
    string str;
    cin>>str;
    int n = str.length();
    cout<<"Using Top Down Approach :\n";
    int **dp = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[n+1];
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=n; ++j) {
            dp[i][j] = -1;
        }
    }
    cout<<"Maximum Length Palindrome Subsequence is : "<<LPS(str,1,n,dp)<<"\n";
    cout<<"Using Bottom Up Approach :\n";
    cout<<"Maximum Length Palindrome Subsequence is : "<<LPS2(str,n)<<"\n";
}