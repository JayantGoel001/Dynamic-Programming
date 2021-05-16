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
int32_t main(){
    string str1,str2;
    cout<<"Enter String 1:\n";
    cin>>str1;
    cout<<"Enter String 2:\n";
    cin>>str2;
    map<pair<int,int>,int> mp;
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
}