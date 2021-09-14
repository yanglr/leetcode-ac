#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                for (int k = 1; k < 4; k++)
                {
                    for (int m = 1; m < 4; m++)
                    {
                        if (i + j + k + m != s.size())
                            continue;
                        int a = stoi(s.substr(0, i));
                        int b = stoi(s.substr(i, j));
                        int c = stoi(s.substr(i + j, k));

                        int d = stoi(s.substr(i + j + k));
                        if (a <= 255 && b <= 255 && c <= 255 && d <= 255)
                        {
                            string buffer = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
                            /* 处理先导0, 比如 "0.0.0.0"是合法的, 而"0.01.0.0"不是, 下面的+3是表示3个点. */
                            if (buffer.size() == s.size() + 3)
                            {
                                res.push_back(buffer);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string S = "25525511135";
    vector<string> res = sol.restoreIpAddresses(S);

    for (string str : res)
        cout << str << endl;
    
    return 0;
}