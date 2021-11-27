#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    int r, c, k; // r: 矩阵的行数, c: 列数, k: 矩阵中元素的个数
    unordered_map<int, int> dict; // 大脑中构建一个映射: x -> x, 默认用这个映射, 将不满足这个映射的特殊键值对存入哈希表
public:
    Solution(int m, int n) {
        r = m;
        c = n;
        k = r*c;
    }
    
    vector<int> flip() { /* 先把矩阵(二维数组)拉平成1维数组, 再进行随机处理 */
        int key = rand() % k;
        int val = key; // 默认的映射规则: x -> x (x的范围是: 0 -> k-1)
        if (dict.count(key))
            val = dict[key];
        if (dict.count(k - 1)) // 当key处的kvp用过后, 用最后一个kvp(key = k-1)覆盖之, 然后删掉最后一个kvp, 就可以在剩下的数中实现随机化选择
        {
            dict[key] = dict[k-1];
            dict.erase(k - 1);
        }
        else
            dict[key] = k - 1;
        k--; // 表示删掉了末尾的一个数
        int newRow = val / c;
        int newCol = val % c;
        return {newRow, newCol};
    }
    
    void reset() {
        k = r*c;
        dict.clear();
    }
};

// Test
int main()
{
    int m = 3;
    int n = 1;
    Solution* sol = new Solution(m, n);
    vector<int> res = sol->flip();
    cout << "{" << res[0] << ", " << res[1] << "}" << endl;
    res = sol->flip();
    cout << "{" << res[0] << ", " << res[1] << "}" << endl;
    res = sol->flip();
    cout << "{" << res[0] << ", " << res[1] << "}" << endl;
    sol->reset();
    res = sol->flip();
    cout << "{" << res[0] << ", " << res[1] << "}" << endl;

    cout << "OK~" << endl;
    
    return 0;
}