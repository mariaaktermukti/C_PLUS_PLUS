//palindrome
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() 
    {
        head = tail = nullptr;
    }


    void insert(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    bool isPalindrome() 
    {
        if (head == nullptr) return true; 
        Node* left = head;
        Node* right = tail;

        while (left != right && left->prev != right) 
        {
            if (left->data != right->data) 
            {
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        return true;
    }

   
    void printList() 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    int value;
    while (cin >> value) 
    {
        if (value == -1) 
            break;
        dll.insert(value);
    }

    if (dll.isPalindrome()) 
    {
        cout << "YES" << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}
