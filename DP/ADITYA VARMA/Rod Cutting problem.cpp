//ROD CUTTING PROBLEM

//Rod length-8
//length[1,2,3,4,5,6]
//price[1,5,8,9,12,17]

//cutt the rod in such a way that u can get maximum amount
//choice-ok binary tree-yes  DP

#include<bits/stdc++.h>
using namespace std;

int recursion(int n,int length[],int price[],int rod_len);
int memorization(int n,int length[],int price[],int rod_len);
int topdown(int n,int length[],int price[],int rod_len);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int rod_len;
    cin>>rod_len;



    int length[n];
    int price[n];

    for(int i=0;i<n;i++)
    {
        cin>>length[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }


    //RECURSION METHOD
    cout<<recursion(n,length,price,rod_len)<<"\n";

    //MEMORIATION
    cout<<memorization(n,length,price,rod_len)<<"\n";

    //TOPDOWN
    cout<<topdown(n,length,price,rod_len)<<"\n";





}

//RECURSION
int recursion(int n,int length[],int price[],int rod_len)
{
    if(rod_len==0||n==0)
    {
        return 0;
    }

    if(length[n-1]>rod_len)
    {
        return recursion(n-1,length,price,rod_len);
    }
    else
    {
        return max( recursion(n-1,length,price,rod_len) , price[n-1] + recursion(n,length,price,rod_len-length[n-1]) );
    }

}

//MEMORIZATION
int memorization(int n,int length[],int price[],int rod_len) {
    int dp[n + 1][rod_len + 1];
    memset(dp, -1, sizeof(dp));

    if (dp[n][rod_len] != -1) {
        return dp[n][rod_len];
    } else {
        if (n == 0 || length == 0) {
            return dp[n][rod_len] = 0;
        }
        if (length[n - 1] > rod_len) {
            return dp[n][rod_len] = memorization(n - 1, length, price, rod_len);
        } else {
            return dp[n][rod_len] = max(memorization(n - 1, length, price, rod_len),
                                        price[n - 1] + memorization(n, length, price, rod_len - length[n - 1]));
        }
    }

}
//TOPDOWN
int topdown(int n,int length[],int price[],int rod_len)
{
    int dp[n + 1][rod_len + 1];

    for (int i = 0; i <=n ; i++)
    {
        dp[i][0]=0;

    }
    for(int i=0;i<=rod_len;i++)
    {
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=rod_len;j++)
        {
            if(length[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j] , price[i-1] + dp[i][j-length[i-1]]);
            }
        }
    }

    return dp[n][rod_len];

}



