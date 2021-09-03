#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {        
        while(num > 9)
        {
            num = add(num);
        }

        return num;
    }

    int add(int num)
    {
        string str = to_string(num);
        int sum = 0;
        for(char ch : str)
        {
            sum += ch - '0';
        }
        return sum;        
    }
};

// Test
int main()
{
    Solution sol;
    int n = 222222222;
    auto res = sol.addDigits(n);
    cout << res << endl;

    return 0;
}