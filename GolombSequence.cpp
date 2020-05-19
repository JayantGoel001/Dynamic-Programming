#include<iostream>
using namespace std;
//Time Complexity is O(n) And Space Complexity is O(n)
int generateGolombSeq(int n)
{
    int *gs=new int[n];
    gs[0]=1;
    for(int i=1;i<n;i++)
    {
        gs[i]=1+gs[i-gs[gs[i-1]-1]];
    }
    for(int i=0;i<n;i++)
    {
        cout<<gs[i]<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"Golomb Sequence is :\n";
    generateGolombSeq(n);
}
