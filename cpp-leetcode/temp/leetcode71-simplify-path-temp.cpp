#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

/* 49 / 256 test cases passed. */

class Solution {
public:
    string simplifyPath(string path) {
        // 1.遇到//, 替换为/
        path = replaceAll(path, "//", "/");

        // 2.遇到 /.. (看是否能朝着根目录/的方向靠近)
        // 向前找最近的一个/, 如果能找到, 把 / 与 /..之间的内容删掉
        while (path.find("/..") != string::npos && path.find("/..") != -1 && path.size() > 3) 
        {
            int pos = path.find("/..");
            string part2 = path.substr(pos + 3, path.size() - pos - 3);
            auto preIt = find(path.begin(), path.begin() + pos, '/');
            if (preIt != path.end())
            {
                string part1 = path.substr(0, preIt - path.begin());
                path = part1.append(part2);
            }            
        }      
        
        // 3.遇到 /. 直接删掉
        path = replaceAll(path, "/.", "");
        // 4.删除末尾的/, 迭代地删除
        if (path != "/") path.erase(path.find_last_not_of('/') + 1);       
        return path;
    }
    string replaceAll(std::string str, const std::string& from, const std::string& to) {
        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
        return str;
    }    
};

// Test
int main()
{
    Solution sol;
    string path = "/a/./b/../../c/";
    auto res = sol.simplifyPath(path);
    cout << res << endl;

    return 0;
}