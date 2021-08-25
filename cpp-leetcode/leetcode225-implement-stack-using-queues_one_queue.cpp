#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

// Test
int main()
{
    MyStack *st = new MyStack();
    st->push(1);
    st->push(2);
    int res1 = st->top();   // 返回 2
    cout << res1 << endl;
    int res2 = st->pop();   // 返回 2
    cout << res2 << endl;
    bool isEmpty = st->empty(); // 返回 False
    cout << (isEmpty ? "False" : "True") << endl;

    return 0;
}