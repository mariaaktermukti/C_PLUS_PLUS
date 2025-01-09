#include <iostream>
using namespace std;

class Stack 
{
private:
    struct Node 
    {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() 
    {
        if (isEmpty()) 
        {
            throw runtime_error("Stack is empty");
        }
        Node* temp = top;
        int value = temp->data;
        top = temp->next;
        delete temp;
        return value;
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }
};

class Queue 
{
private:
    struct Node 
    {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) 
    {
        Node* newNode = new Node(value);
        if (!rear) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            throw runtime_error("Queue is empty");
        }
        Node* temp = front;
        int value = temp->data;
        front = temp->next;
        if (!front) 
        {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    bool isEmpty() 
    {
        return front == nullptr;
    }
};

string checkStackAndQueue(int n, int m, int stackValues[], int queueValues[]) 
{
    if (n != m) 
    {
        return "NO";
    }

    Stack stk;
    Queue que;

    for (int i = 0; i < n; i++) 
    {
        stk.push(stackValues[i]);
        que.enqueue(queueValues[i]);
    }

    while (!stk.isEmpty()) 
    {
        if (stk.pop() != que.dequeue()) 
        {
            return "NO";
        }
    }

    if (stk.isEmpty() && que.isEmpty()) 
    {
        return "YES";
    } 
    else 
    {
        return "NO";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int* stackValues = new int[n];
    int* queueValues = new int[m];

    for (int i = 0; i < n; i++) 
    {
        cin >> stackValues[i];
    }

    for (int i = 0; i < m; i++) 
    {
        cin >> queueValues[i];
    }

    cout << checkStackAndQueue(n, m, stackValues, queueValues) << endl;

    delete[] stackValues;
    delete[] queueValues;

    return 0;
}
