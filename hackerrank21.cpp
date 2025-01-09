#include <iostream>
#include <stack>
#include <queue>
using namespace std;

string checkStackAndQueue(int n, int m, stack<int>& stk, queue<int>& que) 
{
    if (n != m) 
    {
        return "NO";
    }

    while (!stk.empty() && !que.empty()) 
    {
        int stackTop = stk.top();
        stk.pop();

        int queueFront = que.front();
        que.pop();

        if (stackTop != queueFront) 
        {
            return "NO";
        }
    }

    if (stk.empty() && que.empty()) 
    {
        return "YES";
    } 
    else 
    {
        return "NO";
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;

    stack<int> stk;
    queue<int> que;

    for (int i = 0; i < n; i++) 
    {
        int value;
        cin >> value;
        stk.push(value);
    }

    for (int i = 0; i < m; i++) 
    {
        int value;
        cin >> value;
        que.push(value);
    }

    cout << checkStackAndQueue(n, m, stk, que) << endl;

    return 0;
}
