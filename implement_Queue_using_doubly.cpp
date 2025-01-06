#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) { // O(1)
        sz++;
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void pop() 
    { // O(1)
        if (head == NULL) return; 
        sz--;
        Node* deleteNode = head;
        head = head->next;
        if (head != NULL) 
        {
            head->prev = NULL;
        } 
        else 
        {
            tail = NULL; 
        }
        delete deleteNode;
    }

    int front() { // O(1)
        if (head == NULL) throw runtime_error("Queue is empty");
        return head->val;
    }

    int back() { // O(1)
        if (tail == NULL) throw runtime_error("Queue is empty");
        return tail->val;
    }

    int size() { // O(1)
        return sz;
    }

    bool empty() { // O(1)
        return head == NULL;
    }
};

int main() {
    myQueue q;
    int n;
    cout << "Enter the number of elements to push into the queue: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Queue size: " << q.size() << endl;

    cout << "Popping elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
