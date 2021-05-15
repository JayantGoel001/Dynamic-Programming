#include <iostream>
#include <map>
using namespace std;
// Time Complexity is O(n*m^m) And Space Complexity is O(m*m), where m is length of given string.
int countConstruct(string *ar,int n,const string& str,map<string,int> &mp){
    if (str.empty()){
        return 1;
    }
    if (mp.count(str)!=0){
        return mp[str];
    }
    mp[str] = 0;
    for (int i = 0; i < n; ++i) {
        if (str.substr(0,ar[i].size())==ar[i]){
            mp[str] += countConstruct(ar,n,str.substr(ar[i].size()),mp);
        }
    }
    return mp[str];
}
// Time Complexity is O(n*m^m) And Space Complexity is O(m*m), where m is length of given string.
int countConstruct2(string *ar,int n,const string& str){
    int dp[str.length()+1];
    for (int i = 0; i <=str.length(); ++i) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 1; i <=str.length() ; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i>=ar[j].length() && str.substr(i-ar[j].length(),ar[j].length())==ar[j] && dp[i-ar[j].length()]>0){
                dp[i] +=dp[i-ar[j].length()];
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
    map<string ,int> mp;
    cout<<"Using Top Down Approach:\n";
    cout<<countConstruct(ar,n,str,mp)<<"\n";
    cout<<"Using Bottom Up Approach:\n";
    cout<<countConstruct2(ar,n,str);
}