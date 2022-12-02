#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *point;
};

class linked_list
{
    node *head= nullptr;
    node *tail= nullptr;

public:
    void Push_back(int v)
    {
        node *p = new node;
        p->data = v;
        p->point = nullptr;
        if(head == nullptr)
        {
            head = tail = p;
        }
        else
        {
            tail->point = p;
            tail = p;
        }
    }

    void Print()
    {
        node *p=head; // p = null
        cout << "-------------------------------------------\n";
        while(p != nullptr)
        {
            cout << p->data << ' ' << p->point << '\n';
            p = p->point;
        }
        cout << "-------------------------------------------\n";
    }
    void Push_front(int val)
    {
        node *p = new node ;
        p->data=val;
       // p->point=head;
        if(tail==nullptr)
        {
            tail=head =p ;
            p->point=nullptr;
        }
        else
        {
            p->point=head;
            head=p;
        }

    }
    void Pop_back()
    {
        node *r  ;
        r=head;

        if(head->point==nullptr)
        {
            delete tail ;
            head=tail=nullptr;
            return ;
        }
        while(r->point!=tail)
        {
            r=r->point;
        }
        r->point=nullptr;
        delete tail ;
        tail=r;
    }
    void Pop_front()
    {
        node *r;
        r=head;
        if(head->point==nullptr)
        {
            delete tail ;
            head=tail=nullptr;
            return ;
        }

        head=r->point ;
        delete r;

    }

    void Erase(node * p){
        if(p==head){Pop_front();return;}
        if(p==tail){Pop_back();return;}
        node *r;
        r=head;
        while(r->point!=p)
        {
            r=r->point;
        }
        r->point = p->point;
        delete p;
    }

    node * const Begin(){
        return head;
    }
    node * const End(){
        return tail;
    }

    node * Next(node *p , int pos=0){
        node *r=p;
        for(int i=0;i<pos;i++){
            r= r->point;
        }
        return r;
    }
    void Insert(node*p , int val)
    {
        if(p==head){Push_front(val);return;}
        if(p==tail){Push_back(val);return;}
        node *x=new node ;
        node *r=head;
        while(r->point!=p)
        {
            r=r->point;
        }
        x->data=val;
        x->point =r->point ;
        r->point=x ;
    }

    int Size(){
        if(head == nullptr) return 0;
        node *r=head;
        int cnt=1;
        while(r->point!= nullptr){
            cnt++;
            r=r->point;
        }
        return cnt;
    }

    void Clear(){
        node *p=head,*x;
        while(p != nullptr)
        {
            x=p;
            p = p->point;
            delete x;
        }
        head =tail =nullptr;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    linked_list ll;
    cout << ll.Size() << '\n' ;
    ll.Push_front(1);
    ll.Print();
    ll.Clear();
    ll.Print();
}