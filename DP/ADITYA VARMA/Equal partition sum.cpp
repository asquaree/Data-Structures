//wqual partition PROBLEM

//ARR-2 3 7 8 10
//EQUAL PARTITION FALSE
//ARR- 1 3 5 6 7 8
//TRUE-3 5 6 1     7 8

//choice-ok  DP

#include<bits/stdc++.h>
using namespace std;

bool recursion(int n,int arr[],int summ);
bool topdown(int n,int arr[],int summ);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    bool ans;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    int summ=0;
    for(int i=0;i<n;i++)
    {
        summ+=arr[i];
    }
   // cout<<summ<<"\n";
    if(summ%2!=0)
    {
        cout<<"1"<<'\n';
    }
    else{
        //RECURSION METHOD
        cout<<recursion(n,arr,summ/2)<<"\n";

        //TOPDOWN
        cout<<topdown(n,arr,summ/2)<<"\n";

    }





}

//RECURSION
bool recursion(int n,int arr[],int summ)
{
    if(summ==0)
    {
        return true;
    }
    else if(n==0 && summ!=0)
    {
        return false;
    }

    if(arr[n-1]>summ)
    {
        return recursion(n-1,arr,summ);
    } else{
        return (recursion(n-1,arr,summ) || recursion(n-1,arr,summ-arr[n-1]));
    }

}

//MEMORIZATION



//TOPDOWN
bool topdown(int n,int arr[],int summ)
{
    bool dp[n+1][summ+1];
    // memset(dp,-1,sizeof(dp));

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;

    }
    for(int i=1;i<=summ;i++)
    {
        dp[0][i]=false;

    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=summ;j++)
        {
            if(arr[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=(dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            }
        }
    }
    return dp[n][summ];

}
