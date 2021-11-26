#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& A) {
        const int N = A.size();
        if (N <= 3) return false;
        for (int i = 3; i < N; i++)
        {
            // case1: 4步之内有交点
            if (A[i-1] <= A[i-3] && A[i] >= A[i-2])
                return true;
            // case 2: 5步之内有交点
            if (i >= 4 && A[i-3] == A[i-1] && A[i] + A[i-4] >= A[i-2])
                return true;
            // case 3: 6步之内有交点
            if (i >= 5 && A[i-3] >= A[i-1] && A[i-1] + A[i-5] >= A[i-3] && A[i-2] >= A[i-4] && A[i-4] + A[i] >= A[i-2])
                return true;            
        }
        return false;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2,1,1,2};
    auto res = sol.isSelfCrossing(nums);
    cout << (res ? "True" : "False") << endl;

    return 0;
}