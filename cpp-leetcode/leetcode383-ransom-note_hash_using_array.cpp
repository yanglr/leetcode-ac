#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq1[128]; // 题意: 字符串ransomNote和magazine均只含小写字母
        fill(freq1, freq1 + 128, 0);
        int freq2[128];
        fill(freq2, freq2 + 128, 0);        
        for (auto& ch : ransomNote)
            freq1[ch]++;
        for (auto& ch : magazine)
            freq2[ch]++;
        for (int i = 0; i < ransomNote.size(); i++)
        {
            char ch = ransomNote[i];
            if (freq1[ch] > freq2[ch]) return false;
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