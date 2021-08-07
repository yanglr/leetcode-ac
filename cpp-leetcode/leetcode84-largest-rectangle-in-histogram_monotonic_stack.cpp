#include<algorithm>
#include<deque>
#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        
        int res = 0;
        vector<int> tempArr(heights);
        tempArr.insert(tempArr.begin(), 0);
        tempArr.push_back(0); 

        deque<int> st;
        for (int i = 0; i < tempArr.size(); i++)
        {
            while (!st.empty() && tempArr[st.back()] > tempArr[i])
            {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                res = max(res, (right - left + 1) * tempArr[cur]);
            }
            st.push_back(i);  // push索引
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> heights= {2,1,5,6,2,3};
    auto res = sol.largestRectangleArea(heights);
    cout << res << endl;

    return 0;
}