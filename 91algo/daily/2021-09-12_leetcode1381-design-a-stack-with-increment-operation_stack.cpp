#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int size;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        size = 0;
    }

    void push(int x) {
        if (size < stack.size())
        {
            stack[size] = x;
            size++;            
        }
    }
    /* 弹出栈顶元素，并返回栈顶的值，或栈为空时返回 -1  */
    int pop() {
        int res = -1;
        if (size > 0)
        {
            size--;
            res = stack[size];
        }

        return res;
    }
    /* 栈底的 k 个元素的值都增加 val 。如果栈中元素总数小于 k ，则栈中的所有元素都增加 val  */
    void increment(int k, int val) {
        for (int i = 0; i < min(k, size); i++)
            stack[i] += val;
    }
};

// Test
int main()
{
    int maxSize = 5;
    CustomStack *customStack = new CustomStack(3); // Stack 初始化为 [], 长度为3
    customStack->push(1);                          // 栈变为 [1]
    customStack->push(2);                          // 栈变为 [1, 2]
    customStack->push(8);                          // 栈变为 [1, 2, 8]
    int val1 = customStack->pop();                 // 返回栈顶值8, 栈变为 [1, 2]
    cout << val1 << endl;

    customStack->increment(2, 100); // 栈变为 [101, 102]

    return 0;
}