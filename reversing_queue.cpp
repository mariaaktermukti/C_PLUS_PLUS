#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> q) {
    stack<int> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        queue<int> q;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            q.push(x);
        }

        queue<int> reversedQueue = reverseQueue(q);

        while (!reversedQueue.empty()) 
        {
            cout << reversedQueue.front() << " ";
            reversedQueue.pop();
        }
        cout << endl;
    }

    return 0;
}
