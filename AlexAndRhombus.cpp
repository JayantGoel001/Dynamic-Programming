#include<iostream>
#include<math.h>
using namespace std;
//Time Complexity is O(n) And Space Complexity is O(n)
int main()
{
    int n;
    cin>>n;
    int *ar=new int[n];
    ar[0]=1;
    for(int i=1;i<n;i++)
    {
        ar[i]=4*i+ar[i-1];
    }
    cout<<ar[n-1];
}
