#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        const int len = secret.size();
        unordered_map<char, int> dict;
        for (auto& ch : secret)
        {
            dict[ch]++;
        }
        int total = 0;
        for (auto& ch : guess)
        {
            if (dict[ch] > 0)
                total++;
            dict[ch]--;  /* 当前字符用1次后, 就从哈希表中删掉它 */
        }
        int bulls = 0;
        for (int i = 0; i < len; i++)
        {
            if (secret[i] == guess[i]) /* 对比两个字符串, 统计位置相同的字符的数量 */
                bulls++;
        }
        return to_string(bulls) + "A" + to_string(total - bulls) + "B";
    }
};

// Test
int main()
{
    Solution sol;
    string secret = "1122", guess = "2211";
    auto res = sol.getHint(secret, guess);
    cout << res << endl;

    return 0;
}