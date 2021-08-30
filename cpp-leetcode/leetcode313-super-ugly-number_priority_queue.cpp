#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

typedef pair<int, int> PII;  /* kvp: value -> index */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        int k = primes.size();
        vector<int>p(k, 0);       /* p数组放有每个质数 2, 3, 5...等的指针, 一开始都是0 */
        vector<int>results({1});
        priority_queue<PII, vector<PII>, greater<>>q; /* 小顶堆 */        

        /* 初始化堆, 把1与primes中元素相乘的结果都放进去 */                
        for (int i=0; i<primes.size(); i++)
            q.push({primes[i] * results[0], i});

        for (int c = 0; c < n-1; c++)
        {     
            int curMin = q.top().first;
            results.push_back(curMin);

            while (!q.empty() && q.top().first == curMin)                
            {
                int i = q.top().second;
                q.pop();

                p[i]++;                
                q.push({primes[i] * results[p[i]], i});
            }             
        }
        
        return results.back();
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