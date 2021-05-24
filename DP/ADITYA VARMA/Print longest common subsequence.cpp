//LONGEST COMMON SUBSEQUENCE
//X: ABCDE
//Y:ABFCE

//choice-ok longest DP

#include<bits/stdc++.h>
using namespace std;

int recursion(string x,string y,int n,int m);
string topdown(string x,string y,int n,int m);



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

   //cout<<recursion(x,y,n,m)<<"\n";

    //TOPDOWN
    cout<<topdown(x,y,n,m)<<"\n";

    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed<< time_taken << setprecision(5)<< " sec " << endl;


}

//RECURSION
int recursion(string x,string y,int n,int m)
{
   if(n==0 || m==0)
   {
       return 0;
   }


   if(x[n-1]==y[m-1])
   {
      return 1+recursion(x,y,n-1,m-1);

   }
   else
   {
       return max(recursion(x,y,n-1,m),recursion(x,y,n,m-1));
   }

}






//TOPDOWN
string topdown(string x,string y,int n,int m)
{
    string lcs;
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

            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    //return dp[n][m];

    int a=n;
    int b=m;

    while(a!=0 && b!=0)
    {
        if(x[a-1]==y[b-1])
        {
            lcs+=x[a-1];
            a--;
            b--;
        }
        else
        {
            if(dp[a-1][b]>dp[a][b-1])
            {
                a--;
            }
            else
            {
                b--;
            }
        }
    }

    reverse(lcs.begin(),lcs.end());

    return lcs;


}
