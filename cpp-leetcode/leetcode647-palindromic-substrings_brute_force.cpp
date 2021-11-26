#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++)
            {
                int curLen = j - i + 1;
                if (isValidPar(s.substr(i, curLen)))
                    count++;
            }
        }
        return count;
    }
    bool isValidPar(string str)
    {
        string temp(str);
        reverse(str.begin(), str.end());
        return temp == str;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "abc";
    auto res = sol.countSubstrings(s);
    cout << res << endl;

    return 0;
}