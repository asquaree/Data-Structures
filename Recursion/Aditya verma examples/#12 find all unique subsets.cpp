//all unique subsets
/////////////////LIBRARIES///////////////////
#include<bits/stdc++.h>
using namespace std;
/////////////////////CLASSES//////////////////

//////////////U D FUNCTIONS//////////////////////////////
void all_subset(string ip,string op,unordered_set<string> &unique);
////////////////MAIN///////////////////////////////////
int main()
{
   string ip="aba";
   string op="";
    unordered_set<string> unique;
   all_subset(ip,op,unique);
   for(auto i=unique.begin();i!=unique.end();i++)
   {
       cout<<*i<<'\n';
   }
}

/////////////////////////OUTPUT///////////////////////////////
//ab
//aa
//aba
//ba
//a
//b
/////////////////////////FUNCTIONS//////////////////////////////
void all_subset(string ip,string op,unordered_set<string> &unique)
{
    if(ip.size()==0)
    {
        //cout<<op<<"\n";
        unique.insert(op);
        return;
    }
    else
    {
        char last=ip[ip.size()-1];
        ip.pop_back();
        all_subset(ip,op+last,unique);
        all_subset(ip,op,unique);
    }

}
