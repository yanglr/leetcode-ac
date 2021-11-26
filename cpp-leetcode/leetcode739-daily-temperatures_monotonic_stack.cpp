#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        /* 单调递减的单调栈: 存所有待处理的元素的index
			有一个栈, 每次来一个新元素T[i], 就将它与栈顶元素比较, 如果 T[i] > st.top, 就将栈顶元素出栈, 否则就将(当前元素的index)入栈, 栈内的各个index对应的原数组中的数是单调递减的。
		*/
        const int len = T.size();
        vector<int> res(len); /* 由于每个元素初始化为0, 而不存在更大的数时题目要求返回0, 所有不存在更大的数时不需要额外处理了 */
        deque<int> st;
        for (int i = 0; i < len; i++)
        {
            while (!st.empty() && T[i] > T[st.back()])
            {
                res[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    auto res = sol.dailyTemperatures(T);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}