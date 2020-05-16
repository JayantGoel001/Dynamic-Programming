#include<iostream>
#include<math.h>
using namespace std;

//Time Complexity is O(t*n^2) and Space Complexity is O(n)
int main()
{
    int n;
    int t;
    cout<<"Enter number of test Case:\n";
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Enter the number of elements:\n";
        cin>>n;
        int *ar=new int[n];
        cout<<"Enter the value of array:\n";
        for(int j=0;j<n;j++)
        {
            cin>>ar[j];
        }
        int *cumsum=new int[n];
        cumsum[0]=ar[0];
        for(int j=1;j<n;j++)
        {
            cumsum[j]=cumsum[j-1]+ar[j];
        }
        bool w=false;
        for(int j=0;j<n && w==false;j++)
        {
            int x=cumsum[j];
            if(x%2==0)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(cumsum[k]%2==0)
                    {
                        w=true;
                        cout<<k-j<<endl;
                        for(int l=j+1;l<=k;l++)
                        {
                            cout<<l+1<<" ";
                        }
                        cout<<endl;
                        break;
                    }
                }
            }
            else
            {
                for(int k=j+1;k<n;k++)
                {
                    if(cumsum[k]%2==1)
                    {
                        w=true;
                        cout<<k-j<<endl;
                        for(int l=j+1;l<=k;l++)
                        {
                            cout<<l+1<<" ";
                        }
                        cout<<endl;
                        break;
                    }

                }
            }
        }
        if(w==false)
        {
            int x=0;
            for(int j=0;j<n;j++)
            {
                if(cumsum[j]%2==0)
                {
                    w=true;
                    cout<<j-x+1<<endl;
                    for(int k=0;k<=j;k++)
                    {
                        cout<<k+1<<" ";
                    }
                    cout<<endl;
                }
            }
            if(w==false){
                cout<<"-1"<<endl;
            }

        }
    }

}
