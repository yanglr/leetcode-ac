#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        // 题意: 将原字符数组写成(letter+count)形式, 如果count是1不用写, 形式: lc, count的位数可能是1,2... */
        int left = 0, right = 0; /* 指针right: 0 -> len - 1, 指针left: 指向需要更新字符值位置的index */
        int len = chars.size();
        while (right < len)
        {
            int preRight = right; // preRight是连续重复字符区域的第1个字符的index
            while (right < len && chars[right] == chars[preRight]) /* 只要right扫描到的值还是和之前的一样, 就继续前移 */
                right++;
            
            int repeatCount = right - preRight;
            chars[left] = chars[preRight];  /* left处的字符需要更新为right遍历过的字符, 也能写出chars[left] = chars[right - 1]; */
            if (repeatCount == 1)  /* count为1时, 无需操作原数组 */
                left++;
            else if (repeatCount <= 9)
            {
                chars[left + 1] = repeatCount + '0';
                left += 2; /* 假如没新发现一个count>1的字符, 则left += 1, 如果发现一个1位的, 那么移动2位... */
            }
            else
            {
                string countStr = to_string(repeatCount);
                for (int i = 0; i < countStr.size(); i++)
                    chars[left + 1 + i] = countStr[i];
                left += countStr.size() + 1;  /* 若没新发现一个count>1的字符, 则left += 1, 如果发现一个k位的, 那么移动k+1位... */
            }
        }
        return left;
    }
};

// Test
int
main()
{
    Solution sol;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    auto res = sol.compress(chars);
    cout << res << endl;

    return 0;
}