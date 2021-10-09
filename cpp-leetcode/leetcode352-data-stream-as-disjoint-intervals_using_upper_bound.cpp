#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class SummaryRanges {
private:
    vector<vector<int>> _ranges;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    void addNum(int val) {
        vector<int> newRange = vector<int>(2, val);
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        auto it = upper_bound(_ranges.begin(), _ranges.end(), newRange, cmp); /* 寻找要插入的位置 */
        if (it == _ranges.begin())
        {
            if (it != _ranges.end() && (*it)[0] == val + 1)
                (*it)[0] = val;
            else
                _ranges.insert(it, newRange);
        }
        else
        {
            int curPos = it - _ranges.begin();
            int prePos = curPos - 1;
            if (val > _ranges[prePos][1])
            {
                if (val == _ranges[prePos][1] + 1)
                {
                    newRange[0] = _ranges[prePos][0];
                    _ranges.erase(_ranges.begin() + prePos);
                    curPos--;
                }
                if (curPos < _ranges.size() && val == _ranges[curPos][0] - 1)
                {
                    newRange[1] = _ranges[curPos][1];
                    _ranges.erase(_ranges.begin() + curPos);
                }
                _ranges.insert(_ranges.begin() + curPos, newRange);
            }
        }
    }
    vector<vector<int>> getIntervals() {
        return _ranges;
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