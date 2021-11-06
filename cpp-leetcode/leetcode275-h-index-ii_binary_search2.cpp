#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, N = citations.size(); 
        int right = N-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (citations[mid] >= (N-mid)) right = mid - 1;
            else left = mid + 1;
        }
        return N - left;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> C = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = sol.hIndex(C);
    cout << res << endl;
    
    return 0;
}