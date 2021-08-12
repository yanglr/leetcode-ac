#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        long long count = pow(2, len);  /* 子集总的数量 */
        vector<vector<int>> res { {} };  // 空集必然是其中一个子集, 所以直接就在初始化放进来了
        for (int i = 1; i < count; i++) {
            vector<int> curSet;
            string str = toBinary(i); // 转为二进制的字符串
            int curLen = str.size();
            if (len - curLen > 0)     /* 如果位数不够会在左侧填补上字符'0' */
                str.insert(str.begin(), len - curLen, '0');  
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] == '1')
                    curSet.push_back(nums[j]);
            }
            res.push_back(curSet);
        }        
        return res;
    }

    string toBinary(long n)  /* 将非负整数转为二进制串 */
    {
        string res = "";
        while (n > 0)
        {
            char r = n % 2 + '0';
            res.push_back(r);   
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }    
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 1,2,3 };
    auto res = sol.subsets(nums);

    return 0;
}