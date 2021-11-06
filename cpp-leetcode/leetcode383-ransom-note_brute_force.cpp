#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char& ch : ransomNote)
        {
            auto it = find(magazine.begin(), magazine.end(), ch);
            if (it != magazine.end())
            {
                magazine.erase(it);
            }
            else return false;
        }
        return true;
    }
};

// Test
int main()
{
    Solution sol;
    string ransomNote = "aa", magazine = "ab";
    auto res = sol.canConstruct(ransomNote, magazine);
    cout << (res == true ? "True" : "False") << " ";

    return 0;
}