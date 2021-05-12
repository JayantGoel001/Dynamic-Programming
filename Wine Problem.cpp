#include <iostream>
using namespace std;
int solveWine(int *ar,int start,int end,int **dp,int year){
    if (dp[start][end]!=-1){
        return dp[start][end];
    }
    if (start==end){
        dp[start][end] = ar[start]*year;
        return dp[start][end];
    }
    dp[start][end] = max(ar[start]*year + solveWine(ar,start+1,end,dp,year+1),ar[end]*year + solveWine(ar,start,end-1,dp,year+1));
    return dp[start][end];
}
int solveWine2(const int *ar,int n){
    int **dp = new int*[n];
    for (int i = 0; i <n; ++i) {
        dp[i] = new int[n];
    }
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j <n ; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = n-1;i >=0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i<j) {
                int year =n-(j-i);
                dp[i][j] = max(ar[i] * year + dp[i + 1][j],ar[j]*year + dp[i][j - 1]);
            }
            if (i==j){
                int year =n-(j-i);
                dp[i][j] = ar[i]*year;
            }
        }
    }
    return dp[0][n-1];
}
int main(){
    cout<<"Enter number of wines:\n";
    int n;
    cin>>n;
    int ar[n];
    cout<<"Enter value of array:\n";
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    int **dp = new int*[n];
    for (int i = 0; i <n; ++i) {
        dp[i] = new int[n];
    }
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j <n ; ++j) {
            dp[i][j] = -1;
        }
    }
    int start = 0;
    int end= n-1;
    cout<<"Using Top Down Approach\n";
    cout<<"Maximum Cost is :"<<solveWine(ar,start,end,dp,1)<<'\n';

    cout<<"Using Bottom up Approach\n";
    cout<<"Maximum Cost is :"<<solveWine2(ar,n)<<'\n';
}