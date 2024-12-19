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

void insert_at_end(Node* &head, Node* &tail, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

bool are_lists_identical(Node* head1, Node* head2) {
    Node* tmp1 = head1;
    Node* tmp2 = head2;

    while (tmp1 != NULL && tmp2 != NULL) {
        if (tmp1->val != tmp2->val) {
            return false; 
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    return tmp1 == NULL && tmp2 == NULL;
}

int main() {
    Node* head1 = NULL, *tail1 = NULL;
    Node* head2 = NULL, *tail2 = NULL;

    while (true) {
        int value;
        cin >> value;
        if (value == -1) break;
        insert_at_end(head1, tail1, value);
    }

    while (true) {
        int value;
        cin >> value;
        if (value == -1) break;
        insert_at_end(head2, tail2, value);
    }

    if (are_lists_identical(head1, head2)) {
        cout << "YES" << endl;
    } 
    else {
        cout << "NO" << endl;
    }

    return 0;
}
