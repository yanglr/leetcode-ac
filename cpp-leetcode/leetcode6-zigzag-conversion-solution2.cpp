#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string res(s.size(), ' ');
        if (s.empty() || numRows <= 1)
            return s;

        int pos = 0;
        for (int i = 0; i < numRows; i++)
        {
            int gap1 = 2 * (numRows - 1 - i);
            int gap2 = 2 * i;

            int index = i;
            while (pos < s.size())
            {
                if (gap1 > 0)
                {
                    if (index >= s.size())
                        break;
                    res[pos++] = s[index]; // Add char row by row
                    index += gap1;
                }

                if (gap2 > 0)
                {
                    if (index >= s.size())
                        break;
                    res[pos++] = s[index];
                    index += gap2;
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
    string s = "PAYPALISHIRING";
    int numRows = 4;
    auto res = sol.convert(s, numRows);
    cout << res << endl;

    return 0;
}