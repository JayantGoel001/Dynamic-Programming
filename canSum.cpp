#include <iostream>
#include <map>
using namespace std;
bool canSum(int *ar,int n,int sum,map<int,bool> &mp){
    if (sum==0){
        return true;
    }
    if (sum<0){
        return false;
    }
    if (mp.count(sum)!=0){
        return mp[sum];
    }
    for (int i = 0; i < n; ++i) {
        int rem = sum-ar[i];
        if (canSum(ar,n,rem,mp)){
            mp[sum] = true;
            return mp[sum];
        }
    }
    mp[sum] = false;
    return mp[sum];
}
int main(){
    cout<<"Enter The value of n:\n";
    int n;
    cin>>n;
    cout<<"Enter The value of array:\n";
    int *ar = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    cout<<"Enter The value of sum:\n";
    int sum;
    cin>>sum;
    map<int,bool> mp;
    if (canSum(ar,n,sum,mp)) {
        cout << "YES";
    } else{
        cout<<"NO";
    }
}