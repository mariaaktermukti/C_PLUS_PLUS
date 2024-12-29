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

void print_linked_list(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

void delete_at_tail(Node*& head, Node*& tail, int idx) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // If deleting the first node
    if (idx == 0) {
        Node* deleteNode = head;
        head = head->next;
        if (head == NULL) tail = NULL; // If list becomes empty, update tail
        delete deleteNode;
        return;
    }

    Node* tmp = head;
    for (int i = 1; i < idx; i++) {
        if (tmp->next == NULL || tmp->next->next == NULL) {
            cout << "Index out of bounds." << endl;
            return;
        }
        tmp = tmp->next;
    }

    // If deleting the last node
    if (tmp->next == tail) {
        Node* deleteNode = tail;
        tail = tmp;
        tail->next = NULL;
        delete deleteNode;
        return;
    }

    // Deleting a middle node
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while (1) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    int idx;
    cout << "Enter index to delete: ";
    cin >> idx;

    delete_at_tail(head, tail, idx);
    print_linked_list(head);

    return 0;
}
