#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        set<long> st = {1};      /* 1是必须有的, 1是质因数的总数量为0时的特例 */
        int count = 0;
        long firstNum;
        while (count < n)
        {
            auto it = st.begin();
            firstNum = *it;
            st.erase(it);

            for (int i = 0; i < k; i++)
            {
                if (firstNum * primes[i] < INT_MAX)
                    st.insert(firstNum * primes[i]);
                else break;  /* 别漏了 */
            }
            count++;
        }
        return firstNum;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 12;
    vector<int> primes = {2, 7, 13, 19};
    auto res = sol.nthSuperUglyNumber(n, primes);
    cout << res << endl;
    
    return 0;
}