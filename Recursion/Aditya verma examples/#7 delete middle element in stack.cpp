//delete middle element of a stack
//////////////////////////LIBRARIES///////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
///////////////////////////////CLASSES/////////////////////////////////////
class Stack1
{
    int top;
public:
    int a[MAX];
    Stack1()
    {
        top=-1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};

bool Stack1::push(int x)
{
    if(top>=MAX-1)
    {
        cout<<"Stack overflow";
    } else{
        top++;
        a[top]=x;
    }
}
int Stack1::pop()
{
    if(top<0)
    {
        cout<<"stack underflow"<<'\n';
        return 0;
    }
    else
    {
        int x=a[top];
        top--;
        return x;
    }
}
int Stack1::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
bool Stack1::isEmpty()
{
    return (top < 0);
}
int Stack1::size()
{
    return top+1;
}
/////////////////////////U D FUNCTIONS/////////////////////////////////////
void delete_middle(Stack1 *s,int size);
//////////////////////////////MAIN///////////////////////////////////////
int main()
{
    Stack1 s;
    s.push(5);
    s.push(8);
    s.push(1);
    s.push(3);
    s.push(7);
    s.push(1);
    //5 8 1 3 7 1
    delete_middle(&s,s.size());
    while(!s.isEmpty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
}
/////////////OUTPUT/////////////////////////////////////////////////////
//1 7 3 8 5
//////////////FUNCTION//////////////////////////////////////////////////
void delete_middle(Stack1 *s,int size)
{
    if(s->size()==size/2 || s->size()==1)
    {
        s->pop();
        return;
    }
    else
    {
        int tp_ele=s->peek();
        s->pop();
        delete_middle(s,size);
        s->push(tp_ele);
        return;

    }
}
////////////////////END///////////////////////////////////////
