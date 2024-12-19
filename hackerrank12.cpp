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

int find_value(Node* head, int x) {
    int index = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        if (tmp->val == x) {
            return index;
        }
        tmp = tmp->next;
        index++;
    }
    return -1; 
}

int main() {
    int T; 
    cin >> T;
    while (T--) {
        Node* head = NULL;
        Node* tail = NULL;

        while (true) {
            int value;
            cin >> value;
            if (value == -1) break;
            insert_at_end(head, tail, value);
        }

        int X;
        cin >> X;
        
        cout << find_value(head, X) << endl;
    }
    return 0;
}
