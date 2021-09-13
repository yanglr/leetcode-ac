#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
    int front;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty())
            front = x;
        
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty())
        {
            while (!s1.empty())
            { /* 把s1中的元素全部移到s2中 */
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();

        return res;
    }

    /** Get the front element. */
    int peek() {
        if (!s2.empty())
            return s2.top();

        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// Test
int main()
{
    MyQueue* q = new MyQueue();
    q->push(1);
    q->push(2);
    int val = q->peek();
    cout << val << endl;
    int val2 = q->pop();  // return 1, queue is [2]
    cout << val2 << endl;       
    bool isEmpty = q->empty();
    cout << (isEmpty ? "true" : "false") << endl;

    return 0;
}