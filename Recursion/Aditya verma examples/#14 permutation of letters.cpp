//permutation of letters
/////////////////LIBRARIES///////////////////
#include<bits/stdc++.h>
using namespace std;
/////////////////////CLASSES//////////////////

//////////////U D FUNCTIONS//////////////////////////////
void all_subset(string ip,string op);
////////////////MAIN///////////////////////////////////
int main()
{
    string ip="abc";
    string op="";
    all_subset(ip,op);
}

/////////////////////////OUTPUT///////////////////////////////
//CBA
//CBa
//CbA
//Cba
//cBA
//cBa
//cbA
//cba
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
        char low=tolower(last);
        char up=toupper(last);
        all_subset(ip,op+up);
        all_subset(ip,op+low);
    }

}
