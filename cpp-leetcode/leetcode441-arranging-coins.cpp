#include<algorithm>
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

typedef long long LL;
class Solution {
public:
    int arrangeCoins(int n) {
        LL i = 0;
        while ((LL)(i*(i+1)) < (LL)2*n)
            i++;
        if ((LL)(i*(i+1)) == (LL)2*n) return i;   
        return i - 1;
    }
};

// Test
int main()
{
	Solution sol;
    int num = 10;
	auto res = sol.arrangeCoins(num);
    cout << res << endl;

	return 0;
}