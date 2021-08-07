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
        auto cmp = [](const string& s1, const string& s2) /* 签名使用const string& 代替string会变快一点 */
        {
            if (s1.size() != s2.size())
                return s1.size() > s2.size();
            return s1 < s2;
        };        
        sort(words.begin(), words.end(), cmp);  

        string best = "";  // best表示当前最长目标词
        unordered_set<string> st(words.begin(), words.end());  // 取出所有的key 放进 set        
        for (auto& word : words)
        {           
            bool isValid = true;
            string prefix;
            for (int i = 0; i < word.length() - 1 && isValid; i++)
            {
                prefix.push_back(word[i]);
                if (st.count(prefix) == 0)  /* 如果一直有效, 其子串应该一直在set中 */
                    isValid = false;                
            }
            if (isValid)
                return word;  /* 找到的第一个合法的解即为所求 */          
        }
        
        return "";
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