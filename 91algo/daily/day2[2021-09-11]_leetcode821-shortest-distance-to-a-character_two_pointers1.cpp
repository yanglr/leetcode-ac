#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> gaps(s.size());
        vector<char> chars(s.begin(), s.end());

        for (int i = 0; i < chars.size(); i++)
        {
            // 如果当前字符就是要搜索的字符c, 距离为 0
            if (chars[i] == c) gaps[i] = 0;
            else /* 否则分别向左、向右找最近的字符c */
            {
                int leftDistance = INT_MAX, rightDistance = INT_MAX;
                for (int left = i; left >= 0; left--)
                {
                    if (chars[left] == c) // 向左找, 找到第一个
                    {
                        leftDistance = i - left;
                        break;
                    }
                }
                for (int right = i; right < chars.size(); right++) // 向右找, 找到第一个
                {
                    if (chars[right] == c)
                    {
                        rightDistance = right - i;
                        break;
                    }
                }
                gaps[i] = min(leftDistance, rightDistance);
            }
        }

        return gaps;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "loveleetcode";
    char c = 'e';
    auto res = sol.shortestToChar(s, c);
    for (auto &num : res)
        cout << num << endl;

    return 0;
}