#include<iostream>
#include<stack>
#include<ctime>
using namespace std;

class Solution
{
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    void push(int node)
	{
       stack1.push(node);
    }

    int pop()
	{
        int tempVal;
        if(stack2.empty()){
            while(!stack1.empty()){
                tempVal=stack1.top();
                stack2.push(tempVal);
                stack1.pop();
            }
        }
        tempVal=stack2.top();
        stack2.pop();
        return tempVal;
    }
};

// 以下为测试部分，加入了随机数
int main()
{
	Solution sol;

    srand((unsigned)time(NULL));
    rand();
    double feed=((double) rand()/(RAND_MAX)) + 1;  // 产生真正的随机数

	for(int idx=1;idx<=5;idx++)
	{
		sol.push(3.24*idx*feed);
	}
		cout<<sol.pop()<<endl;
		cout<<sol.pop()<<endl;
		cout<<sol.pop()<<endl;
		cout<<sol.pop()<<endl;
		cout<<sol.pop()<<endl;  // 由于新的队列中没有top()函数，但有返回值，故可以如此操作
	return 0;
}