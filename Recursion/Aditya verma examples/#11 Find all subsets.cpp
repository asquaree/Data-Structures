//ALL SUBSETS
/////////////////LIBRARIES///////////////////
#include<bits/stdc++.h>
using namespace std;
/////////////////////CLASSES//////////////////

//////////////U D FUNCTIONS//////////////////////////////
void all_subset(string ip,string op);
////////////////MAIN///////////////////////////////////
int main()
{
   string ip="abcd";
   string op="";
   all_subset(ip,op);
}

/////////////////////////OUTPUT///////////////////////////////
//dcba
//dcb
//dca
//dc
//dba
//db
//da
//d
//cba
//cb
//ca
//c
//ba
//b
//a
//
/////////////////////////FUNCTIONS//////////////////////////////
void all_subset(string ip,string op)
{
    if(ip.size()==0)
    {
        cout<<op<<"\n";
        return;
    }
    else
    {
        char last=ip[ip.size()-1];
        ip.pop_back();
        all_subset(ip,op+last);
        all_subset(ip,op);
    }

}
