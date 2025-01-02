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
    int size;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    void insert(int index, int value) {
        
        if (index < 0 || index > size) {
            cout << "Invalid" << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (index == 0) {
            if (head == nullptr) { 
                head = tail = newNode;
            } else { 
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        } else if (index == size) {  
            if (tail == nullptr) {  
                head = tail = newNode;
            } else { 
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        } else {  
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != nullptr) {
                temp->prev->next = newNode;
            }
            temp->prev = newNode;
        }

        size++; 
        printLeftToRight();
        printRightToLeft();
    }

    void printLeftToRight() {
        Node* temp = head;
        cout << "L -> ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printRightToLeft() {
        Node* temp = tail;
        cout << "R -> ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    int Q;
    cin >> Q;

    DoublyLinkedList dll;

    for (int i = 0; i < Q; i++) {
        int X, V;
        cin >> X >> V;
        dll.insert(X, V);
    }

    return 0;
}
