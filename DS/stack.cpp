#include <bits/stdc++.h>
using namespace std;
//stack
struct node
{
    int val;
    node * pointer;
};
class Stack{
    node *top= nullptr ;
    int sz=0;
public :
    void push(int ele)
    {
        node* p=new node ;
        p->pointer=top;
        p->val=ele ;
        top=p;
        sz++;
    }
    int Top ()
    {
        return top->val ;
    }
    void pop()
    {
        if(sz<=0) return;
        node * temp=top ;
        top=top->pointer;
        delete temp ;
        sz--;

    }
    int Size()
    {
        return sz;
    }
    bool Empty()
    {
        return !sz;
    }
    void emplace (int ele)
    {
        top->val=ele;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Stack s ;
    s.push(5) ;
    s.emplace(20);
    cout<<s.Empty()<<"\n";

}