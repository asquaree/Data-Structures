//print numbers from n->1
///////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////
void print_num(int n);
//////////////////////////////////////////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    print_num(7);
}
/////////////OUTPUT/////////////////////////////////////////////////////
//7 6 5 4 3 2 1 
//////////////FUNCTION//////////////////////////////////////////////////
void print_num(int n)
{
    //base condition
    if(n==0)
    {
        return;
    }
    else
    {
        cout<<n<<" ";
        print_num(n-1);
    }
}
///////////////////////////////////////////////////////////////////////
