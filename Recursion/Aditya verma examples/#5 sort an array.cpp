//sort an array using recursion
//////////////////////////LIBRARIES///////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
/////////////////////////U D FUNCTIONS/////////////////////////////////////
vector<int> sort(vector<int> &array);
vector<int> push_ele(vector<int> &array,int ele);
void print_vector(vector<int> a);
//////////////////////////////MAIN///////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a;
    a.push_back(5);
    a.push_back(9);
    a.push_back(2);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    a.push_back(7);
    a.push_back(0);
    print_vector(a);
    //5 9 2 1 2 3 5 7 7 0
    print_vector(sort(a));


}
/////////////OUTPUT/////////////////////////////////////////////////////
//0 1 2 2 3 5 5 7 7 9
//////////////FUNCTION//////////////////////////////////////////////////
vector<int> sort(vector<int> &array)
{
    //base condition
    if(array.size()==1)
    {
        return array;
    }
    else
    {
        int last_ele=array.back();
        array.pop_back();
        sort(array);
        push_ele(array,last_ele);
        return array;

    }

}
vector<int> push_ele(vector<int> &array,int ele)
{
    //base condition
    if(array.size()==0 || array.back()<=ele)
    {
        array.push_back(ele);
        return array;
    }
    else
    {
        int last_ele=array.back();
        array.pop_back();
        push_ele(array,ele);
        array.push_back(last_ele);
        return array;

    }
}

void print_vector(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
////////////////////END///////////////////////////////////////
