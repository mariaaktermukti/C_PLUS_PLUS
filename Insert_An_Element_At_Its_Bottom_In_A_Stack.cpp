#include <bits/stdc++.h> 
using namespace std;

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    if (myStack.empty()) 
    {
        myStack.push(x);
        return myStack;
    }
    int topElement = myStack.top();
    myStack.pop();

    pushAtBottom(myStack, x);

    myStack.push(topElement);

    return myStack;
}

int main() {
    int T; 
    cin >> T;

    while (T--) 
    {
        int N, X;
        cin >> N >> X; 

        stack<int> myStack;
        vector<int> elements(N);

        for (int i = 0; i < N; i++) 
        {
            cin >> elements[i];
        }

        for (int i = N - 1; i >= 0; i--) 
        {
            myStack.push(elements[i]);
        }

        myStack = pushAtBottom(myStack, X);

        vector<int> result;
        while (!myStack.empty()) 
        {
            result.push_back(myStack.top());
            myStack.pop();
        }

        reverse(result.begin(), result.end());
        for (int i : result) 
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
