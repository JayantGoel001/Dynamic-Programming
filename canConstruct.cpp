#include<iostream>
#include <map>
using namespace std;
// Time Complexity is O(n*m^2) And Space Complexity is O(m).
bool canConstruct(string *ar,int n,const string& str,map<string,bool> &mp){
    if (str.empty()){
        return true;
    }
    if (mp.count(str)!=0){
        return mp[str];
    }
    for (int i = 0; i < n; ++i) {
        string res = str.substr(0,ar[i].length());
        if (res==ar[i]) {
            if (canConstruct(ar,n,str.substr(ar[i].length()),mp)){
                mp[str] = true;
                return mp[str];
            }
        }
    }
    mp[str] = false;
    return mp[str];
}
// Time Complexity is O(n*m^2) And Space Complexity is O(m).
bool canConstruct2(string *ar,int n,const string& str){
    bool dp[str.length()+1];
    for (int i = 0; i <= str.length(); ++i) {
        dp[i] = false;
    }
    dp[0] = true;
    for (int i = 1; i <=str.length(); ++i) {
        if (!dp[i]){
            for (int j = 0; j < n; ++j) {
                if (i>=ar[j].length() && str.substr(i-ar[j].length(),ar[j].length())==ar[j] && dp[i-ar[j].length()]){
                    dp[i] = true;
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
    map<string ,bool> mp;
    cout<<"Using Top Down Approach:\n";
    if (canConstruct(ar,n,str,mp)) {
        cout << "YES";
    } else{
        cout<<"NO";
    }
    cout<<"\nUsing Bottom Up Approach:\n";
    if (canConstruct2(ar,n,str)) {
        cout << "YES";
    } else{
        cout<<"NO";
    }
}