#include <iostream>
#include <vector>
#define int long long int
using namespace std;
// Time Complexity is O(n^2) And Space Complexity is O(n).
int LIS(const int *ar,int n,int *lis){
    for (int i = 0; i < n; ++i) {
        lis[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (ar[i]>ar[j] && lis[i]<lis[j]+1){
                lis[i]= lis[j] + 1;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result = max(result,lis[i]);
    }
    return result;
}
int32_t main(){
    cout<<"Enter The value of n:\n";
    int n;
    cin>>n;
    cout<<"Enter The value of array:\n";
    int *ar = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    int *lis = new int[n];
    int res = LIS(ar,n,lis);
    cout<<"Longest Increasing Sequence is : "<<res<<"\n";
    int prev= INT_MAX;
    vector<int> v;
    for (int i = n-1; i >=0; i--) {
        if (ar[i]<=prev && lis[i]==res){
            v.push_back(ar[i]);
            res--;
            prev = ar[i];
        }
    }
    cout<<"Sequence is :\n";
    for (int i = v.size()-1; i >=0 ; --i) {
        cout<<v[i]<<" ";
    }
}