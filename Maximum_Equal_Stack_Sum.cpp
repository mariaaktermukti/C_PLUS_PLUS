#include <bits/stdc++.h>
using namespace std;

int maxSum(stack<int>& stk1, stack<int>& stk2, stack<int>& stk3) 
{
    int sum1 = 0, sum2 = 0, sum3 = 0;

    stack<int> temp1, temp2, temp3;

    while (!stk1.empty()) 
    {
        sum1 += stk1.top();
        temp1.push(stk1.top());
        stk1.pop();
    }
    while (!stk2.empty()) 
    {
        sum2 += stk2.top();
        temp2.push(stk2.top());
        stk2.pop();
    }
    while (!stk3.empty()) 
    {
        sum3 += stk3.top();
        temp3.push(stk3.top());
        stk3.pop();
    }
    while (!temp1.empty()) 
    {
        stk1.push(temp1.top());
        temp1.pop();
    }
    while (!temp2.empty())
    {
        stk2.push(temp2.top());
        temp2.pop();
    }
    while (!temp3.empty()) 
    {
        stk3.push(temp3.top());
        temp3.pop();
    }

    while (true) 
    {
        if (stk1.empty() || stk2.empty() || stk3.empty()) 
        {
            return 0;
        }

        if (sum1 == sum2 && sum2 == sum3) 
        {
            return sum1;
        }

        if (sum1 >= sum2 && sum1 >= sum3) 
        {
            sum1 -= stk1.top();
            stk1.pop();
        } 
        else if (sum2 >= sum1 && sum2 >= sum3) 
        {
            sum2 -= stk2.top();
            stk2.pop();
        } 
        else 
        {
            sum3 -= stk3.top();
            stk3.pop();
        }
    }
}

int main() {
    int T;
    cin >> T; 

    while (T--) 
    {
        stack<int> stk1, stk2, stk3;
        int x;

        while (cin >> x && x != -1) 
        {
            stk1.push(x);
        }
        while (cin >> x && x != -1) 
        {
            stk2.push(x);
        }
        while (cin >> x && x != -1) 
        {
            stk3.push(x);
        }

        cout << maxSum(stk1, stk2, stk3) << endl;
    }

    return 0;
}
