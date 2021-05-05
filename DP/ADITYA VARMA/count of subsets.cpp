//COUNT OF SUBSET SUM PROBLEM PROBLEM

//arr-2 3 5 6 8 10 sum-10
// 2 3 5,2 8,10----3

//choice-ok  DP

#include<bits/stdc++.h>
using namespace std;

int recursion(int n,int arr[],int summ);
int topdown(int n,int arr[],int summ);

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


    int summ;
    cin>>summ;

    //RECURSION METHOD
    cout<<recursion(n,arr,summ)<<"\n";

    //TOPDOWN
    cout<<topdown(n,arr,summ)<<"\n";





}

//RECURSION
int recursion(int n,int arr[],int summ)
{
    if(summ==0)
    {
        return 1;
    }
    else if(n==0 && summ!=0)
    {
        return 0;
    }

    if(arr[n-1]>summ)
    {
        return recursion(n-1,arr,summ);
    } else{
        return (recursion(n-1,arr,summ) + recursion(n-1,arr,summ-arr[n-1]));
    }

}

//MEMORIZATION



//TOPDOWN
int topdown(int n,int arr[],int summ)
{
    int dp[n+1][summ+1];
    // memset(dp,-1,sizeof(dp));

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;

    }
    for(int i=1;i<=summ;i++)
    {
        dp[0][i]=0;

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
                dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=summ;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[n][summ];

}
