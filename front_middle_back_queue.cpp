#include <iostream>
#include <deque>
using namespace std;

class FrontMiddleBackQueue 
{
private:
    deque<int> left, right;

    void balance() 
    {
        if (left.size() > right.size() + 1) 
        {
            right.push_front(left.back());
            left.pop_back();
        } 
        else if (left.size() < right.size()) 
        {
            left.push_back(right.front());
            right.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) 
    {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) 
    {
        if (left.size() > right.size()) 
        {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
    }

    void pushBack(int val) 
    {
        right.push_back(val);
        balance();
    }

    int popFront() 
    {
        if (left.empty()) return -1;
        int val = left.front();
        left.pop_front();
        balance();
        return val;
    }

    int popMiddle() 
    {
        if (left.empty()) return -1;
        int val;
        if (left.size() == right.size()) 
        {
            val = left.back();
            left.pop_back();
        } 
        else 
        {
            val = left.back();
            left.pop_back();
        }
        balance();
        return val;
    }

    int popBack() 
    {
        if (right.empty() && left.empty()) return -1;
        int val;
        if (right.empty()) 
        {
            val = left.back();
            left.pop_back();
        } 
        else 
        {
            val = right.back();
            right.pop_back();
        }
        balance();
        return val;
    }
};

int main() 
{
    FrontMiddleBackQueue q;

    q.pushFront(1);   
    cout << "After pushFront(1): " << q.popFront() << endl; 

    q.pushBack(2);    
    cout << "After pushBack(2): " << q.popBack() << endl; 

    q.pushFront(1);  
    q.pushBack(2);    
    q.pushMiddle(3);  
    q.pushMiddle(4); 

    cout << "popFront(): " << q.popFront() << endl;  
    cout << "popMiddle(): " << q.popMiddle() << endl;
    cout << "popMiddle(): " << q.popMiddle() << endl; 
    cout << "popBack(): " << q.popBack() << endl;  
    cout << "popFront(): " << q.popFront() << endl;  

    return 0;
}
