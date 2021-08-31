#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class NumArray {
private:
    vector<int> preSum;    
public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        preSum.resize(len + 1);      
        for (int i=0; i < len; i++)
            preSum[i+1] = preSum[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        int res;
        if (left == 0 && right < preSum.size())
            res = preSum[right+1];
        if (left > 0 && right < preSum.size())
            res = preSum[right+1] - preSum[left];
        return res;
    }
};
/**
 * 你的 NumArray 对象会按如下方式进行初始化和调用:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Test
int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* arr = new NumArray(nums);
    int res1 = arr->sumRange(0, 2); // return 1 ((-2) + 0 + 3)
    cout << res1 << endl;
    int res2 = arr->sumRange(2, 5); /* return -1 (3 + (-5) + 2 + (-1)) */
    cout << res2 << endl;
    int res3 = arr->sumRange(0, 5); /* return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1)) */
    cout << res3 << endl;

    return 0;
}