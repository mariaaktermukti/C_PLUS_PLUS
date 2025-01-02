#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string address;
    Node* next;
    Node* prev;

    Node(string addr) {
        address = addr;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    DoublyLinkedList() {
        head = tail = current = nullptr;
    }

    void append(string address) {
        Node* newNode = new Node(address);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void visit(string address) {
        Node* temp = head;
        while (temp) {
            if (temp->address == address) {
                current = temp;
                cout << current->address << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Available" << endl;
    }

    void next() {
        if (current && current->next) {
            current = current->next;
            cout << current->address << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void prev() {
        if (current && current->prev) {
            current = current->prev;
            cout << current->address << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }
};

void processQueries(DoublyLinkedList& dll, int Q) {
    string command, address;
    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == "visit") {
            cin >> address;
            dll.visit(address);
        } else if (command == "next") {
            dll.next();
        } else if (command == "prev") {
            dll.prev();
        }
    }
}

int main() {
    DoublyLinkedList dll;

    string address;
    while (cin >> address && address != "end") {
        dll.append(address);
    }

    int Q;
    cin >> Q;

    processQueries(dll, Q);

    return 0;
}
