#include<iostream>
using namespace std;
int divBy(int n,int x)
{
    while(n%x==0)
    {
        n/=x;
    }
    return n;
}
bool isUgly(int n)
{
    n=divBy(n,2);
    n=divBy(n,3);
    n=divBy(n,5);
    if(n==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Time Complexity O(n) and Space Complexity O(1)
int uglyNumber(int  n)
{
    int c=0;
    int i=0;
    while(c!=n)
    {
        i++;
        if (!isUgly(i))
            continue;
        c++;

    }
    return i;

}
//Time Complexity O(n) and Time Complexity O(n)
int uglyNumberDp(int n)
{
    int *ar=new int[n];
    int i2=0;
    int i3=0;
    int i5=0;
    int next2=2;
    int next3=3;
    int next5=5;
    ar[0]=1;
    for(int i=1;i<n;i++)
    {
        int minDiv=min(next2,min(next3,next5));
        ar[i]=minDiv;
        if(minDiv==next2)
        {
            i2++;
            next2=2*ar[i2];
        }
        if(minDiv==next3)
        {
            i3++;
            next3=3*ar[i3];
        }
        if(minDiv==next5)
        {
            i5++;
            next5=5*ar[i5];
        }
    }
    return ar[n-1];


}
int main()
{
    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    cout<<"Using Simple Approach :\n";
    cout<<uglyNumber(n)<<endl;
    cout<<"Using DP :\n";
    cout<<uglyNumberDp(n)<<endl;
}
