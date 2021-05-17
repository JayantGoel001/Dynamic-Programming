#include <iostream>
#include <map>
#define int long long int
using namespace std;
// Time Complexity is O(mn) And Space Complexity is O(mn).
int LCS(const string& str1,const string& str2,int n,int m,map<pair<int,int>,int> &mp){
    if (mp.count(make_pair(n,m))!=0){
        return mp[make_pair(n,m)];
    }
    if (n==0 || m==0){
        mp[make_pair(n,m)] = 0;
        return mp[make_pair(n,m)];
    }
    if (str1[n-1]==str2[m-1]){
        mp[make_pair(n,m)] =  1+ LCS(str1,str2,n-1,m-1,mp);
        return mp[make_pair(n,m)];
    }
    mp[make_pair(n,m)] = max(LCS(str1,str2,n-1,m,mp), LCS(str1,str2,n,m-1,mp));
    return mp[make_pair(n,m)];
}
// Time Complexity is O(mn) And Space Complexity is O(mn).
int LCS2(const string& str1,const string& str2,int **dp){
    int n = str1.length();
    int m = str2.length();

    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=m; ++j) {
            if (i==0 || j==0){
                dp[i][j] = 0;
            } else if (str1[i-1]==str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
// Time Complexity is O(mn) And Space Complexity is O(m).
int LCS3(string str1,string str2){
    int n = str1.length();
    int m = str2.length();
    int dp[2][m+1];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=m; ++j) {
            if (str1[i-1]==str2[j-1]){
                dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
            }else{
                dp[i%2][j] = max(dp[i%2][j-1],dp[(i-1)%2][j]);
            }
        }
    }
    return dp[n%2][m];
}
int32_t main(){
    string str1,str2;
    cout<<"Enter String 1:\n";
    cin>>str1;
    cout<<"Enter String 2:\n";
    cin>>str2;
    map<pair<int,int>,int> mp;
    cout<<"Using Top Down Approach:\n";
    cout<<"Length of Longest Common Sequence is : "<<LCS(str1,str2,str1.length(),str2.length(),mp)<<"\n";
    int i = str1.length();
    int j = str2.length();
    string result;
    while (i>0 && j>0){
        if (str1[i-1] == str2[j-1]){
            result = str1[i-1] + result;
            i--;
            j--;
        } else if (mp[make_pair(i-1,j)]>mp[make_pair(i,j-1)]){
            i--;
        } else{
            j--;
        }
    }
    cout<<"Longest Common Sequence is : "<<result<<"\n";

    int n = str1.length();
    int m = str2.length();
    int **dp = new int*[n+1];
    for (int k = 0; k <= n; ++k) {
        dp[k] = new int[m+1];
    }

    cout<<"Using Bottom Up Approach:\n";
    cout<<"Length of Longest Common Sequence is : "<<LCS2(str1,str2,dp)<<"\n";
    result="";
    i = n;
    j = m;
    while (i>0 && j>0){
        if (str1[i-1] == str2[j-1]){
            result = str1[i-1] + result;
            i--;
            j--;
        } else if (dp[i-1][j]>dp[i][j-1]){
            i--;
        } else{
            j--;
        }
    }
    cout<<"Longest Common Sequence is : "<<result<<"\n";
    cout<<"Using Bottom Up Approach with Optimised Space:\n";
    cout<<"Length of Longest Common Sequence is : "<<LCS3(str1,str2)<<"\n";
}