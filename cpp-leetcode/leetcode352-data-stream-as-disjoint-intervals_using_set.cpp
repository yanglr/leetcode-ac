#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

class SummaryRanges {
private:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) const
        {
            return a[0] < b[0];
        }
    };
    set<vector<int>, cmp> st; 
public:    
    SummaryRanges() {
    }    
    void addNum(int val) {
        auto it = st.lower_bound({val, val});
        int start = val, end = val;
        if (it != st.begin() && (*(prev(it)))[1] + 1 >= start) it--;
        while (it != st.end() && end + 1 >= (*it)[0])
        {
            start = min(start, (*it)[0]);
            end = max(end, (*it)[1]);
            it = st.erase(it);
        }
        st.insert(it, {start, end});
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (const auto& val : st) res.push_back(val);
        return res;
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