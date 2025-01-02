#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addNode(int val) {
        Node* newNode = new Node(val);
        if (!head) 
        {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    void reverse() {
        Node* i = head; 
        Node* j = tail; 

        while (i != j && i->prev != j) {
            swap(i->data, j->data);

            i = i->next; 
            j = j->prev;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);

    cout << "Original List: ";
    list.printList();

    list.reverse();

    cout << "Reversed List: ";
    list.printList();

    return 0;
}
