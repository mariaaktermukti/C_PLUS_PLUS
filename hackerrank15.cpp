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

void remove_duplicates(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* final = current;
        while (final->next != NULL) {
            if (final->next->val == current->val) {
                Node* duplicate = final->next;
                final->next = final->next->next;
                delete duplicate;
            } else {
                final = final->next;
            }
        }
        current = current->next;
    }
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

    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        insert_at_tail(head, tail, val);
    }

    remove_duplicates(head);

    print_linked_list(head);

    return 0;
}
