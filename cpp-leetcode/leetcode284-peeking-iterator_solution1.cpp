#include<vector>
#include<algorithm>
#include<iostream>
#include<assert.h>
using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
    int _nextValue = 0;
    bool _hasNext = false;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        _hasNext = Iterator::hasNext();
        if (_hasNext)
            _nextValue = Iterator::next();
    }

    int peek() {
        return _nextValue;
    }

    int next() {
        int nextValue = _nextValue;
        _hasNext = Iterator::hasNext();
        if (_hasNext)
            _nextValue = Iterator::next();
        return nextValue;
    }

    bool hasNext() const {
        return _hasNext;
    }
};

// Test
/* 本题如果用C++实现没办法本地debug, 因为其中的 Iterator类没实现 */
int main()
{
    // const vector<int> nums = {1, 2, 3};
    // PeekingIterator* it = new PeekingIterator(nums); // [1,2,3]      
    // int val = it->next(); // 返回 1, 指针移动到下一个元素 [1,2,3]
    // cout << val << endl;
    // it->peek();       // 返回 2, 指针未发生移动 [1,2,3]
    // it->next();       // 返回 2, 指针移动到下一个元素 [1,2,3]
    // it->next();       // 返回 3, 指针移动到下一个元素 [1,2,3]
    // bool hasNext = it->hasNext(); // 返回 False
    // cout << (hasNext ? "True" : "False") << endl;

    return 0;
}