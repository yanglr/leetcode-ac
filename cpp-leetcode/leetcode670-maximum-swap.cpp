#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> lastDict(10, 0);
        for (int i = 0; i < str.size(); ++i) {
            lastDict[str[i] - '0'] = i;  // 记录每个数最后出现位置的索引
        }
        /* 双指针，一个从原数字的头部开始，一个从索引表的末尾开始 */
        for (int i = 0; i < str.size(); ++i) {  /* 从原数字的头部向后扫，保证了尽量是高位 */
            for (int k = 9; k > str[i] - '0'; k--) {   /* 从dict的尾部向前扫，保证了尽量靠后且最大 */
                if (lastDict[k] > i)  /* 最大数字可能不止出现一次，希望能跟较低位的最大数交换 */
                {                    
                    swap(str[i], str[lastDict[k]]);
                    return stoi(str);
                }   
            }
        }
        
        return num;
    }
};

// Test
int main()
{
    Solution sol;
    int num = 2736;
    int res = sol.maximumSwap(num);           
    cout << res <<endl;
    return 0;
}