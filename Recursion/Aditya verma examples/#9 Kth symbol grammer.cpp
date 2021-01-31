//Kth symbol grammer
/////////////////LIBRARIES///////////////////
#include<bits/stdc++.h>
using namespace std;
/////////////////////CLASSES//////////////////

//////////////U D FUNCTIONS//////////////////////////////
int particular(int n,int k);
////////////////MAIN///////////////////////////////////
int main()
{
   int n,k;
   cin>>n>>k;
   /*row 1: 0
    row 2: 01
    row 3: 0110
    row 4: 01101001*/
   cout<<particular(n,k);
}

/////////////////////////OUTPUT///////////////////////////////
//1 or 0
/////////////////////////FUNCTIONS//////////////////////////////
int particular(int n,int k)
{
    if(n==1 || k==1)
    {
        return 0;
    }
    else
    {
        if(k>pow(2,n)/4)
        {
            if(particular(n-1,k-pow(2,n)/4)==1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return particular(n-1,k);
        }
    }
}
