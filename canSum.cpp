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
        mp[rem] = canSum(ar,n,rem,mp);
        if (mp[rem]){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int *ar = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    int sum;
    cin>>sum;
    map<int,bool> mp;
    if (canSum(ar,n,sum,mp)) {
        cout << "YES";
    } else{
        cout<<"NO";
    }
}