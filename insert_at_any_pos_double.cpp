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
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void insert_at_any_pos(Node* head, int idx, int val)
{
    Node* newNode = new Node(val);
    Node* tmp = head;
    
    if (idx == 0)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    for (int i = 0; i < idx - 1 && tmp != NULL; i++)
    {
        tmp = tmp->next;
    }

    if (tmp == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    newNode->next = tmp->next;
    newNode->prev = tmp;
    if (tmp->next != NULL)
        tmp->next->prev = newNode;
    tmp->next = newNode;
}

int main()
{
    Node* head = new Node(10);
    Node* a = new Node(15);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    insert_at_any_pos(head, 2, 100);
    print_forward(head);

    return 0;
}
