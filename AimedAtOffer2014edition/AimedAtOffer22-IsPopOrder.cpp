#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	if(pushV.size() == 0 || popV.size() == 0)
        return false;  // 如果其中一个序列长度为0，则不合题意，返回false
    stack<int> s; 

	int k=0;
	for(int i=0;i<pushV.size();i++)
	{
		if(pushV[i] != popV[k])
		{
			s.push(pushV[i]);    // 压栈，直至栈顶元素等于输出队列
		}
		else {
		k++;
		while (!s.empty() && s.top()==popV[k])
		{
			s.pop();   // 输出序列和栈顶一致，继续
			k++;
		}
	  }
    }
		if(k==popV.size()) return true;  // 压完所有输入后，相等，判断结果为：是出栈序列
		return false; // 仍不等，则判断结果为：不是出栈序列
}
};

// 以下为测试部分
int main()
{
	Solution sol;
	int in[] = {1,2,3,4,5};
	int a[] = {4,5,3,2,1};
    int b[] = {4,3,5,1,2};
	vector<int> invec(in,in+5);
	vector<int> vec1(a,a+5);
	vector<int> vec2(b,b+5);

	//vector<int> invec(0);
	//vector<int> vec1(0);
	//vector<int> vec2(0);

	cout<<"Is the sequence possible pop order ?: "<<sol.IsPopOrder(invec,vec1)<<endl;
	cout<<"Is the sequence possible pop order ?: "<<sol.IsPopOrder(invec,vec2)<<endl;
	return 0;
}
