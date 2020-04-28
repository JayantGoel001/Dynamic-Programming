#include<iostream>
#include<math.h>
using namespace std;
long long int comb(int x)
{
    long long int res=1L;
    for(int i=x+1;i<=2*x;i++)
    {
        res*=i;
    }
    for(int i=1;i<=x;i++)
    {
        res/=i;
    }
    return res;
}
//Time Complexity O(n) And Space Complexity O(1)
long long int catNum(int n)
{
    return (comb(n)/(n+1));
}

//Exponential Time Complexity  And Space Complexity O(1)
long long int catNumRec(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=catNumRec(i)*catNumRec(n-i-1);
        }
        return sum;
    }
}
//Time Complexity is O(n) And Space Complexity is O(n)
long long int catNumDP(int n)
{
    long long int *ar=new long long int[n+1];
    ar[0]=1;
    for(int i=1;i<=n;i++)
    {
        ar[i]=(ar[i-1]*(2*i)*(2*i-1))/(i*(i+1));
    }
    return ar[n];
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    cout<<"Catalan Number through Formula : "<<catNum(n)<<endl;
    cout<<"Catalan Number through Recursion : "<<catNumRec(n)<<endl;
    cout<<"Catalan Number through DP : "<<catNumDP(n)<<endl;
}
