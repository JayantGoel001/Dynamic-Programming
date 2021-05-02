#include <iostream>
#include <map>
using namespace std;
int solveGridTraveler(int n,int m,map<pair<int,int>,int> &mp){
    if (n==0 || m==0){
        return 0;
    }
    if (n==1 || m==1){
        return 1;
    }
    if(mp.count(make_pair(n,m))!=0){
        return mp[make_pair(n,m)];
    }
    mp[make_pair(n,m)] = solveGridTraveler(n-1,m,mp) + solveGridTraveler(n,m-1,mp);
    return mp[make_pair(n,m)];
}
int main(){
    cout<<"Enter the value of n and m:\n";
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,int> mp;
    cout<<solveGridTraveler(n,m,mp);
}