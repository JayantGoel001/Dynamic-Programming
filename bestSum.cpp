#include<iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> bestSum(int *ar,int n,int sum,map<int,vector<int>> &mp){
    if (sum==0){
        vector<int> v;
        v.push_back(0);
        return v;
    }
    if (sum<0){
        return vector<int>();
    }
    if (mp.count(sum)!=0){
        return mp[sum];
    }

    vector<int> minLength;
    for (int i = 0; i < n; ++i) {
        int rem = sum - ar[i];
        vector<int> v = bestSum(ar,n,rem,mp);
        if (!v.empty()) {
            v.push_back(ar[i]);
            if (minLength.empty() || minLength.size() > v.size()) {
                minLength = v;
            }
        }
    }
    mp[sum] = minLength;
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
    map<int,vector<int>> mp;
    vector<int> v = bestSum(ar,n,sum,mp);
    if (!v.empty()) {
        for (int i = 1; i < v.size(); ++i) {
            cout<<v[i]<<" ";
        }
    } else{
        cout<<"NO";
    }
}