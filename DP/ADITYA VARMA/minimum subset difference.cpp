//MINIMUM SUBSET SUM DIFFERENCE

//The difference can range from 0 to sum of all ele that it
//arr-2 3 5 2 8 10- max diff= {} {2 3 5 2 8 10} =30 min={8 2 5} {10 3 2}=0
//we will check from 0 difference.Like if sum =total/2 possible or not.then (total/2)-1 possible or not.like this

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
    int summ=0;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        summ+=arr[i];
    }



   // int summ;
    //cin>>summ;


    //RECURSION METHOD
    //cout<<recursion(n,arr,summ/2)<<"\n";//for this question ,recursion time complexity will be too high because we we have to check for sum/2 to 0.
    //thus its better to memorize the recursion results.

    //TOPDOWN
    cout<<summ-2*topdown(n,arr,summ/2)<<"\n";





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
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    
   for(int q=summ;q>=0;q--)
   {
       if(dp[n][q]==true)
       {
           return q;
       }
   }
    return 0;

}
