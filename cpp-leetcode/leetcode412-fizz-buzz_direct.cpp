#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            if ((i % 3 == 0) && (i % 5 == 0)) res.push_back("FizzBuzz");
            else if (i % 3 == 0) res.push_back("Fizz");
            else if (i % 5 == 0) res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 15;
    auto res = sol.fizzBuzz(n);
    for (auto &str : res)
        cout << str << endl;    
    
    return 0;
}