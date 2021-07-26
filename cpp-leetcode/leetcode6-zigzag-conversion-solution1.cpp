#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        // base case
        if (s.empty() || numRows <= 1)
            return s;

        // handle first row
        for (int i = 0; i < s.size(); i += (numRows - 1) * 2)
            res.push_back(s[i]);

        // handle middle rows
        for (int j = 1; j < numRows - 1; j++)
        {
            bool down = true;
            for (int i = j; i < s.size();)  // Since the step has two possible values, so not add increase logic here.
            {
                res.push_back(s[i]); // Add first element of current row, then add others
                if (down) // going down
                    i += (numRows - 1 - j) * 2;
                else // going up
                    i += 2*j;

                down = !down; // switch direction
            }
        }

        // handle last row
        for (int i = numRows - 1; i < s.size(); i += (numRows - 1) * 2)
            res.push_back(s[i]);

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 4;
    auto res = sol.convert(s, numRows);
    cout << res << endl;
    
    return 0;
}