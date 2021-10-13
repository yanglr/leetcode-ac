#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string res = "";
        sort(A.begin(), A.end());
        do
        {
            if ((A[0] == 2 && A[1] <= 3 || A[0] < 2) && A[2] <= 5)
            {
                string curTime = to_string(A[0]) + to_string(A[1]) + ":"
                    + to_string(A[2])+to_string(A[3]);
                if (curTime > res) res = curTime;
            }       
        } while (next_permutation(A.begin(), A.end()));
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 6, 6};
    auto res = sol.largestTimeFromDigits(nums);
    cout << res << endl;

    return 0;
}