//COIN CHANGE PROBLEM II

//coins:[1 2 3]
//sum: 5

//find the minimum no of coins to make the sum

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
    if(n==0)
    {
        return INT_MAX-1;
    }
   if(sum==0 && n!=0)
   {
       return 0;
   }
   if(n==1 && sum!=0)
   {
       if(sum%coins[0]==0)
       {
           return sum/coins[0];
       } else{
           return INT_MAX-1;
       }
   }

    if(coins[n-1]>sum)
    {
        return recursion(sum,coins,n-1);
    }
    else
    {
        return min(recursion(sum,coins,n-1) , 1+recursion(sum-coins[n-1],coins,n));
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
        if(n==0)
        {
            return dp[n][sum]=INT_MAX-1;
        }
        if(sum==0 && n!=0)
        {
            return dp[n][sum]=0;
        }
        if(n==1 && sum!=0)
        {
            if(sum%coins[0]==0)
            {
                return dp[n][sum]=sum/coins[0];
            } else{
                return dp[n][sum]=INT_MAX-1;
            }
        }

        if(coins[n-1]>sum)
        {
            return dp[n][sum]=memorization(sum,coins,n-1);
        }
        else
        {
            return dp[n][sum]= min(memorization(sum,coins,n-1) ,1+memorization(sum-coins[n-1],coins,n));
        }

    }

}
//TOPDOWN
int topdown(int sum,int coins[],int n)
{
    int dp[n + 1][sum+ 1];

    for (int i = 1; i <=n ; i++)
    {
        dp[i][0]=0;

    }
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=INT_MAX-1;
    }

    for(int i=1;i<=sum;i++)
    {
        if(i%coins[0]==0)
        {
            dp[1][i]=i/coins[0];
        }
        else
        {
            dp[1][i]=INT_MAX;
        }
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=sum;j++)
        {
            if(coins[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j] ,1+dp[i][j-coins[i-1]]);
            }
        }
    }

    return dp[n][sum];

}



