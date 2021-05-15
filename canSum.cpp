#include <iostream>
#include <map>
using namespace std;
// Time Complexity is O(nm) And Space Complexity is O(nm).
bool canSum(int *ar,int n,int sum,map<int,bool> &mp){
    if (sum==0){
        return true;
    }
    if (sum<0){
        return false;
    }
    if (mp.count(sum)!=0){
        return mp[sum];
    }
    for (int i = 0; i < n; ++i) {
        int rem = sum-ar[i];
        if (canSum(ar,n,rem,mp)){
            mp[sum] = true;
            return mp[sum];
        }
    }
    mp[sum] = false;
    return mp[sum];
}
// Time Complexity is O(nm) And Space Complexity is O(nm).
bool canSum2(const int *ar,int n,int sum){
    int *dp = new int[sum+1];
    for (int i = 0; i <=sum; ++i) {
        dp[i] = false;
    }
    dp[0] = true;
    for (int i = 1; i <=sum; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i>=ar[j] && dp[i]== false){
                dp[i] = dp[i-ar[j]];
            }
        }
    }
    return dp[sum];
}
int main(){
    cout<<"Enter The value of n:\n";
    int n;
    cin>>n;
    cout<<"Enter The value of array:\n";
    int *ar = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    cout<<"Enter The value of sum:\n";
    int sum;
    cin>>sum;
    map<int,bool> mp;
    cout<<"Using Top Down Approach:\n";
    if (canSum(ar,n,sum,mp)) {
        cout << "YES\n";
    } else{
        cout<<"NO\n";
    }
    cout<<"Using Bottom Up Approach:\n";
    if (canSum2(ar,n,sum)) {
        cout << "YES\n";
    } else{
        cout<<"NO\n";
    }
}