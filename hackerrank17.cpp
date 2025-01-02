#include <bits/stdc++.h>
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

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) 
    {
        return true; 
    }

    Node* tail = head;
    while (tail->next != NULL) 
    {
        tail = tail->next;
    }

    Node* front = head;
    Node* back = tail;

    while (front != back && front->next != back) 
    {
        if (front->val != back->val) 
        {
            return false; 
        }
        front = front->next;
        back = back->prev;
    }

    return true;  
}

void insertEnd(Node*& head, int val) 
{
    Node* newNode = new Node(val);
    if (head == NULL) 
    {
        head = newNode;
    } 
    else 
    {
        Node* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;  
        
    }
}

int main() {
    Node* head = NULL;
    int value;

    while (cin >> value && value != -1)
    {
        insertEnd(head, value);
    }

    if (isPalindrome(head))
    {
        cout << "YES" << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}
