#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2; // 辅助队列
    
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q1.size();
        while (size > 1) { // 将q1 导入q2，但要留下最后一个元素
            q2.push(q1.front());
            q1.pop();
            size--;
        }

        int res = q1.front(); 
        q1.pop();
        
        q1 = q2;                // 将q2赋值给q1
        while (!q2.empty())     // 清空q2
            q2.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
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