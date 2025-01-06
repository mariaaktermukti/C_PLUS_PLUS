#include <iostream>
#include <list>
using namespace std;

class myQueue {
public:
    list<int> l;

    void push(int val) 
    { 
        l.push_back(val);
    }

    void pop() 
    { 
        if (!l.empty())
            l.pop_front();
    }

    int front() 
    { 
        if (l.empty()) throw runtime_error("Queue is empty");
        return l.front();
    }

    int back() 
    {
        if (l.empty()) throw runtime_error("Queue is empty");
        return l.back();
    }

    int size() 
    { 
        return l.size();
    }

    bool empty() 
    { 
        return l.empty();
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
