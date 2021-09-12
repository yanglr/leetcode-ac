#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s)
    {
        vector<int> st;
        int stars = 0;
        for (char ch : s)
        {
            if (ch == '(' || ch == '*')
            {
                st.push_back(ch);
                if (ch == '*') stars++;
            }
            else // ch == ')'
            {
                if (st.empty()) return false;
                bool seenLeft = false;   // 策略: 尽可能拿左括号去与当前的字符ch(右括号)做匹配, 因为后期*可以代表空串, 也可代表右括号, 所以*的作用是很大的, 我们这里先尽量使用左括号。bool值seenLeft记录从后向扫描字符串s时是否出现了左括号 */
                int size = st.size();
                for (int i = size - 1; i >= 0; i--)  /* 从后向前扫描字符串s, 试着找与当前的字符ch(右括号)匹配的左括号( */
                {
                    if (st[i] == '(')  /* 从后向前扫描字符串s, 试着找左括号(, 出现1个左括号说明能匹配上, 将其删掉后break */
                    {
                        seenLeft = true;
                        st.erase(st.begin() + i);
                        break;
                    }
                }
                if (!seenLeft)  /* 如果字符串s中不存在左括号(全是*), 就使用一个潜在的左括号*充当左括号, 依然能匹配上, 用完后将其删掉 */
                {
                    st.pop_back();
                    stars--;
                }
            }
        }
        
        int size = st.size();
        stars = 0;
        for (int i = size - 1; i >= 0; i--) // 再一次从后向扫描字符串s, 这次遍历的目标的判断左括号
        {
            if (st[i] == '(') /* 合法情况是: 左括号数量>=右括号数量, 否则非法 */
            {
                if (stars <= 0) // 当前字符是左括号(, 急需一个*充当右括号)与之匹配一下, 不够匹配就返回false
                    return false;
                stars--;    // 能匹配上, 就抵消掉一个*
            }
            else // st[i] == '*', *不影响结果
                stars++;
        }
        return true;
    }
};

//Test
int main()
{
    Solution sol;
    string str = "(*))";
    bool res = sol.checkValidString(str);
    cout << (res == true ? "true" : "false") << endl;

    return 0;
}