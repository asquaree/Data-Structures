// 0/1 KNAPSACK PROBLEM

//  W[]= 1 3 4 5
// V[]= 1 4 5 7
//SACK WEIGHT=7


//Choice-ok   optimal(max,min)-ok   DP

#include<bits/stdc++.h>
using namespace std;

int max_val_sack(int n,int w[],int v[],int weigh);
int memorization(int n,int w[],int v[],int weigh);
int topdown(int n,int w[],int v[],int weigh);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int w[n];

    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    int v[n];

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    int weigh;
    cin>>weigh;
    //RECURSION METHOD
    //cout<<max_val_sack(n,w,v,weigh)<<"\n";

    //MEMORIZATION
   // cout<<memorization(n,w,v,weigh)<<"\n";

    //TOPDOWN
    cout<<topdown(n,w,v,weigh)<<"\n";





}

//RECURSION
int max_val_sack(int n,int w[],int v[],int weigh)
{
    if(n==0|| weigh==0)
    {
        return 0;
    }
    else if(w[n-1]>weigh)
    {
        return max_val_sack(n-1,w,v,weigh);
    }
    else
    {
        return max(max_val_sack(n-1,w,v,weigh),v[n-1]+max_val_sack(n-1,w,v,weigh-w[n-1]));
    }

}

//MEMORIZATION

int memorization(int n,int w[],int v[],int weigh)
{
    int memo[n+1][weigh+1];
    memset(memo,-1,sizeof(memo));

    if(n==0 ||weigh==0)
    {
        memo[n][weigh]=0;
        return memo[n][weigh]=0;
    }
    else if(memo[n][weigh]!=-1)
    {
        return memo[n][weigh];
    }
    else
    {
        if(w[n-1]>weigh)
        {
            memo[n][weigh]=memorization(n-1,w,v,weigh);
            return memo[n][weigh];
        }
        else
        {
            memo[n][weigh]=max(memorization(n-1,w,v,weigh),v[n-1]+memorization(n-1,w,v,weigh-w[n-1]));
            return memo[n][weigh];
        }
    }
}

//TOPDOWN
int topdown(int n,int w[],int v[],int weigh)
{
    int dp[n+1][weigh+1];
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++)
    {
        dp[i][0]=0;

    }
    for(int i=0;i<weigh;i++)
    {
        dp[0][weigh]=0;

    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=weigh;j++)
        {
            if(w[i]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],v[i]+dp[i][j-w[i]]);
            }
        }
    }
    return dp[n][weigh];

}

