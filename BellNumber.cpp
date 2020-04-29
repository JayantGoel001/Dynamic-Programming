#include<iostream>
using namespace std;
//Time Complexity is O(n^2) And Space Complexity is O(n^2)
int bellDP(int num)
{
    int **ar=new int*[num+1];
    for(int i=0;i<num+1;i++)
    {
        ar[i]=new int[num+1];
    }

    for(int i=0;i<=num;i++)
    {
        for(int j=0;j<=num;j++)
        {
            ar[i][j]=0;
        }
    }
    ar[0][0]=1;
    for(int i=1;i<=num;i++)
    {
        ar[i][0]=ar[i-1][i-1];
        for(int j=1;j<=i;j++)
        {
            ar[i][j]=ar[i][j-1]+ar[i-1][j-1];
        }
    }
    return ar[num-1][num-1];
}
//Time complexity is exponential And Space Complexity is O(n) in Stack
int bellRec(int i,int j)
{
    if(i==0 && j==0)
    {
        return 1;
    }
    else if(j==0)
    {
        return bellRec(i-1,i-1);
    }
    else
    {
        return bellRec(i-1,j-1)+bellRec(i,j-1);
    }

}
int main()
{
    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    cout<<"The bell number at Using DP "<<n<<" is: "<<bellDP(n)<<endl;
    cout<<"The bell number at Using Recursion "<<n<<" is: "<<bellRec(n-1,n-1);
}
