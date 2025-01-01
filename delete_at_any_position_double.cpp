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

void delete_at_position(Node*& head, int position) {
    if (head == NULL)
     { 
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (position <= 0) 
    {  
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 1) 
    { 
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1; ++i)
     { 
        if (temp->next == NULL)
         { 
            cout << "Position out of bounds." << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL)
     { 
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* deleteNode = temp->next; 
    temp->next = temp->next->next; 
    delete deleteNode;
}

void print_linked_list(Node* head) {
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
    Node* c = new Node(40);

    head->next = a;
    a->next = b;
    b->next = c;

    cout << "Before deletion:" << endl;
    print_linked_list(head);

    int position = 3;
    delete_at_position(head, position);

    cout << "After deletion at position " << position << ":" << endl;
    print_linked_list(head);

    return 0;
}
