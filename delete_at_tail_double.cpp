#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node*& head, int value) {
    Node* newnode = new Node(value);
    newnode->next = head;
    head = newnode; 
}

void delete_at_tail(Node*& head) {
    if (head == NULL) 
    { 
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == NULL)
     { 
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) 
    { 
        temp = temp->next;
    }

    Node* deleteNode = temp->next; 
    temp->next = NULL;
    delete deleteNode;
}

void print_linked_list(Node* head) 
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next = a;
    a->next = b;

    cout << "Before deletion at tail:" << endl;
    print_linked_list(head);

    delete_at_tail(head);

    cout << "After deletion at tail:" << endl;
    print_linked_list(head);

    return 0;
}
