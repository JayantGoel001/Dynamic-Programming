#include<iostream>
#include <map>
using namespace std;
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
    if (canConstruct(ar,n,str,mp)) {
        cout << "YES";
    } else{
        cout<<"NO";
    }
}