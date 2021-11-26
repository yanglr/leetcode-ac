#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, string> dict; // shortUrl -> long url
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string randomStr(int k) // % 62
    {
        string str = "";
        while (k > 0)
        {
            str += chars[rand() % 62];
            k--;
        }
        return str;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (true)
        {
            string shortUrl = randomStr(6);
            if (dict.count(shortUrl) == 0)
            {
                dict[shortUrl] = longUrl;
                return "http://tinyurl.com/" + shortUrl;
            }
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dict[shortUrl.substr(19)];
    }
};

// Test
int main()
{
    Solution sol;
    string longUrl = "https://leetcode.com/problems/design-tinyurl";
    string shortUrl = sol.encode(longUrl);
    cout << shortUrl << endl;
    auto res = sol.decode(shortUrl);
    cout << res << endl;

    return 0;
}