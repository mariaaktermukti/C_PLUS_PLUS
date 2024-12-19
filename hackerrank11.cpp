// get difference 
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
void insert_at_any_pos(Node* &head, int idx, int val) 
{
    Node* newnode = new Node(val);
    if (idx == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    Node* tmp = head;
    for (int i = 1; i < idx - 1 && tmp != NULL; i++) {
        tmp = tmp->next;
    }
    if (tmp == NULL) return;
    newnode->next = tmp->next;
    tmp->next = newnode;
}
void print_linked_list(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int find_max_min_difference(Node* head)
 {
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
    int value, pos = 1; 
    while (cin >> value && value != -1) {
        insert_at_any_pos(head, pos++, value);
    }
    cout << find_max_min_difference(head) << endl;

    return 0;
}
