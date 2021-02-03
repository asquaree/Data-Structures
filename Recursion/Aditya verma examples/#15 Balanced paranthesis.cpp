//Balanced paranthesis
/////////////////LIBRARIES///////////////////
#include<bits/stdc++.h>
using namespace std;
/////////////////////CLASSES//////////////////

//////////////U D FUNCTIONS//////////////////////////////
void paranthesis(int brackets,string op,unordered_set<string> &all);
////////////////MAIN///////////////////////////////////
int main()
{
    int bracket;
    cin>>bracket;//3
    string op="()";
    unordered_set<string> all;
    paranthesis(bracket,op,all);
    for(auto i=all.begin();i!=all.end();i++)
    {
        cout<<*i<<'\n';
    }

}

/////////////////////////OUTPUT///////////////////////////////
//((()))
//(())()
//()(())
//()()()
//(()())
/////////////////////////FUNCTIONS//////////////////////////////
void paranthesis(int brackets,string op,unordered_set<string> &all)
{
    if(brackets==1)
    {
        //cout<<op<<"\n";
        all.insert(op);
        return;
    }
    else
    {
        string f1="()";
        string f2="(";
        string f3=")";
        paranthesis(brackets-1,f1+op,all);
        paranthesis(brackets-1,op+f1,all);
        paranthesis(brackets-1,f2+op+f3,all);
        return;

    }
}
