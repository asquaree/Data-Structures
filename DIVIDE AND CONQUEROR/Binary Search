//
// Created by AAKASH on 13-09-2020.
//

#include<bits/stdc++.h>
using namespace std;
int bs(vector<long long int> a,long long int b_ele,int l,int h);
int main()
{
    int n,k;
    cin>>n;

    vector<long long int> a;
    vector<long long int> b;

    for(int i=0;i<n;i++)
    {
        long long int z;
        cin>>z;
        a.push_back(z);
    }
    cin>>k;
    for(int i=0;i<k;i++)
    {
        long long int z;
        cin>>z;
        b.push_back(z);
    }

    for(int i=0;i<b.size();i++)
    {
        cout<<bs(a,b[i],0, n-1)<<" ";
    }
}
//USING RECURSION 
int bs(vector<long long int> a,long long int b_ele,int l,int h)
{
    
    if(h<l)
    {
       
        return -1;
    }

    int mid=(l+h)/2;
   
    if(a[mid]==b_ele)
    {
        return mid;
    }
    else if(b_ele<a[mid])
    {
        h=mid-1;
        return bs(a,b_ele,l,h);
    } else{
        l=mid+1;
        return bs(a,b_ele,l,h);
    }

}
//USING WHILE LOOP(FAST)
int bs(vector<long long int> a,long long int b_ele,int l,int h)
{
    
    while(h>=l)
    {
         int mid=(l+h)/2;
        if(a[mid]==b_ele)
       {
        return mid;
      }
       else if(b_ele<a[mid])
      {
        h=mid-1;
      }
      else
      {
        l=mid+1;
      }   
   }
   return -1;
}

