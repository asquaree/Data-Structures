//LONGEST COMMON SUBSTRING
//X: ABCDE
//Y:ABFCE

//choice-ok longest DP

#include<bits/stdc++.h>
using namespace std;

int recursion(string x,string y,int n,int m,int *mx1 );
int memorization(string x,string y,int n,int m,int *mx1);
int topdown(string x,string y,int n,int m);

int memo[1000][1000];

int main()
{
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   string x,y;
   cin>>x>>y;

   int n=x.size();
   int m=y.size();
    //RECURSION METHOD
    int mx1=0;
    recursion(x,y,n,m,&mx1);
    cout<<mx1<<"\n";

    //MEMORIZATION
    int mx2=0;
   // memset(memo,-1,sizeof(memo));

    //memorization(x,y,n,m,&mx1);
    //cout<<mx1<<"\n";

    //TOPDOWN
    //cout<<topdown(x,y,n,m)<<"\n";

    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed<< time_taken << setprecision(5)<< " sec " << endl;


}

//RECURSION
int recursion(string x,string y,int n,int m,int *mx1 )
{
   if(n==0 || m==0)
   {
       return 0;
   }

   int temp=0;
   if(x[n-1]==y[m-1])
   {
      // cout<<x[n-1]<<" "<<y[]
       temp=1+recursion(x,y,n-1,m-1,mx1);
       *mx1=max(temp,*mx1);
       recursion(x,y,n-1,m,mx1);
       recursion(x,y,n,m-1,mx1);

       return temp;
   }
   else
   {
       recursion(x,y,n-1,m,mx1);
       recursion(x,y,n,m-1,mx1);
       return 0;
   }

}

//MEMORIZATION
int memorization(string x,string y,int n,int m,int *mx1)
{
    if(memo[n][m]!=-1)
    {
        *mx1=max(*mx1,memo[n][m]);
        return memo[n][m];
    }
    else
    {
        if(n==0 || m==0)
        {
            return memo[n][m]=0;
        }

        int temp=0;
        if(x[n-1]==y[m-1])
        {
            // cout<<x[n-1]<<" "<<y[]
            memo[n-1][m-1]=memorization(x,y,n-1,m-1,mx1);
            memo[n][m]=1+memo[n-1][m-1];
            *mx1=max(memo[n][m],*mx1);
            memo[n-1][m]=memorization(x,y,n-1,m,mx1);
            memo[n][m-1]=memorization(x,y,n,m-1,mx1);

            return memo[n][m];
        }
        else
        {
            memo[n-1][m]=memorization(x,y,n-1,m,mx1);
            memo[n][m-1]=memorization(x,y,n,m-1,mx1);
            return 0;
        }

    }

}




//TOPDOWN
int topdown(string x,string y,int n,int m)
{
    int mx=0;
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                mx=max(mx,dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }

    return mx;


}
