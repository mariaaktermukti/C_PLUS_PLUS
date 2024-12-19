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

void insert_at_head(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
    if (tail == NULL) {
        tail = newnode;
    }
}

void insert_at_tail(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void delete_at_index(Node*& head, Node*& tail, int idx) {
    if (head == NULL) return; 

    if (idx == 0) 
    { 
        Node* tmp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL; 
        }
        delete tmp;
        return;
    }

    Node* tmp = head;
    int count = 0;
    while (count < idx - 1 && tmp->next != NULL) 
    { 
        tmp = tmp->next;
        count++;
    }

    if (tmp->next == NULL) return; 

    Node* deleteNode = tmp->next;
    tmp->next = deleteNode->next;

    if (deleteNode == tail) {
        tail = tmp; 
    }

    delete deleteNode;
}

void print_linked_list(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int Q;
    cin >> Q;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            insert_at_head(head, tail, V);
        } 
        else if (X == 1) {
            insert_at_tail(head, tail, V);
        } 
        else if (X == 2) {
            delete_at_index(head, tail, V);
        }

        print_linked_list(head);
    }

    return 0;
}
