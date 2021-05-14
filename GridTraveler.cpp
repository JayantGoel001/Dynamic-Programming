#include <iostream>
#include <map>
#define ll long long int
using namespace std;
// Time Complexity is O(nm) and Space Complexity is O(mn).
ll solveGridTraveler(int n,int m,map<pair<int,int>,ll> &mp){
    if (n==0 || m==0){
        return 0;
    }
    if (n==1 || m==1){
        return 1;
    }
    if(mp.count(make_pair(n,m))!=0){
        return mp[make_pair(n,m)];
    }
    if(mp.count(make_pair(m,n))!=0){
        return mp[make_pair(m,n)];
    }
    mp[make_pair(n,m)] = solveGridTraveler(n-1,m,mp) + solveGridTraveler(n,m-1,mp);
    mp[make_pair(m,n)] = mp[make_pair(n,m)];

    return mp[make_pair(n,m)];
}
// Time Complexity is O(nm) and Space Complexity is O(mn).
ll solveGridTraveler2(int n,int m){
    int dp[n+1][m+1];
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=m; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[1][1]= 1;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m; ++j) {
            if (i==1 || j==1){
                dp[i][j]=1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}
int main(){
    cout<<"Enter the value of n and m:\n";
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,ll> mp;
    cout<<"Using Top Down Approach:\n";
    cout<<"Fibonacci Number at "<<n<<" is : "<<solveGridTraveler(n,m,mp)<<'\n';

    cout<<"Using Bottom Up Approach:\n";
    cout<<"Fibonacci Number at "<<n<<" is : "<<solveGridTraveler2(n,m)<<"\n";
}