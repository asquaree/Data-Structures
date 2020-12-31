//find height of a binary tree
//////////////////////////LIBRARIES///////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
///////////////////////////////CLASSES/////////////////////////////////////
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};
/////////////////////////U D FUNCTIONS/////////////////////////////////////
int height(Node *root);
//////////////////////////////MAIN///////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);

    cout<<height(root);
}
/////////////OUTPUT/////////////////////////////////////////////////////
//4
//////////////FUNCTION//////////////////////////////////////////////////
int height(Node *root)
{
    //base condition
   if(root==NULL)
   {
       return 0;
   }
   else
   {
       Node *leftroot,*rightroot;
       leftroot=root->left;
       rightroot=root->right;
       return 1+max( height(leftroot),height(rightroot) );
   }
}
////////////////////END///////////////////////////////////////
