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
    } 
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

int find_max_min_difference(Node* head) {
    if (head == NULL) return 0; 
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    Node* tmp = head;

    while (tmp != NULL) {
        maxVal = max(maxVal, tmp->val);
        minVal = min(minVal, tmp->val);
        tmp = tmp->next;
    }
    return maxVal - minVal;
}

int main() {
    Node* head = NULL; 
    Node* tail = NULL; 

    int value;
    while (cin >> value && value != -1) {
        insert_at_end(head, tail, value); 
    }
    
    cout << find_max_min_difference(head) << endl;

    return 0;
}
