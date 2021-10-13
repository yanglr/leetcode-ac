#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * 4个数字全排列总共有24种可能, 判断每一种可能是否能组成合法时间值, 如果能, 再和当前保存的最大值进行比较；
     * 最大值是一个int值, 用来表示分钟数；
     */
    string largestTimeFromDigits(vector<int>& arr) {
        int largest = -1;
        // 依次暴力枚举出4个数
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    if(i == j || i == k || j == k) continue;
                    // 0,1,2,3 总和为6, 故剩下的index为6-three sum of index
                    int l = 6 - i - j - k;
                    
                    int res = composeTime(i, j, k, l, arr);
                    largest = max(largest, res);
                }
            }
        }        
        if(largest == -1) return "";

        string str1(5, '0');
        sprintf(&str1[0], "%02d:%02d", largest / 60, largest % 60);
        return str1;
    }
     /* 判断输入的四个数字按照输入顺序组成的时间是否合法, 如果合法, 返回分钟数 */
    int composeTime(int a, int b, int c, int d, vector<int>& nums)
    {
        int hours = nums[a] * 10 + nums[b];
        int min = nums[c] * 10 + nums[d];
        
        if(hours < 24 && min < 60)
            return hours * 60 + min;
        
        return -1;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 6, 6};
    auto res = sol.largestTimeFromDigits(nums);
    cout << res << endl;

    return 0;
}