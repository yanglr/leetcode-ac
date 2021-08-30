#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = "";
        vector<string> weighPosfix = {"", "Thousand", "Million", "Billion"};
        vector<pair<string, string>> kvVect; 
        auto str = to_string(num);
        int len = str.size();   
        for (int i = len - 1; i >= 0; i -= 3)  
        {
            if (i >= 2)
                kvVect.push_back(make_pair(str.substr(i - 2, 3), weighPosfix[(len - i) / 3]));
            else kvVect.push_back(make_pair(str.substr(0, i + 1), weighPosfix[(len - i) / 3]));
        }
        reverse(kvVect.begin(), kvVect.end());

        for (int i = 0; i < kvVect.size(); i++)
        {
            if (i != kvVect.size() - 1)
                res += (ThreeDigitsNumToString(kvVect[i].first) == "" ?  "" : 
                 (ThreeDigitsNumToString(kvVect[i].first) + " " + kvVect[i].second)) + " ";
            else res += (ThreeDigitsNumToString(kvVect[i].first) == "" ?  "" : 
                 (ThreeDigitsNumToString(kvVect[i].first) + " " + kvVect[i].second));
        }
        res.erase(res.find_last_not_of(' ')+1);
        
        res = replaceAll(res, "  ", " ");   // 将连续的多个空格替换成1个   
        return res;
    }

    string ThreeDigitsNumToString(string str)
    {
        string res;
        vector<string> tenTo19Prefix = {"Thir", "Four", "Fif", "Six", "Seven", "Eigh", "Nine"};
        vector<string> twentyTo90Prefix = {"Twen", "Thir", "For", "Fif", "Six", "Seven", "Eigh", "Nine"};  /* 这里是"For", 而不是"Four" */

        string validStr = "";
        unordered_map<int, string> dict = {
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, 
            {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"} };

        for (int i = 13; i <= 19; i++)
        {
            if (dict.find(i) == dict.end())
            {
                dict[i] = "teen";
            }
        }
        for (int i = 13; i <= 19; i++)
        {
            dict[i] = tenTo19Prefix[i % 13] + dict[i];
        }
        for (int i = 20; i <= 90; i += 10)
        {            
            if (dict.find(i) == dict.end())
            {
                dict[i] = "ty";
            }
        }
        for (int i = 20; i <= 90; i += 10)
        {            
            dict[i] = twentyTo90Prefix[i / 10 - 2] + dict[i];
        }
        int len = str.size();

        // 去掉先导0
        int validNum = stoi(str);
        if (validNum == 0) return "";

        if (validNum > 0 && validNum < 100)
        {
            res = LastTwoDigitsToString(validNum, dict);
        }
        if (validNum >= 100)
        {
            res.append(dict[str[0] - '0']);
            res = res.append(" Hundred");
            if (validNum > 100 && validNum % 100 != 0)
                res.append(" ").append(LastTwoDigitsToString(validNum % 100, dict));                             
        }

        return res;
    }

    string LastTwoDigitsToString(int num, unordered_map<int, string> dict)
    {
        string res = "";
        if (num > 0 && num <= 19 || (num % 10 == 0))
        {             
            res.append(dict[num]);
        }
        else if (num % 10 != 0 && num < 100)
        {
            int rem = num % 10;
            string prefix;
            if (num - rem == 40) prefix = "Forty";       // 这两个是特殊情况
            else if (num - rem == 90) prefix = "Ninety"; 
            else prefix = dict[num - rem];
            
            res.append(prefix).append(" ").append(dict[rem]);
        }
        return res;        
    }
    
    string replaceAll(string str, const string& sub_str, const string& new_str) {
        string resultStr = str;
        int pos = 0;
        while((pos = resultStr.find(sub_str)) != string::npos)   // 替换所有指定子串
        {
            resultStr.replace(pos, sub_str.length(), new_str);
        }
        return resultStr;
    }       
};

// Test
int main()
{
    Solution sol;
    int num = 1000000001;
    auto res = sol.numberToWords(num);    /* Expected: "One Billion One" */
    cout << res << endl;
    
    return 0;
}