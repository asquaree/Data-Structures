//print factorial of n
///////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////
int factorial(int n);
//////////////////////////////////////////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<factorial(7);
}
/////////////OUTPUT/////////////////////////////////////////////////////
//5040
//////////////FUNCTION//////////////////////////////////////////////////
int factorial(int n)
{
    //base condition
    if(n==1)
    {
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
///////////////////////////////////////////////////////////////////////
