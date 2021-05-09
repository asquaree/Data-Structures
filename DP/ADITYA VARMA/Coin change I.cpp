//COIN CHANGE PROBLEM I

//coins:[1,2,3]
//sum=5;
//find max no. of ways of getting sum;

#include<bits/stdc++.h>
using namespace std;

int recursion(int sum,int coins[],int n);
int memorization(int sum,int coins[],int n);
int topdown(int sum,int coins[],int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int sum;
    cin>>sum;



    int coins[n];

    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }



    //RECURSION METHOD
    cout<<recursion(sum,coins,n)<<"\n";

    //MEMORIATION
    cout<<memorization(sum,coins,n)<<"\n";

    //TOPDOWN
    cout<<topdown(sum,coins,n)<<"\n";





}

//RECURSION
int recursion(int sum,int coins[],int n)
{
    if(sum==0)
    {
        return 1;
    }
   if(n==0 && sum!=0)
   {
       return 0;
   }

    if(coins[n-1]>sum)
    {
        return recursion(sum,coins,n-1);
    }
    else
    {
        return recursion(sum,coins,n-1) + recursion(sum-coins[n-1],coins,n);
    }

}

//MEMORIZATION
int memorization(int sum,int coins[],int n)
{
    int dp[n+1][sum+1];
    memset(dp,-1,sizeof(dp));

    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    else
    {
        if(sum==0)
        {
            return dp[n][sum]=1;
        }
        if(n==0 && sum!=0)
        {
            return dp[n][sum]=0;
        }

        if(coins[n-1]>sum)
        {
            return dp[n][sum]=memorization(sum,coins,n-1);
        }
        else
        {
            return dp[n][sum]=memorization(sum,coins,n-1) + memorization(sum-coins[n-1],coins,n);
        }

    }

}
//TOPDOWN
int topdown(int sum,int coins[],int n)
{
    int dp[n + 1][sum+ 1];

    for (int i = 0; i <=n ; i++)
    {
        dp[i][0]=1;

    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
    }

    return dp[n][sum];

}



