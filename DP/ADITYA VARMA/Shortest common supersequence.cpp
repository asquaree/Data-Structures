//SHORTEST COMMON SUPERSEQUENCE
//X: ABCDE
//Y:ABFCE
//ABCE--ABFCDE
//aakashaggarwal
//aakanshagga
//SUBSEQUENCE PLUS KUCH AUR TO OFC DP


#include<bits/stdc++.h>
using namespace std;

int recursion(string x,string y,int n,int m);
string topdown2(string x,string y,int n,int m);
string topdown1(string x,string y,int n,int m);



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

    //TOPDOWN1
   // cout<<topdown1(x,y,n,m)<<"\n";
    //TOPDOWN2
    cout<<topdown2(x,y,n,m)<<"\n";


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


//TOPDOWN1
string topdown1(string x,string y,int n,int m)
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



//TOPDOWN2
string topdown2(string x,string y,int n,int m)
{
    int x_strt,y_strt,x_end,y_end;
    string lcs;
    string dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        dp[i][0]="";
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]="";
    }


    int st=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {

                dp[i][j]=dp[i-1][j-1]+x[i-1];
                if(st==0)
                {
                    x_strt=i-1;
                    y_strt=j-1;
                    st=1;
                }
                else
                {
                    x_end=i-1;
                    y_end=j-1;
                }


            }
            else
            {
                if(dp[i-1][j].size()>dp[i][j-1].size())
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    lcs=dp[n][m];
    cout<<lcs<<"\n";

    cout<<x_strt<<" "<<y_strt<<" "<<x_end<<" "<<y_end<<"\n";

    string scs;
    scs+=x.substr(0,x_strt)+y.substr(0,y_strt);

    int sz=lcs.size();
    scs.push_back(lcs[0]);
    int cnt=1;

    int x_ind=x_strt+1;
    int y_ind=y_strt+1;
    while(cnt<sz)
    {
        while(x[x_ind]!=lcs[cnt])
        {
            scs+=x[x_ind];
            x_ind++;
        }
        while(y[y_ind]!=lcs[cnt])
        {
            scs+=y[y_ind];
            y_ind++;
        }
        scs.push_back(lcs[cnt]);
        cnt++;
        x_ind++;
        y_ind++;
    }
    scs.push_back(lcs[cnt]);
    scs+=x.substr(x_end+1,n-x_end+1)+y.substr(y_end+1,n-y_end+1);

    return scs;





}
