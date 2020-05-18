#include<iostream>
using namespace std;
//Time Complexity is O(n) And Space Complexity is O(n)
int tileDomino(int n)
{
    int *a=new int[n+1];
    int *b=new int[n+1];
    a[0]=1;
    a[1]=0;
    b[0]=0;
    b[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-2]+2*b[i-1];
        b[i]=a[i-1]+b[i-2];
    }
    return a[n];

}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"The number of ways to fill 3X"<<n<<" with 2X1 are :"<<tileDomino(n);
}
