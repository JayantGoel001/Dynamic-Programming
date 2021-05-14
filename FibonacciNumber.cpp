#include<iostream>
#include <map>
using namespace std;
//Time Complexity O(n) And Space Complexity O(n)
int fibonacci(int n){
    int *ar=new int[n+1];
    ar[0]=0;
    ar[1]=1;
    for(int i=2;i<=n;i++){
        ar[i]=ar[i-1]+ar[i-2];
    }
    return ar[n];
}
// Time Complexity is O(n) and Space Complexity is O(n)
int fibonacci2(int n, map<int, int> &mp){
    if (mp.count(n)!=0){
        return mp[n];
    }
    if (n==1 || n==0){
        mp[n] = n;
        return mp[n];
    }
    mp[n] = fibonacci2(n-1,mp) + fibonacci2(n-2,mp);
    return mp[n];
}
int main(){
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"Using Bottom Up Approach:\n";
    cout<<"Fibonacci Number at "<<n<<" is :"<<fibonacci(n)<<"\n";
    map<int,int> mp;
    cout<<"Using Top Down Approach:\n";
    cout<<"Fibonacci Number at "<<n<<" is :"<<fibonacci2(n,mp);
}
