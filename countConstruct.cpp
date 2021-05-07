#include <iostream>
#include <map>
using namespace std;
// Time Complexity is O(n*m*m) And Space Complexity is O(m*m), where m is length of given string.
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
    cout<<countConstruct(ar,n,str,mp);
}