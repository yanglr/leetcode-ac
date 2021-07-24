// #include <string>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// #include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> dict;  /* 哈希表: key是排序后的的各个单词，value是该key对应的全部异位词 */
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());       /* 对当前扫描到的字符串按字典序有小到大排序, 排序后的结果可以作为key插入哈希表 */

            if (dict.find(str) == dict.end())   /* 如果当前的key在哈希表中还不存在，就加进来 */
            {
                vector<string> item;
                dict[str] = item;
            }
            dict[str].push_back(strs[i]);      /* 如果当前的key在哈希表中已存在, 往其中加入其他字符串即可 */
        }

        for (auto kvpIt : dict)                /* 把哈希表中的value遍历出来, 放入二维动态数组的结果中 */
        {
            result.push_back(kvpIt.second);
        }

        return result;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = sol.groupAnagrams(strs);  /* 加断点到当前行的下一行, debug时可以看到结果 */

    return 0;
}