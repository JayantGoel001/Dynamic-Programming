#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// Time Complexity is O(n^m) And Space Complexity is O(n^m).
vector<vector<string>> allConstruct(string *ar,int n,const string& str,map<string,vector<vector<string>>> &mp){
    if (str.empty()){
        return vector<vector<string>>(1,vector<string>());
    }
    if (mp.count(str)!=0){
        return mp[str];
    }
    vector<vector<string>> res = vector<vector<string>>();
    for (int i = 0; i < n; ++i) {
        if (str.substr(0,ar[i].length())==ar[i]){
            vector<vector<string>> v = allConstruct(ar,n,str.substr(ar[i].length()),mp);
            for (auto & j : v) {
                j.push_back(ar[i]);
                res.push_back(j);
            }
        }
    }
    mp[str] = res;
    return mp[str];
}
// Time Complexity is O(n^m) And Space Complexity is O(n^m).
vector<vector<string>> allConstruct2(string *ar,int n,const string& str){
    vector<vector<string>> dp[str.length()+1];
    dp[0] = vector<vector<string>>(1,vector<string>());
    for (int i = 1; i <=str.length() ; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i>=ar[j].length() && str.substr(i-ar[j].length(),ar[j].length())==ar[j] && !dp[i-ar[j].length()].empty()){
                for (int k = 0; k < dp[i-ar[j].length()].size(); ++k) {
                    dp[i].push_back(dp[i-ar[j].length()][k]);
                    dp[i][dp[i].size()-1].push_back(ar[j]);
                }
            }
        }
    }
    return dp[str.length()];
}
int main(){
    cout<<"Enter The value of n:\n";
    int n;
    cin>>n;
    cout<<"Enter The value of array:\n";
    auto *ar = new string [n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    cout<<"Enter The Target String:\n";
    string str;
    cin>>str;
    map<string ,vector<vector<string>>> mp;
    cout<<"Using Top Down Approach\n";
    vector<vector<string>> v = allConstruct(ar,n,str,mp);
    for (auto & i : v) {
        reverse(i.begin(),i.end());
    }
    for (auto & i : v) {
        for (auto & j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"Using Bottom Up Approach\n";
    v = allConstruct2(ar,n,str);
    for (auto & i : v) {
        for (auto & j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}