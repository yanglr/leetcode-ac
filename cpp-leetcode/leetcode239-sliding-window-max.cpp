#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> res;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> indexQ; // 双端队列，存储的是当前窗口最大值的索引，维护操作: 保持单调递减，队头是最大值

        cout << "Current deque:" << endl;
        for (int i = 0; i < nums.size(); i++) {
            // 依次地将数组元素加入到队列中
            // 注意: 确保队列元素间的距离都在k以内
            while (!indexQ.empty() && i - k + 1 > indexQ.front()) /* 倒着数第k个与队列开头数的index比较。窗口长度>k时，从队列中删掉最前面的数 */
                indexQ.pop_front();
            while (!indexQ.empty() && nums[i] >= nums[indexQ.back()])         
                indexQ.pop_back();  /* 不断地把左侧比自己小的数从队列中删掉, 遇到下一个比自己大的数时自己会被删掉 */
            
            indexQ.push_back(i);            
            for (int idx:indexQ)
            {
                cout << idx << "[" << nums[idx] << "]" << " ";
            }
            cout << endl;
            
            if (i >= k - 1)    // 只要窗口大小 ≥ k 时, 窗口就会有最大值，将其放进res(结果vector)中
            {
                res.push_back(nums[indexQ.front()]);
            }
        }

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto res = sol.maxSlidingWindow(nums, k);

    return 0;
}