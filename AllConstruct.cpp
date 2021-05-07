#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

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
}