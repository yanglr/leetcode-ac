#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        if (words.empty()) return "";
        
        string best = "";  // best表示当前最长目标词
        unordered_set<string> st(words.begin(), words.end());  // 取出所有的key 放进 set

        for (auto& word : words)
        {
            if ((word.size() < best.size()) || (word.size() == best.size() && word > best)) /* word > best 表示按题意来的留下字典序小的, 删掉字典序较大的 */
                continue;       /* 剪枝 pruning */
            
            bool isValid = true;
            string prefix;
            for (int i = 0; i < word.length() - 1 && isValid; i++)
            {
                prefix.push_back(word[i]);
                if (st.count(prefix) == 0)  /* 如果一直有效, 其子串应该一直在set中 */
                    isValid = false;                
            }
            if (isValid)
                best = word;            
        }
        
        return best;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    // vector<string> words = { "yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y" };
    // vector<string> words = { "r","kt","jtgt","j","jtg","rdwy","chkext","c","l","zo","lnp","k","jt","chke","ktui","rd","jtgtha","ch","chkex" };
    // vector<string> words = {"b", "br", "bre", "brea", "break", "breakf", "breakfa", "breakfas", "breakfast", "l", "lu", "lun", "lunc", "lunch", "d", "di", "din", "dinn", "dinne", "dinner"};
    auto res = sol.longestWord(words);
    cout << res << endl;
    
    return 0;
}