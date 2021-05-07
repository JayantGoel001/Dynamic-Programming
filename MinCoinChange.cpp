#include <iostream>
#include <map>
#define ll long long int
using namespace std;
//Time Complexity is O(n*sum) and Space Complexity is O(n*sum).
ll minCoinChange(const int *ar,int n,int sum,map<int,ll> &mp){
    if (sum==0){
        return 0;
    }
    if (mp.count(sum)!=0){
        return mp[sum];
    }
    mp[sum] = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (sum>=ar[i]) {
            mp[sum] = min(mp[sum],1+minCoinChange(ar, n,sum - ar[i], mp));
        }
    }
    return mp[sum];
}
int main(){
    cout<<"Enter the value of n:\n";
    int n;
    cin>>n;
    int *ar = new int [n];
    cout<<"\nEnter the value of array:\n";
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    cout<<"\nEnter the sum to be searched :\n";
    int sum;
    cin>>sum;
    map<int,ll> mp;
    ll x = minCoinChange(ar,n,sum,mp);
    if (x>=0){
        cout<<x;
    } else{
        cout<<"Not Possible";
    }
}