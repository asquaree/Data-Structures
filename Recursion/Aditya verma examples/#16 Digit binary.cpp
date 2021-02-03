//N digit binary
/////////////////LIBRARIES///////////////////
#include<bits/stdc++.h>
using namespace std;
/////////////////////CLASSES//////////////////

//////////////U D FUNCTIONS//////////////////////////////
void binary(int n,string op,unordered_set<string> &all,int extra);
////////////////MAIN///////////////////////////////////
int main()
{
    int n;
    cin>>n;//4
    string op="1";
    int extra=1;
    unordered_set<string> all;
    binary(n,op,all,extra);
    for(auto i=all.begin();i!=all.end();i++)
    {
        cout<<*i<<'\n';
    }

}

/////////////////////////OUTPUT///////////////////////////////
//1100
//1010
//1101
//1011
//1111
//1110
/////////////////////////FUNCTIONS//////////////////////////////
void binary(int n,string op,unordered_set<string> &all,int extra)
{
    if(n==1)
    {
        //cout<<op<<"\n";
        all.insert(op);
        return;
    }
    else
    {
        if(extra>0)
        {
            binary(n-1,op+"1",all,extra+1);
            binary(n-1,op+"0",all,extra-1);
            binary(n-1,"1"+op,all,extra+1);
        }
        else
        {
            binary(n-1,"1"+op,all,extra+1);
            binary(n-1,op+"1",all,extra+1);
        }

        return;

    }
}
