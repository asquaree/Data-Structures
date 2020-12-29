//print numbers from 1-n

#include<bits/stdc++.h>
using namespace std;

void print_num(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    print_num(n);

}


void print_num(int n)
{
    //base condition
    if(n==0)
    {
        return;
    }
    else
    {
        print_num(n-1);
        cout<<n<<" ";
    }


}
