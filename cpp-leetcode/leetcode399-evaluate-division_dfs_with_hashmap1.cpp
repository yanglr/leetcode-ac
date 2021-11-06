#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

class Solution {
    unordered_map<string, vector<pair<string, double>>> dict; //存储相关数据    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); i++)
        {
            auto eq = equations[i];
            dict[eq[0]].push_back({eq[1], values[i]});       // 放入所有的A/B
            dict[eq[1]].push_back({eq[0], 1.0 / values[i]}); // 放入所有的B/A
        }
        for (int i = 0; i < queries.size(); i++) //遍历所有的query
        {
            auto eq = queries[i];
            if (dict.find(eq[0]) == dict.end() || dict.find(eq[1]) == dict.end())
            {
                res.push_back(-1.0); // 提前处理: A不在哈希表中
                continue;                
            }
            else if (eq[0] == eq[1])
            {
                res.push_back(1.0);  // 提前处理: A=B
                continue;                
            }
            unordered_set<string> visited;
            double temp = dfs(eq[0], eq[1], visited); //剩下的都扔给dfs
            res.push_back(temp);
        }
        return res;
    }
    double dfs(string A, string B, unordered_set<string>& visited)
    {
        if (A == B) return 1.0;
        visited.insert(A);
        double temp = -1.0;
        for (auto& kvp : dict[A]) //遍历A所能通向的所有位置
        {
            string med = kvp.first; // 选取一个位置叫media
            if (visited.find(med) != visited.end())
                continue;                          //如果这个位置已经访问过了，就不要再考虑
            double temp2 = dfs(med, B, visited); //剩下的就交给dfs去算从med到B的距离。
            if (temp2 != -1.0)
            {
                temp = kvp.second * temp2; //只要从med到B可行的话，就算找到从A到B的解了(因为题目保证没有其他med能造成冲突)
                break;
            }
        }
        return temp;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values = {1.5, 2.5, 5.0};
    vector<vector<string>> queries = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    auto res = sol.calcEquation(equations, values, queries);
    for (auto& num : res)
    cout << num << "";
    
    return 0;
}
