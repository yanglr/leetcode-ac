#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0)
            sign = -1;        
        string str = to_string(x);
        std::reverse(str.begin(), str.end());  /* Leetcode的C++编译环境中出现了多个reverse函数，无法准确匹配到，所以需要加上std命名空间。 */
        long res = stol(str); /* 如果reverse后得到的字符串末尾有-，会在这里自动删除 */
        if(res < INT_MIN || res > INT_MAX)
            return 0;
        
        return sign*res;
    }
};

// Test
int main()
{
    Solution sol;
    int n = -666666666;
    auto res = sol.reverse(n);
    cout << res << endl;
    
    return 0;
}
