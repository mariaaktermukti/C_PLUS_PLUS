#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
       int val;
       Node* next;
       Node* prev;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }   
};
void print_forward(Node* head)
{
    Node* tmp=head;
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp=tmp->next;
    }
    cout << endl;
}

void insert_at_head(Node* &head,int val)
{
    Node* newnode= new Node(val);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

int main()
{
    Node* head= new Node(10);
    Node* a= new Node(20);
    Node* b= new Node(30);
    
    head->next=a;
    a->prev=head;

    a->next=b;
    b->prev=a;
     
     insert_at_head(head,100);
     insert_at_head(head,200);
    print_forward(head);
    return 0;
}
