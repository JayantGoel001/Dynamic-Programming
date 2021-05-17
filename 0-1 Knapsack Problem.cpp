#include<iostream>
#include <vector>
#define int long long int
using namespace std;
// Time Complexity is O(2^n) And Space Complexity is O(n) in stack.
int knapsackRec(int *value,int *weight,int n,int W){
    if (n==0 || W==0){
        return 0;
    }
    if (weight[n-1]>W){
        return knapsackRec(value,weight,n-1,W);
    } else{
        return max(knapsackRec(value,weight,n-1,W),value[n-1] + knapsackRec(value,weight,n-1,W-weight[n-1]));
    }
}
// Time Complexity is O(n*W) And Space Complexity is O(n*W)
int knapsackTD(int *value,int *weight,int n,int W,int **dp){
    if (n==0 || W==0){
        dp[n][W] = 0;
        return dp[n][W];
    }
    if (dp[n][W]!=-1){
        return dp[n][W];
    }
    if (weight[n-1]>W){
        dp[n][W] = knapsackTD(value,weight,n-1,W,dp);
        return dp[n][W];
    } else{
        dp[n][W] = max(knapsackTD(value,weight,n-1,W,dp),value[n-1]+ knapsackTD(value,weight,n-1,W-weight[n-1],dp));
        return dp[n][W];
    }
}
// Time Complexity is O(n*W) And Space Complexity is O(n*W)
int knapsackBU(int *value,const int *weight,int n,int W){
    int **dp = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[W+1];
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=W; ++j) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <=W; ++j) {
            if (i==0 || j==0){
                dp[i][j] = 0;
            } else if (j>=weight[i-1]){
                dp[i][j] = max(dp[i-1][j],value[i-1] + dp[i-1][j-weight[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
// Time Complexity is O(n*W) And Space Complexity is O(2*W)
int knapsackBU1(int *value,const int *weight,int n,int W){
    int **dp = new int*[2];
    for (int i = 0; i <2; ++i) {
        dp[i] = new int[W+1];
    }
    for (int i = 0; i <2; ++i) {
        for (int j = 0; j <=W; ++j) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <=W; ++j) {
            if (i==0 || j==0){
                dp[i%2][j] = 0;
            } else if (j>=weight[i-1]){
                dp[i%2][j] = max(dp[(i-1)%2][j],value[i-1] + dp[(i-1)%2][j-weight[i-1]]);
            }else{
                dp[i%2][j] = dp[(i-1)%2][j];
            }
        }
    }
    return dp[n%2][W];
}
// Time Complexity is O(n*W) And Space Complexity is O(W)
int knapsackBU2(int *value,const int *weight,int n,int W){
    int *dp = new int[W+1];
    for (int j = 0; j <=W; ++j) {
        dp[j] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = W; j >=weight[i]; --j) {
            dp[j] = max(dp[j],value[i] + dp[j-weight[i]]);
        }
    }
    return dp[W];
}
//Time Complexity is O(n*W) And Space Complexity is O(n*W)
int UnboundedKnapsackBU(int *value,const int *weight,int n,int W){
    int **dp = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[W+1];
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=W; ++j) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=W; ++j) {
            if (i==0 || j==0){
                dp[i][j] = 0;
            } else if (j>=weight[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i][j-weight[i-1]]+value[i-1]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

//Time Complexity is O(n*W) And Space Complexity is O(W)
int UnboundedKnapsackBU2(int *value,const int *weight,int n,int W){
    int *dp = new int[W+1];
    for (int j = 0; j <=W; ++j) {
        dp[j] = 0;
    }
    for (int i = 0; i <n; ++i) {
        for (int j = weight[i]; j <=W; ++j) {
            dp[j] = max(dp[j],value[i] + dp[j-weight[i]]);
        }
    }
    return dp[W];
}

int32_t main(){
    int W;
    cout<<"Enter the value of knapsack capacity:\n";
    cin>>W;
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"Enter the values:\n";
    int *value=new int[n];
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    cout<<"Enter the weights of each item:\n";
    int *weight=new int[n];
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<"Maximum value obtained through recursion is "<<knapsackRec(value,weight,n,W)<<endl;
    int **dp = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        dp[i] = new int[W+1];
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=W; ++j) {
            dp[i][j] = -1;
        }
    }
    cout<<"Maximum value obtained through Dynamic Programming Top Down Approach is "<<knapsackTD(value,weight,n,W,dp)<<endl;
    cout<<"Maximum value obtained through Dynamic Programming Bottom Up Approach is "<<knapsackBU(value,weight,n,W)<<endl;
    cout<<"Maximum value obtained through Dynamic Programming Bottom Up Approach Optimised-1 is "<<knapsackBU1(value,weight,n,W)<<endl;
    cout<<"Maximum value obtained through Dynamic Programming Bottom Up Approach Optimised-2 is "<<knapsackBU2(value,weight,n,W)<<endl;

    cout<<"Unbounded Maximum value obtained through Dynamic Programming Bottom Up Approach is "<<UnboundedKnapsackBU(value,weight,n,W)<<endl;
    cout<<"Unbounded Maximum value obtained through Dynamic Programming Bottom Up Approach Optimised-2 is "<<UnboundedKnapsackBU2(value,weight,n,W)<<endl;
}