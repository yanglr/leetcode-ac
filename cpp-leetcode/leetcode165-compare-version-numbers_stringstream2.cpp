#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        for(auto& ch : v1)
            if (ch == '.') ch = ' ';
        for(auto& ch : v2)
            if (ch == '.') ch = ' ';
        
        istringstream s1(v1), s2(v2);
        while (true)
        {
            int n1, n2;
            if (!(s1 >> n1)) n1 = 0;
            if (!(s2 >> n2)) n2 = 0;
            if (!s1 && !s2) return 0;
            if (n1 < n2) return -1;
            if (n1 > n2) return 1;
        }
    }
};

// Test
int main()
{
    Solution sol;
    string version1 = "7.5.2.4", version2 = "7.5.3";
    auto res = sol.compareVersion(version1, version2);
    cout << res << endl;
    
    return 0;
}