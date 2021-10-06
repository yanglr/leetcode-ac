#include<vector>
#include<algorithm>
#include<iostream>
#include<assert.h>
using namespace std;

template <class T>
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<T>& nums);
    Iterator(const Iterator& iter);
    // Returns the next element in the iteration.
    T next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

template <class T>
class PeekingIterator : public Iterator<T> {
public:
    PeekingIterator(const vector<T>& nums) : Iterator<T>(nums) {
        flag = Iterator<T>::hasNext();
        if (flag) {
            nextElement = Iterator<T>::next();
        }
    }
    
    T peek() {
        return nextElement;
    }

    T next() {
        T ret = nextElement;
        flag = Iterator<T>::hasNext();
        if (flag) {
            nextElement = Iterator<T>::next();
        }
        return ret;
    }
    
    bool hasNext() const {
        return flag;
    }
private:
    T nextElement;
    bool flag;
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