#include <iostream>
#define int long long int
using namespace std;
int getMaximum(int *ar,int n){
    int maxi = -1;
    for (int i = 0; i < n; ++i) {
        maxi = max(maxi,ar[i]);
    }
    return maxi;
}
int getSum(const int *ar,int n){
    int sum=0;
    for (int i = 0; i < n; ++i) {
        sum+= ar[i];
    }
    return sum;
}
int getStudents(const int *ar,int n,int x){
    int total = 0;
    int students = 1;
    for (int i = 0; i < n; ++i) {
        total+=ar[i];
        if (total>x){
            total = ar[i];
            students++;
        }
    }
    return students;
}
// Time Complexity is O(N*log(sum(array))) And Space Complexity is O(N).
int allocation(int *ar,int n,int m){
    if (m>n){
        return -1;
    }
    int low = getMaximum(ar,n);
    int high = getSum(ar,n);
    while (low<high){
        int mid = (low+high)/2;
        int numberOfStudents = getStudents(ar,n,mid);
        if (numberOfStudents<=m){
            high = mid;
        } else{
            low = mid+1;
        }
    }
    return low;
}
int32_t main(){
    cout<<"Enter the value of n:\n";
    int n;
    cin>>n;
    cout<<"Enter the value of array:\n";
    int *ar = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    cout<<"Enter the value of m:\n";
    int m;
    cin>>m;
    cout<<"Minimum Number of Pages allocated to the student is : "<<allocation(ar,n,m)<<"\n";
}