#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int k) {
        if (k == 0) return A;
        vector<int> res;
        int n = A.size();
        // 对位相加
        int carry = 0;
        int sum = 0;      
        int i = n - 1; 
        while (k > 0 || i >= 0)
        {
            sum = carry + (k % 10);
            if (i >= 0) // 保证访问A[i]前不越界
                sum += A[i];

            carry = (sum <= 9) ? 0 : 1;
            res.push_back(sum % 10);            
            k = k / 10;
            
            i--;
        }
        if (carry == 1) res.push_back(1);
        reverse(res.begin(), res.end());
        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> A = {2, 7, 4};
    int K = 81;

    auto res = sol.addToArrayForm(A, K);
    for (auto &num : res)
        cout << num << endl;  

    return 0;
}
