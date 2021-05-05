//SUBSET SUM PROBLEM

//ARR-2 3 7 8 10
//SUM=11
//FIND 11 IS POSSIBLE OR NOT

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

