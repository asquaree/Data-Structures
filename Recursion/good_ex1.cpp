//https://codeforces.com/problemset/problem/509/A
//solution

#include <bits/stdc++.h>

using namespace std;
int element(int row,int column);
int main()
{
    int n;
    cin>>n;
    cout<<element(n,n)<<endl;



}
int element(int row,int column)
{
    if(row==1 || column==1)
    {
        return 1;
    }
    return element(row-1,column) + element(row, column-1);
}



