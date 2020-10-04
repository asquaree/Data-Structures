//https://codeforces.com/contest/189/problem/A
#include<bits/stdc++.h>

int max_cut(int n,int a,int b,int c);
using namespace std;
using ll=long long int;
int main()
{
    int n;
    int a,b,c;
    cin>>n>>a>>b>>c;
    int arr[3];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    sort(arr,arr+3);
    int count=0;
    //cout<<"min ele:"<<arr[0]<<endl;
    if(n%arr[0]==0)
    {
        count=n/arr[0];
        cout<<count<<endl;
        return 0;
    }

    cout<<max_cut(n,arr[0],arr[1],arr[2]);


}


int max_cut(int n,int a,int b,int c)
{
    int mxcut[n];
    for(int i=-1;i>=(-1*c);i--)//c is max
    {
        mxcut[i]=-1;
    }
    mxcut[0]=0;


    for(int i=1;i<=n;i++)
    {
        /*
        int x,y,z;
        x=i-a;
        y=i-b;
        z=i-c;
        if(x<0)
        {
            mxcut[x]=-1;
        }
        if(y<0)
        {
            mxcut[y]=-1;
        }
        if(z<0)
        {
            mxcut[z]=-1;
        }
      
        */
         if(max(max(mxcut[i-a],mxcut[i-b]),mxcut[i-c])==-1)
        {
            mxcut[i]=-1;
        } else{
            mxcut[i]=1+max(max(mxcut[i-a],mxcut[i-b]),mxcut[i-c]);
        }
        //cout<<i<<" "<<"length ke liye"<<mxcut[i]<<endl;

    }
    return mxcut[n];
}


//17(5 3 2)=1+max(maxcut(17-5=12),maxcut(17-3=12),maxcut(17-2)=15)
//1-0 a[1]=-1;
//a[2]=1;
//a[3]=1+if(max(maxcut=-1)) a[3]=-1;
//a[4]=1+max(macut(a[2]))=2;
