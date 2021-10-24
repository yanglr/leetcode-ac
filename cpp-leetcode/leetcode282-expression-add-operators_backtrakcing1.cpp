#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> addOperators(string num, int target) { /* target: 目标和 */
    /*
        Follow up:
        如果加一种运算符/(除号)怎么办?
        如果加入括号怎么办?
        先转为逆波兰表达式, 再想办法解决
    */
        backtrack(num, target, "", 0, /*curEval (long) */ 0, /*prev*/ 0);
        return res;
    }
    void backtrack(string& numStr, int target, string curExp, int startPos, long curEval, long prev) /* prev: pre eval, 即cur Eval撤销最近一次+-*运算的结果 */
    {        
        if (startPos == numStr.size()) // 全部字符处理完了
        {
            if (curEval == target)
            {
                res.push_back(curExp);
            }
            return;
        }
        for (int i = startPos; i < numStr.size(); i++)
        {         
            if (numStr[startPos] == '0' && i > startPos) // 拆分出来的数有先导0: 0674 367482
                                                // |    |
                                                //  0 + 2
                break;
            long curNum = stol(numStr.substr(startPos, i - startPos + 1)); // 当前在处理的子字符串: [startPos, i]
            if (startPos == 0) /* 拆分出来的第1个数不参与运算 */
            {
                backtrack(numStr, target, curExp + to_string(curNum), i + 1, curNum, curNum);
            }
            else
            {
                backtrack(numStr, target, curExp + "+" + to_string(curNum), i + 1, curEval + curNum, curNum);   // 在curNum之前插入1个+, 运算+curNum给整体表达式的sum贡献了+curSum = curSum, curEval更新为curEval + curNum
                backtrack(numStr, target, curExp + "-" + to_string(curNum), i + 1, curEval - curNum, -curNum);  // 在curNum之前插入1个-, 运算-curNum给整体表达式的sum贡献了-curSum

                backtrack(numStr, target, curExp + "*" + to_string(curNum), i + 1, curEval - prev + curNum * prev, curNum * prev); // 在curNum之前插入1个*, 运算*curNum给整体表达式的sum贡献了+prev*curSum, 由于需要先恢复 □ ± 3 * 2 中的 □ 值(□ ± 3 = curEval), 故curEval更新为□ ± 3 * 2 = curEval - prev + prev * curNum, prev在多次函数调用过程中依次为3,6(只记录做乘法运算的话)
            }
        }
    }
};

// Test
int main()
{
    Solution sol;
    string num = "1325";
    int targetNum = 31;
    auto res = sol.addOperators(num, targetNum);
    for (auto& str : res)
        cout << str << endl;

    return 0;
}