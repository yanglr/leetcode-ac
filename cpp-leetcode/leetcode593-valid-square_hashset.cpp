#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> set = 
        {
            getLenSquare(p1, p2),
            getLenSquare(p1, p3),
            getLenSquare(p1, p4),
            getLenSquare(p2, p3),
            getLenSquare(p2, p4),
            getLenSquare(p3, p4)
        };

        if (set.find(0) == set.end() && set.size() == 2)  // 所有邻边+对角线中，菱形有3种长度, 平行四边形(含长方形)有4种长度, 其他四边形有6种长度 
        {
            return true;
        }

        return false;
    }
    int getLenSquare(vector<int> point1, vector<int> point2) {
       return (point2[0] - point1[0]) * (point2[0] - point1[0]) + (point2[1] - point1[1]) * (point2[1] - point1[1]);
    }    
};

// Test
int main()
{
    Solution sol;
    vector<int> p1 = {0, 0}, p2 = {1, 1}, p3 = {1, 0}, p4 = {0, 1};
    auto res = sol.validSquare(p1, p2, p3, p4);

    cout << (res == true ? "true" : "false") << endl;

    return 0;
}