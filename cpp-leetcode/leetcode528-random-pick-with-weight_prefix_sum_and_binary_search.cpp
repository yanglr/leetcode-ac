#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> preSum; 
public:
    Solution(vector<int>& w) {
        const int len = w.size();
        preSum.resize(len);
        preSum[0] = w[0];
        for (int i = 1; i < len; i++)
            preSum[i] = preSum[i - 1] + w[i]; // 计算前缀和        
    }

    int pickIndex() {
        int sum = preSum.back();        
        int randPos = rand() % sum + 1; /* 产生1到sum之间的随机数 */
        return lower_bound(preSum.begin(), preSum.end(), randPos) - preSum.begin();
    }
};

// Test
int main()
{
    vector<int> w = {1, 3};
    Solution* sol = new Solution(w);
    int num1 = sol->pickIndex();
    cout << num1 << endl;
    int num2 = sol->pickIndex();
    cout << num2 << endl;
    int num3 = sol->pickIndex();
    cout << num3 << endl;
    int num4 = sol->pickIndex();
    cout << num4 << endl;            

    return 0;
}