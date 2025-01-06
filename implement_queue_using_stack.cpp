#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2; 

public:
    MyQueue() {}
    void push(int x) 
    {
        s1.push(x);
    }

    int pop() 
    {
        if (s2.empty()) 
        {
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) 
        {
            throw runtime_error("Queue is empty");
        }
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        if (s2.empty()) 
        {
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) 
        {
            throw runtime_error("Queue is empty");
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue myQueue;

    myQueue.push(1); 
    myQueue.push(2); 

    cout << "Front element: " << myQueue.peek() << endl; 

    cout << "Popped element: " << myQueue.pop() << endl; 

    cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl; 

    return 0;
}
