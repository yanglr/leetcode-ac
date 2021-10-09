#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class SummaryRanges {
private:
    vector<vector<int>> vec;    
public:
    void addNum(int val) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        vector<int> newRange = {val, val};
        auto it = lower_bound(vec.begin(), vec.end(), newRange, cmp);
        int start = val, end = val;
        if (it != vec.begin() && (*(it - 1))[1] + 1 >= val) // *(it - 1) 是迭代器指针it前一个区间
            it--;
        while (it != vec.end() && val + 1 >= (*it)[0] && val - 1 <= (*it)[1])
        {
            start = min(start, (*it)[0]);  // *(it) 是当前迭代器指针it指向的区间
            end = max(end, (*it)[1]);
            it = vec.erase(it);
        }
        vec.insert(it, {start, end});
    }

    vector<vector<int>> getIntervals() {
        return vec;
    }
};

void print2dVec(vector<vector<int>> res)
{
    for (auto& row : res) // 遍历每一行
    {
        for (auto& elem : row) // 输出每一个元素
            cout << elem << " ";  
        cout << "\n";
    }   
    cout << "----------------\n";    
}

int main()
{
    // vector<int> nums = {0, 2, 3, 4, 6, 8, 9};    
    SummaryRanges* sr = new SummaryRanges();
    // sr->addNum(val);
    vector<vector<int>> ranges = sr->getIntervals();
    print2dVec(ranges);

    sr->addNum(1);                  // arr = {1}
    print2dVec(sr->getIntervals()); //  返回 {{1, 1}}
    sr->addNum(3);                  // arr = {1, 3}
    print2dVec(sr->getIntervals()); //  返回 {{1, 1}, {3, 3}}
    sr->addNum(7);                  // arr = {1, 3, 7}
    print2dVec(sr->getIntervals()); //  返回 {{1, 1}, {3, 3}, {7, 7}}
    sr->addNum(2);                  // arr = {1, 2, 3, 7}
    print2dVec(sr->getIntervals()); //  返回 {{1, 3}, {7, 7}}
    sr->addNum(6);                  // arr = {1, 2, 3, 6, 7}
    print2dVec(sr->getIntervals()); //  返回 {{1, 3}, {6, 7}}
    
    return 0;
}