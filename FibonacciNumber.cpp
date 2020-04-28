#include<iostream>
using namespace std;
//Time Complexity O(n) And Space Complexity O(n)
int fibo(int n)
{
    int *ar=new int[n+1];
    ar[0]=0;
    ar[1]=1;
    for(int i=2;i<=n;i++)
    {
        ar[i]=ar[i-1]+ar[i-2];
    }
    return ar[n];
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"Fibonacci Number at "<<n<<" is :"<<fibo(n);
}
